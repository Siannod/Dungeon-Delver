#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

constexpr int wall_min = 0;
constexpr int wall_max = 15;

class Generator
{
public:
	bool finished = false;

	//DUNGEON LEVEL
	int dungeon[15][15];

	//CO-ORDS
	int wallx = 1;
	int wally = 1;
	int temp = 0;
	int directionx;
	int directiony;
	int move;
	std::vector<int> wall;

	std::vector<std::vector<int>> walls = { {3, 1 ,3}, {1, 3, 2} };
	std::vector<std::vector<int>> visited;

	std::map<int, std::vector<int>> directions =
	{
		{1, {0, 3}},
		{2, {3, 0}},
		{3, {0, -3}},
		{4, {-3, 0}}
	};

	//FUNCTIONS
	void fill_dungeon();

	void generate();
	
	int random(int min, int max);
};