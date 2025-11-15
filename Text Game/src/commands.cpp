#pragma once
#include "commands.h"

void Command::delimit(std::string input)
{
	command.clear();
	std::string temp;
	std::stringstream input_stream(input);
	while (std::getline(input_stream, temp, ' '))
	{
		command.push_back(temp);
	}
}

char Command::convert_case(char letter)
{
	if (int(letter) >= 97 && int(letter) <= 122)
	{
		return letter - 32; //IF LETTER IS LOWERCASE CONVERT TO UPPERCASE
	}
	else
	{
		return letter + 32; //IF LETTER IS UPPERCASE CONVERT TO LOWERCASE
	}
}



void Command::get_help()
{
	std::cout << ">> view <index>: Prints out details of the item specified\n";
	std::cout << ">> back: goes back \n>> help: shows this list of commands \n>> drop <index>: drops specified item";
}