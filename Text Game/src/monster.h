#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "stack.h"
#include "queue.h"

struct coords
{
	int x;
	int y;
	int cost;
};

struct MonsterStats
{
	int MAX_HEALTH;
	int health;
	int range;
	int damage;
	int moves_left = MAX_MOVES;
	const int MAX_MOVES = 5;
};

class Monster
{
public:
	Stack route;
	Queue queue = Queue(100);
	std::vector<std::vector<std::string>>* battle_field;
	Monster(int* x, int* y, int size, std::vector<std::vector<std::string>>* field_ptr)
	{
		player_x = x;
		player_y = y;
		SIZE = size;
		battle_field = field_ptr;
	}
	MonsterStats stats;

	QueueSpace::Node next_node;
	coords temp;
	coords diff;
	coords new_coords;
	coords aim;
	coords monster = { 11, 8, 0 };

	int* player_x;
	int* player_y;
	int SIZE;

	bool route_found = false;

	std::map <int, std::vector<int>> moves =
	{
		{1, {-2, 0}},
		{2, {0, 1}},
		{3, {2, 0}},
		{4, {0, -1}}
	};

	
	std::vector<std::vector<int>> visited;

	//STACK VARS
	Node current_node;
	int start_cost;


	//FUNCTIONS
	//external
	void next_move();

	void path_to_player_healthy();

	bool player_in_range();

	//internal

	void compare_spot();

	bool check_in_range_visited(int x, int y);

	void check_next_steps(int i);
};