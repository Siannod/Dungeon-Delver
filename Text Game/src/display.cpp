#pragma once
#include "display.h"

void Display::clear()
{
	system("cls");
}

void Display::main_menu()
{
	std::cout << menu_top << std::endl;
	std::cout << "| 1. Move	 2. Inventory |" << std::endl;
	std::cout << "| 3. Spells	 4. Stats     |" << std::endl;
	std::cout << menu_top << std::endl;
	std::cout << "- Select menu option: ";
	if (input_validation(1, 4, "- Select menu option: ", false))
	{
		if (choice_int == 1) { clear();  dungeon_move_options(); }
		else if (choice_int == 2) { clear(), inventory(); }
	}
}
//

void Display::dungeon_move_options()
{
	dungeon.print_dungeon();
	temp.clear();
	dungeon.check_paths({player.player_x, player.player_y}, temp);
	for (int i = 0; i < temp.size(); i++)
	{		
		std::cout << ">> " << i+1 << ". " << dungeon.directions.at(temp[i]) << std::endl;
	}
	std::cout << ">> "<< temp.size()+1 << ". Back to main menu" << std::endl;
	std::cout << "- ";
	input_validation(1, temp.size()+1, "- ", false);
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

void Display::inventory(bool valid)
{
	std::cin.ignore();
	while (!command.go_back)
	{
		command.view_all(player.inventory.inventory, player.inventory.items);
		std::cout << ">> Type 'help' for more commands" << std::endl;
		std::cout << "- ";
		std::getline(std::cin, choice_string);
		command.delimit(choice_string);
		command.do_command(player.inventory.inventory, player.inventory.items);
		_getch();
		clear();
	}
	main_menu();
}

void Display::monster_encounter(bool alive)
{
	clear();
	
	do
	{
		clear();
		std::cout << ">> As you continue along your path, dark shadows masking the way forwards a monster looms out of the darkness" << std::endl;
		combat.print_field();
		combat_menu();
		
		if (choice_int == 1) {
			if (combat.moves_left == 0)
			{
				clear();
				combat.print_field();
				std::cout << "[!] NO MORE MOVES LEFT THIS TURN";
				_getch();

			}
			else
			{
				combat_move();
			}	
		}
		if (choice_int == 2) { inventory(); }
		if (choice_int == 4) { combat.flee(player.stats.at("Dexterity")); }
	} while (alive);
}

void Display::combat_menu()
{
	std::cout << "+=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=+" << std::endl;
	std::cout << "| 1. Move    2. Items | Health: " << player.health_current << " |" << std::endl;
	std::cout << "| 3. Fight   4. Flee  | Moves: " << combat.moves_left << "  |" << std::endl;
	std::cout << "+=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=+" << std::endl;
	std::cout << "- ";
	input_validation(1, 4, "- ", false);
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