#pragma once

#include "inventory.h"
#include "stack.h"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
struct PlayerStats
{
	int x = 1;
	int y = 1;
	int MAX_HEALTH;
	int health = MAX_HEALTH;
	int level;
	int coin;
	int upgrade_points;
	std::string name;
	std::map <std::string, int> stats =
	{
		{"Strength", 0},
		{"Dexterity", 0},
		{"Constitution", 0}
	};
};


class Player
{
private:
	bool to_level = false;
	bool valid = false;
	
	

public:
	//CLASSES
	Inventory inventory = Inventory(true);
	
	Player(bool run)
	{
		stats.upgrade_points = 5;
		create_character();
	}

	PlayerStats stats;
	PlayerStats* stats_ptr = &stats;

	//strings
	std::string player_name;
	//bool
	bool able_to_flee = true;
	
	
	//CHOICES
	//int
	int choice_int;
	//string
	std::string choice_string;
	//bool
	
	
	//MAPS
	

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
