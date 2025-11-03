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
private:

public:
	bool finished = false;

	//DUNGEON LEVEL
	int dungeon[wall_max][wall_max];

	//CO-ORDS
	int tempx;
	int tempy;
	int loop = 0;
	int size;
	int back;
	int wall_x = 1;
	int wall_y = 1;
	int rand_wall = 0;
	int directionx;
	int directiony;
	int move;
	int new_wall;
	std::vector<int> wall;

	int wall_store[2] = { wallx, wally };

	std::vector<std::vector<int>> walls = { {4, 1 ,3}, {1, 4, 2} };
	std::vector<std::vector<int>> visited;

	std::map<int, std::vector<int>> directions =
	{
		{1, {-3, 0}},
		{2, {0, 3}},
		{3, {3, 0}},
		{4, {0, -3}}
	};

	std::map<int, std::vector<int>> direction_fill =
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