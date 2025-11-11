#pragma once
#include "dungeon_generator.h"

class Dungeon
{
public:
	int temp_x;
	int temp_y;
	
	

	std::vector<std::vector<std::string>> dungeon;

	std::map<int, std::string> rooms =
	{
		{2, "boss"},
		{3, "monster"},
		{4, "loot"}
	};

	std::map<int, int> room_count =
	{
		{2, 1},
		{3, 4},
		{4, 2}
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

	Generator generator = Generator(rooms, room_count);

	//FUNCTIONS
	void print_dungeon();

	void generate();

	void check_paths(std::vector<int> coords, std::vector<int> &temp);

	bool range();

	void move_player(int old_x, int old_y, int new_x, int new_y);
};