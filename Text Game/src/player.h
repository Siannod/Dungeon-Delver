#pragma once

#include "inventory.h"
#include "stack.h"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

class Player
{
private:
	bool to_level = false;
	bool valid = false;
	
	

public:
	//CLASSES
	Inventory inventory;
	Stack location;

	
	//INTS
	int player_x = 1;
	int player_y = 1;
	
	int level = 1;
	int coin = 0;

	int choice_int;

	//STRINGS
	std::string choice_string;
	std::string player_name;
	
	//MAPS
	std::map <std::string, int> stats =
	{
		{"Strength", 0},
		{"Dexterity", 0},
		{"Constitution", 0}
	};



	//VECTOR
	std::vector <std::string> stat_names = { "Strength", "Dexterity", "Constitution"};
	std::vector<int> temp;
	std::vector<int> co_ords = { 1, 1 };

	//FUNCTIONS
	void level_up();

	void print_stats();

	bool range_validation(int min, int max, std::string statement, bool valid = false);
	
	void move(int x_mod, int y_mod);
};
