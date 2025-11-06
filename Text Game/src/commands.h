#pragma once
#include "inventory.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>   

class Command
{
public:
	std::vector<std::string> command;
	std::string temp;
	bool rstrt = false;


	//FUNCTIONS
	void delimit(std::string input);

	void do_command(std::vector<InventorySpace::inventory_slot> inventory, std::map <int, std::string> items);

	void get_help();

	void view(std::vector<InventorySpace::inventory_slot> inventory, std::map <int, std::string> items);

	void view_all(std::vector<InventorySpace::inventory_slot> inventory, std::map <int, std::string> items);

	void set(std::vector<InventorySpace::inventory_slot>& inventory);

	char convert_case(char letter);
};