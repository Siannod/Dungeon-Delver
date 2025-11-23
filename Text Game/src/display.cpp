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

void Display::print_main_menu()
{
	clear();
	std::cout << menu_top << std::endl;
	std::cout << "| 1. Move	 2. Inventory |" << std::endl;
	std::cout << "| 3. Spells	 4. Stats     |" << std::endl;
	std::cout << menu_top << std::endl;
	std::cout << "- Select menu option: ";
}

void Display::main_menu()
{
	while(running)
	{
		print_main_menu();
		if (input_validation(1, 4, "- Select menu option: "))
		{
			if (choice_int == 1) { clear();  dungeon_move_options(); }
			else if (choice_int == 2) { clear(), inventory_menu(); }
			else if (choice_int == 4)
			{
				clear(); 
				player.print_stats_menu(); 
				wait();
				if (player.check_level_up())
				{
					clear();
					player.level_up();
					
				}
			}
		}
	}
}

void Display::print_dunegon_move_options()
{
	for (int i = 0; i < temp.size(); i++)
	{
		std::cout << ">> " << i + 1 << ". " << dungeon.directions.at(temp[i]) << std::endl;
	}
	std::cout << ">> " << temp.size() + 1 << ". Back to main menu" << std::endl;
	std::cout << "- ";
}

void Display::dungeon_move_options()
{
	dungeon.print_dungeon();
	temp.clear();
	dungeon.check_paths({ player.stats.x, player.stats.y }, temp);
	print_dunegon_move_options();
	input_validation(1, temp.size() + 1, "- ");
	if (choice_int < temp.size() + 1)
	{
		x_mod = dungeon.direction.at(temp[choice_int - 1])[0];
		y_mod = dungeon.direction.at(temp[choice_int - 1])[1];

		player.move(x_mod, y_mod);
		if (dungeon.dungeon[player.stats.x][player.stats.y] == "2") 
		{
			monster_encounter(1); 
		}
		else if (dungeon.dungeon[player.stats.x][player.stats.y] == "3") 
		{ 
			monster_encounter(0); 
		}
		else if (dungeon.dungeon[player.stats.x][player.stats.y] == "4") { loot_room(); }
		dungeon.move_player(player.stats.x, player.stats.y, x_mod, y_mod);
		if (running)
		{
			clear();
			dungeon_move_options();
		}
	}
	clear(); 
	main_menu();
}

bool Display::input_validation(int min, int max, std::string statement)
{
	valid = false;
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

void Display::print_inventory_menu()
{
	player.inventory.print();
	std::cout << ">> Coins: " << player.stats.coin << std::endl;
	std::cout << ">> Type 'help' for more commands" << std::endl;
}

void Display::inventory_menu(bool valid)
{
	std::cin.ignore();
	player.inventory.go_back = false;
	while (!player.inventory.go_back)
	{
		print_inventory_menu();
		std::cout << "- ";
		std::getline(std::cin, choice_string);
		player.inventory.command.delimit(choice_string);
		player.inventory.do_command(player.stats);
		wait();
		clear();
	}
	main_menu();
}

void Display::monster_encounter(int type) 
{
	bool alive = true;
	combat.type = type;
	clear();
	combat.monster_types[type]->create_monster(player.stats_ptr);
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
		else if (choice_int == 2) { inventory_menu(); } 
		else if (choice_int == 3) 
		{ 
			combat_fight(type); 
			if (!combat.check_monster_alive())
			{
				//clear();
				std::cout << ">> Congratulations! You defeated the monster, you gained " << combat.monster->coin_worth(player.stats.level) << " coins" << std::endl;
				player.stats.coin += combat.monster->value;
				player.stats.monsters_killed += 1;
				alive = false;
			}
			wait(); 
		}
		//FLEE
		else if (choice_int == 4)
		{
			combat.flee(player.able_to_flee, player.stats.stats.at("Dexterity"));
			wait();
		} 
		if (choice_int == 5 || (!combat.action_left && combat.moves_left == 0))
		{
			end_of_turn(type, alive);
		}
	} while (alive);
	if (type == 1)
	{
		new_level();
		player.stats.x = 1;
		player.stats.y = 1;
	}
}

void Display::end_of_turn(int type, bool &alive)
{
	player.able_to_flee = true;
	combat.moves_left = 5;
	combat.action_left = true;
	combat.monster_turn();
	int_temp = combat.monster_types[type]->route.top;
	print_monster_moves(type);
	monster_attack(type);
	if (!combat.check_player_alive(player.stats.health))
	{
		alive = false;
		running = false;
	}
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
	std::cin.clear();
	input_validation(1, combat.options.size()+1, "- ");
	if (choice_int < combat.options.size() + 1)
	{
		combat.move_player(choice_int);
	}
	
}

void Display::combat_fight(int type)
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
			clear();
			combat.action_left = false;
			if (combat.check_for_enemy(player.inventory.item_types.at(temp_item.item_type).range))
			{

				combat.monster_types[type]->stats.health -= combat.calculate_damage(temp_item);
				if (combat.check_monster_alive())
				{
					std::cout << ">> You dealt " << combat.damage << " damage the monster is now on " << combat.monster_types[type]->stats.health << " health" << std::endl;
				}
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

void Display::print_monster_moves(int type)
{
	for (int i = 0; i < int_temp; i++)
	{
		combat.next_step = combat.monster_types[type]->route.pop();
		combat.move_monster(combat.next_step.x, combat.next_step.y);
		Sleep(2000);
		clear();
		combat.print_field();
	}
}

void Display::monster_attack(int type)
{
	if (combat.monster_types[type]->player_in_range(combat.player.x, combat.player.y))
	{
		int damage = combat.monster_types[type]->calculate_damage();
		if (player.inventory.find_item_of_type(3))
		{
			chance = 30 + (player.inventory.inventory[index].dmg_bonus * 3);
			if (combat.monster_types[type]->does_hit(chance))
			{
				std::cout << ">> The Monster did " << damage << " damage." << std::endl;
				player.stats.health -= damage;
				wait();
			}
			else
			{
				std::cout << ">> The monster tried to hit but you blocked with your shield" << std::endl;
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

void Display::loot_room()
{
	clear();
	index = combat.random(1, player.inventory.items.size());
	statement = player.inventory.items.at(index).name;
	bonus = combat.random(1, player.stats.level);
	std::cout << ">> As you make your way through the dungeon you come across a door." << std::endl;
	std::cout << ">> Opening it reveals a sturdy chest in the centre, wrought iron bands wrap around securing it in place" << std::endl;
	if (player.inventory.items.at(index).item_type < 4 && 0 < bonus)
	{
		
		std::cout << ">> Prying the bands away and lifting the heavy lid reveals a +" << bonus << " " << statement << std::endl;
	}
	else
	{
		bonus = 0;
		std::cout << ">> Prying the bands away and lifting the heavy lid reveals a " << statement << std::endl;
	}
	valid = false;
	if (yes_no_validation("[?] Do you wish to take it? (y/n) "))
	{
		for (int i = 0; i < player.inventory.inventory.size(); i++)
		{
			if (player.inventory.inventory[i].item_id == 0)
			{
				player.inventory.set(i, index);
				player.inventory.inventory[i].dmg_bonus = bonus;
				break;
			}
		}
	}
	else
	{
		std::cout << ">> You decide not to take the " << statement << std::endl;
	}
}

bool Display::yes_no_validation(std::string question)
{
	valid = false;
	do
	{
		std::cout << question;
		std::cin >> choice_string;
		if (choice_string == "y")
		{
			valid = true;
			return true;
		}
		else if (choice_string == "n")
		{
			valid = false;
			return false;
		}
		else
		{
			std::cout << "[!] INVALID INPUT, TRY AGAIN." << std::endl;
		}
	} while (!valid);
}

void Display::new_level()
{
	dungeon.new_dungeon();
}