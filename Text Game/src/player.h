#pragma once

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
	int health = level + stats.at("Constitution");
	int level = 1;
	int coin = 0;
	int choice_int;
	std::string choice_string;

	std::map <std::string, int> stats =
	{
		{"Strength", 0},
		{"Dexterity", 0},
		{"Consitution", 0}
	};

	std::vector <std::string> stat_names = { "Strength", "Dexterity", "Constitution" };


	//FUNCTIONS
	void level_up();

	void print_stats();

	void range_validation(int max);
};
