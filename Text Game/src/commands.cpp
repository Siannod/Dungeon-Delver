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

void Command::get_help()
{
	std::cout << ">> view <index>: Prints out details of the item specified \n>> view_all: Shows all inventory slots and their details\n";
	std::cout << "\n>> back: goes back \n>> help: shows this list of commands \n>> drop <index>: drops specified item";
}

void Command::view(std::vector<InventorySpace::inventory_slot> inventory, std::map <int, std::string> items)
{
	std::cout << ">> Inventory slot " << inventory[stoi(command[1])].slot << " details:\n>> Name: " << items[inventory[stoi(command[1])].item_id];
}

void Command::view_all(std::vector<InventorySpace::inventory_slot> inventory, std::map <int, std::string> items)
{
	std::cout << "Inventory:\n";
	for (int i = 0; i < inventory.size(); i++)
	{
		std::cout << ">> - Slot " << inventory[i].slot << ": " << items[inventory[i].item_id] << "\n";
	}
}

void Command::set(std::vector<InventorySpace::inventory_slot>& inventory)
{
	inventory[stoi(command[1])].item_id = stoi(command[2]);
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



void Command::do_command(std::vector<InventorySpace::inventory_slot> inventory, std::map <int, std::string> items)
{
	if (command.empty()){std::cout << "[!] EMPTY COMMAND, TRY AGAIN.\n";}
	else if (command[0] == "help"){get_help();}
	else if (command[0] == "view"){view(inventory, items);}
	else if (command[0] == "view_all"){view_all(inventory, items);}
	else if (command[0] == "set"){set(inventory);}
	else if (command[0] == "drop") { drop(inventory, stoi(command[1])); }
	else{std::cout << "[!] INVALID COMMAND INPUT, TRY AGAIN\n";}
	std::cout << "\n";
}