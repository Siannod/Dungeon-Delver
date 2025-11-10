#pragma once
#include "display.h"

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
		if (choice_int == 1) { move_options(); }
	}
}

void Display::move_options()
{

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