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

void Dungeon::check_paths(std::vector<int> coords, std::vector<int>& temp)
{
	for (int i = 1; i < 5; i++)
	{
		temp_x = coords[0] + generator.direction.at(i)[0];
		temp_y = coords[1] + generator.direction.at(i)[1];
		if (dungeon[temp_x][temp_y] == 1 && range())
		{
			temp.push_back(i);
		}
	}
}

bool Dungeon::range()
{
	if (temp_x > 0 && temp_x < wall_max && 0 < temp_y && temp_y < wall_max)
	{
		return true;
	}
	else
	{
		return false;
	}
}