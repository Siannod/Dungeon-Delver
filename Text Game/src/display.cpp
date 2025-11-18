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
	clear();
	std::cout << menu_top << std::endl;
	std::cout << "| 1. Move	 2. Inventory |" << std::endl;
	std::cout << "| 3. Spells	 4. Stats     |" << std::endl;
	std::cout << menu_top << std::endl;
	std::cout << "- Select menu option: ";
	if (input_validation(1, 4, "- Select menu option: ", false))
	{
		if (choice_int == 1) { clear();  dungeon_move_options(); }
		else if (choice_int == 2) { clear(), print_inventory(); }
		else if (choice_int == 4) { clear(), player.print_stats(); wait(); }
	}
}

void Display::dungeon_move_options()
{
	dungeon.print_dungeon();
	temp.clear();
	dungeon.check_paths({ player.player_x, player.player_y }, temp);
	for (int i = 0; i < temp.size(); i++)
	{
		std::cout << ">> " << i + 1 << ". " << dungeon.directions.at(temp[i]) << std::endl;
	}
	std::cout << ">> " << temp.size() + 1 << ". Back to main menu" << std::endl;
	std::cout << "- ";
	input_validation(1, temp.size() + 1, "- ", false);
	if (choice_int < temp.size() + 1)
	{
		x_mod = dungeon.direction.at(temp[choice_int - 1])[0];
		y_mod = dungeon.direction.at(temp[choice_int - 1])[1];

		player.move(x_mod, y_mod);
		std::cout << dungeon.dungeon[player.player_x][player.player_y] << std::endl;
		if (dungeon.dungeon[player.player_x][player.player_y] == "3") { monster_encounter(); }
		dungeon.move_player(player.player_x, player.player_y, x_mod, y_mod);
		std::cout << dungeon.dungeon[player.player_x][player.player_y];

		clear();
		dungeon_move_options();
	}
	else { clear(); main_menu(); }
}

bool Display::input_validation(int min, int max, std::string statement, bool valid)
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
	do
	{
		player.able_to_flee = true;
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
		else if (choice_int == 3 && combat.action_left) { combat_fight(); }
		//FLEE
		else if (choice_int == 4)
		{
			if(player.able_to_flee)
			{
				player.able_to_flee = false;
				if (combat.flee(player.stats.at("Dexterity")))
				{
					clear();
					std::cout << ">> You succesfully fled the monster" << std::endl;
					player.able_to_flee = true;
					wait();
					main_menu();
				}
				else
				{
					std::cout << ">> You were unsuccessful in fleeing the monster, you must stay and fight" << std::endl;
					wait();
				}
			}
			else
			{
				std::cout << ">> You cannot try to flee again this round, you must stay and fight" << std::endl;
				wait();
			}
		} 
		if (choice_int == 5 || (!combat.action_left && combat.moves_left == 0))
		{
			combat.monster_turn();
			combat.monster.route.print_stack();
			int_temp = combat.monster.route.top;
			for (int i = 0; i < int_temp; i++)
			{
				combat.next_step = combat.monster.route.pop();
				combat.move_monster(combat.next_step.x, combat.next_step.y);
				Sleep(2000);
				clear();
				combat.print_field();
				combat.monster.route.print_stack();
			}
		}
	} while (alive);
}

void Display::combat_menu()
{
	std::cout << "+=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=+" << std::endl;
	std::cout << "| 1. Move    2. Items | Health: " << player.health_current << " |" << std::endl;
	std::cout << "| 3. Fight   4. Flee  | Moves: " << combat.moves_left << "  |" << std::endl;
	std::cout << "| 5. End Turn         |           |" << std::endl;
	std::cout << "+=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=+" << std::endl;
	std::cout << "- ";
	input_validation(1, 5, "- ", false);
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
	input_validation(1, combat.options.size()+1, "- ", false);
	if (choice_int < combat.options.size() + 1)
	{
		combat.moves_left -= 1;
		combat.new_x = combat.player_x + combat.moves.at(combat.options[choice_int - 1])[0];
		combat.new_y = combat.player_y + combat.moves.at(combat.options[choice_int - 1])[1];
		combat.move_player();
	}
	else
	{
		monster_encounter();
	}
}

void Display::combat_fight()
{
	clear();
	player.inventory.find_weapons();
	count = 1;
	if (player.inventory.weapon_index.size() != 0)
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
		input_validation(1, count, "- ", false);
		index = player.inventory.weapon_index[choice_int];
		temp_item = player.inventory.inventory[index];
		if (combat.check_for_enemy(player.inventory.item_type.at(temp_item.item_type).range))
		{

			combat.action_left = false;
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