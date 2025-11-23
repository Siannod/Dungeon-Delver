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
	Stack route;
	Queue queue = Queue(100);

	std::vector<std::vector<std::string>>* battle_field;
	
	PlayerStats* player_stats_ptr;
	MonsterStats stats;

	QueueSpace::Node next_node;
	coords temp;
	coords diff;
	coords new_coords;
	coords aim = {100, 100, 100};
	coords monster = { 11, 8, 0 };

	coords last_player = { 1, 1, 0 };

	int* player_x;
	int* player_y;

	int value;

	int SIZE;

	int hit_chance;

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

	Monster(PlayerStats* stats_ptr, int size, std::vector<std::vector<std::string>>* field_ptr)
	{
		player_stats_ptr = stats_ptr;
		SIZE = size;
		battle_field = field_ptr;
	}

	//FUNCTIONS
	//external
	bool next_move(int player_x, int player_y);

	void path_to_player_healthy();

	virtual bool player_in_range(int player_x, int player_y);

	virtual int calculate_damage();

	bool check_at_aim();

	//internal

	virtual void create_monster(PlayerStats* stats);

	void compare_spot();

	bool has_player_moved(int x, int y);

	bool check_in_range_visited(int x, int y);

	void check_next_steps(int i);

	int random(int min, int max);

	bool does_hit(int chance);

	int coin_worth(int level);
};