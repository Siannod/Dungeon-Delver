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

	//DUNGEON LEVEL
	int dungeon[wall_max][wall_max];

	//CO-ORDS
	int tempx;
	int tempy;
	int back;
	int wall_x = 1;
	int wall_y = 1;
	int new_wall;

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
	void fill_dungeon();

	void generate();

	int random(int min, int max);

	void print_dungeon();

	void check_new_walls();

};