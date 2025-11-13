#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Combat
{
public:
	const int FIELD_SIZE = 10;
	Combat()
	{
		fill_field();
	}
	std::map <std::string, std::string> field_pieces =
	{
		{"top_first" , "+-=-+"},
		{"mid_first", "|   |"},
		{"top_rest", "-=-+"},
		{"mid_rest", "   |"}
	};

	std::vector<std::string> field_rows = { "|", " ", " ", "|" };

	std::vector<std::vector<std::string>> battle_field;

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
	int player_y = 0;

	int new_x;
	int new_y;

	bool alive;

	//FUNCTIONS
	void fill_field();

	void print_field();

	void move_player();

	void check_moves();
};