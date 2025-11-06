#pragma once

#include "inventory.h"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

class Player
{
private:
	bool to_level = true;
	bool valid = false;
	int co_ords[2] = { 1, 1 };
	

public:
	Inventory inventory;

	std::string player_name;

	int player_x = 1;
	int player_y = 1;
	
	int level = 1;
	int coin = 0;

	int choice_int;
	std::string choice_string;
	
	std::map <std::string, int> stats =
	{
		{"Strength", 0},
		{"Dexterity", 0},
		{"Constitution", 0}
	};

	std::vector <std::string> stat_names = { "Strength", "Dexterity", "Constitution"};


	//FUNCTIONS
	void level_up();

	void print_stats();

	bool range_validation(int min, int max, std::string statement, bool valid = false);
};
