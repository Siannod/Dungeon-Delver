#pragma once
#include "display.h"

void Display::clear()
{
	system("cls");
}

void Display::wait()
{
	_getch();
}

void Display::main_menu()
{
	do
	{
		clear();
		std::cout << menu_top << std::endl;
		std::cout << "| 1. Move	 2. Inventory |" << std::endl;
		std::cout << "| 3. Spells	 4. Stats     |" << std::endl;
		std::cout << menu_top << std::endl;
		std::cout << "- Select menu option: ";
		if (input_validation(1, 4, "- Select menu option: "))
		{
			if (choice_int == 1) { clear();  dungeon_move_options(); }
			else if (choice_int == 2) { clear(), print_inventory(); }
			else if (choice_int == 4) { clear(), player.print_stats(); wait(); }
		}
	} while (running);
}

void Display::dungeon_move_options()
{
	dungeon.print_dungeon();
	temp.clear();
	dungeon.check_paths({ player.stats.x, player.stats.y }, temp);
	for (int i = 0; i < temp.size(); i++)
	{
		std::cout << ">> " << i + 1 << ". " << dungeon.directions.at(temp[i]) << std::endl;
	}
	std::cout << ">> " << temp.size() + 1 << ". Back to main menu" << std::endl;
	std::cout << "- ";
	input_validation(1, temp.size() + 1, "- ");
	if (choice_int < temp.size() + 1)
	{
		x_mod = dungeon.direction.at(temp[choice_int - 1])[0];
		y_mod = dungeon.direction.at(temp[choice_int - 1])[1];

		player.move(x_mod, y_mod);
		std::cout << dungeon.dungeon[player.stats.x][player.stats.y] << std::endl;
		if (dungeon.dungeon[player.stats.x][player.stats.y] == "3") { monster_encounter(); }
		dungeon.move_player(player.stats.x, player.stats.y, x_mod, y_mod);
		std::cout << dungeon.dungeon[player.stats.x][player.stats.y];

		clear();
		dungeon_move_options();
	}
	else { clear(); main_menu(); }
}

bool Display::input_validation(int min, int max, std::string statement)
{
	while (!valid)
	{
		std::cin >> choice_string;
		try
		{
			choice_int = stoi(choice_string);
			if (min <= choice_int && choice_int <= max)
			{
				return true;
			}
			else
			{
				throw 505;
			}
		}
		catch (...)
		{
			std::cout << "[!] INVALID INPUT" << std::endl;
			std::cout << statement;
		}
	}
}

void Display::print_inventory(bool valid)
{
	std::cin.ignore();
	while (!player.inventory.go_back)
	{
		player.inventory.print();
		std::cout << ">> Type 'help' for more commands" << std::endl;
		std::cout << "- ";
		std::getline(std::cin, choice_string);
		player.inventory.command.delimit(choice_string);
		player.inventory.do_command();
		wait();
		clear();
	}
	main_menu();
}

void Display::monster_encounter(bool alive) 
{
	clear();
	combat.monster.create_monster(player.stats_ptr);
	do
	{
		clear();
		std::cout << ">> As you continue along your path, dark shadows masking the way forwards a monster looms out of the darkness" << std::endl;
		combat.print_field();
		combat_menu();
		//MOVE
		if (choice_int == 1)
		{
			if (combat.moves_left == 0)
			{
				clear();
				combat.print_field();
				std::cout << "[!] NO MORE MOVES LEFT THIS TURN";
				wait();
			}
			else
			{
				combat_move();
			}
		} 
		//SEE INVENTORY
		else if (choice_int == 2) { print_inventory(); } 
		else if (choice_int == 3) 
		{ 
			combat_fight(); 
			if (!combat.check_monster_alive())
			{
				clear();
				std::cout << ">> Congratulations! You defeated the monster, you gained " << combat.monster.coin_worth(player.stats.level) << std::endl;
				player.stats.coin += combat.monster.value;
			}
			wait(); 
		}
		//FLEE
		else if (choice_int == 4)
		{
			combat.flee(player.able_to_flee, player.stats.stats.at("Dexterity"));
		} 
		if (choice_int == 5 || (!combat.action_left && combat.moves_left == 0))
		{
			player.able_to_flee = true;
			combat.moves_left = 5;
			combat.action_left = true;
			combat.monster_turn();
			int_temp = combat.monster.route.top;
			print_monster_moves();
			monster_attack();
		}
	} while (alive);
}

void Display::combat_menu()
{
	std::cout << "+=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=+" << std::endl;
	std::cout << "| 1. Move    2. Items | Health: " << player.stats.health << " |" << std::endl;
	std::cout << "| 3. Fight   4. Flee  | Moves: " << combat.moves_left << "  |" << std::endl;
	std::cout << "| 5. End Turn         |           |" << std::endl;
	std::cout << "+=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=+" << std::endl;
	std::cout << "- ";
	input_validation(1, 5, "- ");
}

void Display::combat_move()
{
	clear();
	combat.print_field();
	combat.check_moves();
	for (int i = 0; i < combat.options.size(); i ++)
	{
		std::cout << ">> " << i+1 << ". " << dungeon.directions.at(combat.options[i]) << std::endl;
	}
	std::cout << ">> " << combat.options.size() + 1 << ". back" << std::endl;
	std::cout << "- ";
	input_validation(1, combat.options.size()+1, "- ");
	if (choice_int < combat.options.size() + 1)
	{
		combat.move_player(choice_int);
	}
	else
	{
		monster_encounter();
	}
}

void Display::combat_fight()
{
	if (combat.action_left)
	{
		clear();
		player.inventory.find_weapons();
		count = 1;
		if (player.inventory.weapon_index.size() != 0)
		{
			print_weapons();
			std::cout << "- ";
			input_validation(1, count, "- ");
			index = player.inventory.weapon_index[choice_int - 1];
			temp_item = player.inventory.inventory[index];
			if (combat.check_for_enemy(player.inventory.item_types.at(temp_item.item_type).range))
			{

				combat.monster.stats.health -= combat.calculate_damage(temp_item);
				combat.action_left = false;
				std::cout << ">> You dealt " << combat.damage << " damage the monster is now on " << combat.monster.stats.health << std::endl;
			}
			else
			{
				std::cout << "[!] NO ENEMIES IN RANGE, MOVE AND TRY AGAIN" << std::endl;
			}
		}
		else
		{
			std::cout << "[!] YOU HAVE NO WEAPONS YOU CAN ONLY FLEE" << std::endl;
		}
	}
	else
	{
		std::cout << "[!] YOU HAVE USED YOUR ATTACK FOR THIS TURN" << std::endl;
	}
}

void Display::print_weapons()
{
	for (int item : player.inventory.weapon_index)
	{
		temp_item = player.inventory.inventory[item];
		if (temp_item.item_type == 1 || temp_item.item_type == 2)
		{
			std::cout << ">> " << count << ". " << temp_item.name << std::endl;
		}
		count += 1;
	}
}

void Display::print_monster_moves()
{
	for (int i = 0; i < int_temp; i++)
	{
		combat.next_step = combat.monster.route.pop();
		combat.move_monster(combat.next_step.x, combat.next_step.y);
		Sleep(2000);
		clear();
		combat.print_field();
	}
}

void Display::monster_attack()
{
	if (combat.monster.player_in_range(combat.player.x, combat.player.y))
	{
		int damage = combat.monster.calculate_damage();
		if (player.inventory.find_item_of_type(3))
		{
			if (combat.monster.does_hit())
			{
				std::cout << ">> The Monster did " << damage << " damage." << std::endl;
				player.stats.health -= damage;
				wait();
			}
		}
		else
		{
			std::cout << ">> The Monster did " << damage << " damage." << std::endl;
			player.stats.health -= damage;
			wait();
		}
	}
}