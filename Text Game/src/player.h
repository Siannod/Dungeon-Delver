#pragma once

#include "inventory.h"
#include "stack.h"
#include "structs.h"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <conio.h>




class Player
{
private:
	bool to_level = false;
	bool valid = false;

public:
	//CLASSES
	Inventory inventory;
	
	Player(bool run)
	{
		stats.upgrade_points = 5;
	}

	PlayerStats stats;
	PlayerStats* stats_ptr = &stats;

	//bool
	bool able_to_flee = true;
	
	
	//CHOICES
	//int
	int choice_int;
	//string
	std::string choice_string;

	//VECTOR
	std::vector <std::string> stat_names = { "Strength", "Dexterity", "Constitution"};
	std::string stat_name;
	std::vector<int> temp;


	//FUNCTIONS
	void create_character();

	void level_up();

	void print_stats_menu();

	void print_stats();

	bool range_validation(int min, int max, std::string statement);
	
	void move(int x_mod, int y_mod);

	bool check_level_up();
	
	void player_death();

	int calculate_max_health();
};