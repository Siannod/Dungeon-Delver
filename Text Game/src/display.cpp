#pragma once
#include "display.h"

void Display::clear()
{
	system("cls");
}

void Display::main_menu()
{
	std::cout << "+ - - - - - - - - - - - - - +" << std::endl;
	std::cout << "| 1. Move		 2. Inventory |" << std::endl;
	std::cout << "| 3. Spells	 4.           |" << std::endl;
	std::cout << "+ - - - - - - - - - - - - - +" << std::endl;
}