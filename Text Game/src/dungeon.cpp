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
			if (dungeon[i][j] == "X")
			{
				std::cout << "X ";
			}
			else if (dungeon[i][j] != "1")
			{
				std::cout << "0 ";
			}
			else
			{
				std::cout << "1 ";
			}
		}
		std::cout << "\n";
	}
}

void Dungeon::check_paths(std::vector<int> coords, std::vector<int>& temp)
{
	for (int i = 1; i < 5; i++)
	{
		temp_x = coords[0] + generator.direction.at(i)[2];
		temp_y = coords[1] + generator.direction.at(i)[3];
		if (range())
		{
			if (dungeon[temp_x][temp_y] != "1")
			{
				temp.push_back(i);
			}
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

void Dungeon::move_player(int old_x, int old_y, int move_x, int move_y)
{
	dungeon[old_x][old_y] = "0";
	dungeon[old_x + move_x][old_y + move_y] = "X";
}