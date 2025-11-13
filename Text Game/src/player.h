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
	
	Player()
	{
		upgrade_points = 5;
		create_character();

	}
	//PLAYER STATS
	//ints
	int level = 1;
	int coin = 0;
	int health_max;
	int health_current;
	int upgrade_points;
	
	int player_x = 1;
	int player_y = 1;
	//strings
	std::string player_name;
	
	
	
	//CHOICES
	//int
	int choice_int;
	//string
	std::string choice_string;
	//bool
	
	
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


	//FUNCTIONS
	void create_character();

	void level_up();

	void print_stats();

	bool range_validation(int min, int max, std::string statement, bool valid = false);
	
	void move(int x_mod, int y_mod);
};
