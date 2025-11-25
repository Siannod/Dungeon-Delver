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
	std::vector<std::vector<std::string>> dungeon_temp;
	Generator(std::map<int, std::string> room, std::map<int, int> &room_counts, std::vector<std::vector<std::string>>& dungeon)
	{
		rooms = room;
		room_count = room_counts;
		dungeon_temp = dungeon;
	}
	int temp;
	//CO-ORDS
	int tempx;
	int tempy;
	int back;
	int wall_x = 1;
	int wall_y = 1;
	int new_wall;

	//ROOM GENERATION
	int new_room = 0;
	int room_type = 0;
	bool generating = true;

	//VECTORS
	std::vector<int> wall;
	std::vector<std::vector<int>> walls = { {4, 1 ,3}, {1, 4, 2} };
	std::vector<std::vector<int>> visited;
	std::vector<std::vector<int>> nodes;

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

	void gen_rooms(std::vector<std::vector<std::string>>& dungeon, bool generating = true);
};