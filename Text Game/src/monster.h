#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "stack.h"

class Monster
{
public:
	Stack route;
	std::vector<std::vector<std::string>> battle_field;
	Monster(int &x, int &y, int size, std::vector<std::vector<std::string>> &field)
	{
		player_x = x;
		player_y = y;
		SIZE = size;
		battle_field = field;
	}
	const int MAX_MOVES = 5;
	int MAX_HEALTH;
	int health;
	int range;
	int damage;

	int monster_x = 11;
	int monster_y = 8;

	int x_diff;
	int y_diff;
	int total_diff;

	int new_x;
	int new_y;

	int aim[3];
	int aim_x;
	int aim_y;
	int player_x;
	int player_y;

	int SIZE;

	int moves_left = MAX_MOVES;

	bool route_found = false;

	std::map <int, std::vector<int>> moves =
	{
		{1, {-2, 0}},
		{2, {0, 1}},
		{3, {2, 0}},
		{4, {0, -1}}
	};

	//FUNCTIONS
	void player_spots();

	void compare_spot();

	bool player_in_range();

	void path_to_player_healthy();

	bool check_in_range(int x, int y);

};