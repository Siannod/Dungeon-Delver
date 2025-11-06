#pragma once
#include "dungeon_generator.h"

class Dungeon
{
public:
	
	
	std::vector<std::vector<int>> dungeon;

	Generator generator;

	std::map<int, std::string> rooms =
	{
		{0, "path"},
		{1, "wall"},
		{2, "boss"},
		{3, "room"}
	};



	//FUNCTIONS
	void print_dungeon();

	void generate();
};