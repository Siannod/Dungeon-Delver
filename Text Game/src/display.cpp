#pragma once
#include "display.h"

void Display::setup()
{
	dungeon.generate();
	player.inventory.initialise();
}

void Display::clear()
{
	system("cls");
}

void Display::main_menu()
{
	std::cout << "+ - - - - - - - - - - - - - - +" << std::endl;
	std::cout << "| 1. Move	 2. Inventory |" << std::endl;
	std::cout << "| 3. Spells	 4.           |" << std::endl;
	std::cout << "+ - - - - - - - - - - - - - - +" << std::endl;
	std::cout << "- Select menu option: ";
	if (input_validation(1, 4, "- Select menu option: ", false))
	{
		if (choice_int == 1) { clear();  move_options(); }
		if (choice_int == 2) { clear(), inventory(); }
	}
}

void Display::move_options()
{
	dungeon.print_dungeon();
	temp.clear();
	dungeon.check_paths(player.co_ords, temp);
	for (int i = 0; i < temp.size(); i++)
	{		
		//std::cout << temp[i];
		std::cout << ">> " << i+1 << ". " << dungeon.directions.at(temp[i]) << std::endl;
	}
	std::cout << ">> "<< temp.size()+1 << ". Back to main menu" << std::endl;
	std::cout << "- ";
	input_validation(1, temp.size()+1, "- ", false);
	if (choice_int < temp.size() + 1)
	{
		player.move(dungeon.direction.at(temp[choice_int-1])[0], dungeon.direction.at(temp[choice_int-1])[1]);
		clear();
		move_options();
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