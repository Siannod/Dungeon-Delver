#pragma once
#include "dungeon_generator.h"
#include <thread>

class Dungeon
{
public:
	int temp_x;
	int temp_y;
	
	float level = 1;
	

	std::vector<std::vector<std::string>> dungeon;


	//ROOM GENERATION
	const int boss_max = 1;
	const int monster_max = 4;
	const int loot_max = 2;
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

	std::thread t;

	Generator generator = Generator(rooms, room_count, dungeon);

	//FUNCTIONS
	void start_up();

	void print_dungeon();

	void generate();

	void check_paths(std::vector<int> coords, std::vector<int> &temp);

	bool range();

	void move_player(int old_x, int old_y, int new_x, int new_y);

	void new_dungeon();
};