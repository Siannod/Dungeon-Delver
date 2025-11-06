#pragma once
#include "dungeon.h"

void Dungeon::generate()
{
	generator.generate(dungeon);
}

void Dungeon::print_dungeon()
{
	std::cout << "\n\n";
	for (int i = 0; i < wall_max; i++)
	{
		for (int j = 0; j < wall_max; j++)
		{
			std::cout << dungeon[i][j] << " ";
		}
		std::cout << "\n";
	}
}