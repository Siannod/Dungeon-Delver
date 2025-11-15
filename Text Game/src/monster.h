#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

class Monster
{
public:
	Monster(int &x, int &y, int size)
	{
		player_x = x;
		player_y = y;
		SIZE = size;
	}
	const int MAX_MOVES = 5;
	int MAX_HEALTH;
	int health;
	int range;
	int damage;

	int monster_x = 11;
	int monster_y = 8;
	int new_x;
	int new_y;
	std::vector<std::vector<int>> aim;
	int player_x;
	int player_y;
	int SIZE;

	int moves_left = MAX_MOVES;


	std::map <int, std::vector<int>> moves =
	{
		{1, {-2, 0}},
		{2, {0, 1}},
		{3, {2, 0}},
		{4, {0, -1}}
	};

	//FUNCTIONS
	void path_to_player();

	bool player_in_range();

};