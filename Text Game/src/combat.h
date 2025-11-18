#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
#include "player.h"
#include "monster.h"

class Combat
{
public:
	
	const int FIELD_SIZE = 11;
	
	Combat()
	{
		fill_field();
		
	}
	std::map <std::string, std::string> field_pieces =
	{
		{"top_first" , "+-=-+"},
		{"mid_first", "|"},
		{"top_rest", "-=-+"},
		{"mid_rest", "   |"}
	};

	std::vector<std::string> field_rows = { "|", " ", " ", "|" };

	std::vector<std::vector<std::string>> battle_field;

	std::vector<std::vector<std::string>>* field_ptr = &battle_field;

	std::map <int, std::vector<int>> moves =
	{
		{1, {-2, 0}},
		{2, {0, 1}},
		{3, {2, 0}},
		{4, {0, -1}}
	};

	std::vector<int> options;

	std::string start;
	std::string end;

	int player_x = 1;
	int player_y = 1;

	int new_x;
	int new_y;

	bool alive;

	int moves_left = 5;
	bool action_left = true;
	
	int temp;

	int* x_ptr = &player_x;
	int* y_ptr = &player_y;

	Node next_step;

	Monster monster = Monster(x_ptr, y_ptr, FIELD_SIZE, field_ptr);
	//FUNCTIONS
	void fill_field();

	void print_field();

	void move_player();

	void move_monster(int x, int y);

	void check_moves();

	bool flee(int dex);

	int random(int min, int max);

	bool check_for_enemy(int range);

	void monster_turn();
};