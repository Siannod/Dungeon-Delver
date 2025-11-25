#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "player.h"
#include "stack.h"
#include "queue.h"
#include "structs.h"


class Monster
{
public:
	//CLASSES
	Stack route;
	Queue queue = Queue(100);	
	PlayerStats* player_stats_ptr;
	MonsterStats stats;

	//COORDS
	coords temp;
	coords diff;
	coords new_coords;
	coords aim = {100, 100, 100};
	coords monster = { 11, 8, 0 };
	coords last_player = { 1, 1, 0 };

	//INTS
	int* player_x;
	int* player_y;
	int value;
	int SIZE;
	int hit_chance;

	//BOOL
	bool route_found = false;

	//MAP
	std::map <int, std::vector<int>> moves =
	{
		{1, {-2, 0}},
		{2, {0, 1}},
		{3, {2, 0}},
		{4, {0, -1}}
	};

	//VECTOR
	std::vector<std::vector<int>> visited;

	std::vector<std::vector<std::string>>* battle_field;
	//STACK VARS
	Node current_node;
	int start_cost;

	//QUEUE VARS
	QueueSpace::Node next_node;
	Monster(PlayerStats* stats_ptr, int size, std::vector<std::vector<std::string>>* field_ptr)
	{
		player_stats_ptr = stats_ptr;
		SIZE = size;
		battle_field = field_ptr;
	}

	//FUNCTIONS
	//external
	bool next_move(int player_x, int player_y); //calculates where the monster wants to go

	void path_to_player_healthy(); //find the optimal path there

	virtual bool player_in_range(int player_x, int player_y); //checks if the players in range

	virtual int calculate_damage();

	//internal

	virtual void create_monster(PlayerStats* stats);

	void compare_spot();

	bool check_in_range_visited(int x, int y);

	void check_next_steps(int i);

	int random(int min, int max);

	bool does_hit(int chance);

	int coin_worth(int level);
};