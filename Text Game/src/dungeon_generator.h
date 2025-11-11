#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
#include <string>

constexpr int wall_min = 0;
constexpr int wall_max = 21;

class Generator
{
public:
	std::map<int, std::string> rooms;
	std::map<int, int> room_count;
	Generator(std::map<int, std::string> room, std::map<int, int> &room_counts)
	{
		rooms = room;
		room_count = room_counts;
	}
	//CO-ORDS
	int tempx;
	int tempy;
	int back;
	int wall_x = 1;
	int wall_y = 1;
	int new_wall;

	//ROOM GENERATION
	bool new_room = false;
	int room_type = 0;

	//VECTORS
	std::vector<int> wall;
	std::vector<std::vector<int>> walls = { {4, 1 ,3}, {1, 4, 2} };
	std::vector<std::vector<int>> visited;

	//MAPS
	std::map<int, std::vector<int>> direction =
	{
		{1, {-2, 0, -1, 0}},
		{2, {0, 2, 0, 1}},
		{3, {2, 0, 1, 0}},
		{4, {0, -2, 0, -1}}
	};
	

	//FUNCTIONS
	void fill_dungeon(std::vector<std::vector<std::string>> &dungeon);

	void generate(std::vector<std::vector<std::string>> &dungeon);

	int random(int min, int max);

	void check_new_walls(std::vector<std::vector<std::string>> dungeon);

	int get_room_type();
};