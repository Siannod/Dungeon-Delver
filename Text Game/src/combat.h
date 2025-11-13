#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Combat
{
public:
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

	std::vector<std::vector<std::string>> battle_field;

	std::map <int, std::vector<int>> move =
	{
		{1, {-2, 0}},
		{2, {0, 2}},
		{3, {2, 0}},
		{4, {0, -2}}
	};

	std::string start;
	std::string end;

	//FUNCTIONS
	void fill_field();

	void print_field();
};