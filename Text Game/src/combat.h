#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Combat
{
public:

	std::map <std::string, std::string> field_pieces =
	{
		{"top_first" , "+-=-+"},
		{"mid_first", "|   |"},
		{"top_rest", "-=-+"},
		{"mid_rest", "   |"}
	};

	std::vector<std::string> battle_field;

	//FUNCTIONS
	void fill_field();
};