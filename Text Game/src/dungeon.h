#pragma once
#include "dungeon_generator.h"

class Dungeon
{
public:
	
	
	std::vector<std::vector<int>> dungeon;

	Generator generator;



	//FUNCTIONS
	void print_dungeon();

	void generate();
};