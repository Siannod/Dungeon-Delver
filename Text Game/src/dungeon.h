#pragma once
#include "dungeon_generator.h"

class Dungeon
{
public:
	int temp_x;
	int temp_y;
	
	Generator generator;
	
	std::vector<std::vector<int>> dungeon;

	std::map<int, std::string> rooms =
	{
		{0, "path"},
		{1, "wall"},
		{2, "boss"},
		{3, "room"}
	};

	std::map<int, std::vector<int>> direction =
	{
		{1, {-2, 0}},
		{2, {0, 2}},
		{3, {2, 0}},
		{4, {0, -2}}
	};

	std::map<int, std::string> directions =
	{
		{1, "North"},
		{2, "East"},
		{3, "South"},
		{4, "West"}
	};

	//FUNCTIONS
	void print_dungeon();

	void generate();

	void check_paths(std::vector<int> coords, std::vector<int> &temp);

	bool range();
};