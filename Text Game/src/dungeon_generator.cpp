#pragma once
#include <string>
#include <algorithm>
#include "dungeon_generator.h"

void Generator::fill_dungeon()
{
	for (int i = 0; i < wall_max; i++)
	{
		for (int j = 0; j < wall_max; j++)
		{
			dungeon[i][j] = 1;
		}
	}
	dungeon[1][1] = 0;
}

int Generator::random(int min, int max)
{
	if (max == 0)
	{
		return 0;
	}
	srand(time(0));
	return rand() % (max);
}

void Generator::print_dungeon()
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

void Generator::generate()
{
	fill_dungeon();
	wall_x = 1;
	wall_y = 1;
	walls = { {3, 1 ,3}, {1, 3, 2} };
	visited = {};
	dungeon[1][1] = 0;
	do
	{
		new_wall = random(0, walls.size() - 1);
		wall = walls[new_wall];
		wall_x = wall[0];
		wall_y = wall[1];
		back = wall[2];
			
		if (dungeon[wall_x][wall_y] == 1)
		{
			dungeon[wall_x][wall_y] = 0;
			dungeon[wall_x - direction.at(back)[2]][wall_y - direction.at(back)[3]] = 0;
		}

		visited.push_back(wall);
		walls.erase(find(walls.begin(), walls.end(), wall));
			
		check_new_walls();

	}while (walls.size() != 0);
	
}

void Generator::check_new_walls()
{
	for (int i = 1; i < direction.size() + 1; i++)
	{
		tempx = wall_x + direction.at(i)[0];
		tempy = wall_y + direction.at(i)[1];

		if (0 < tempx && tempx < wall_max && 0 < tempy && tempy < wall_max)
		{
			if (dungeon[tempx][tempy] == 1)
			{
				wall = { tempx, tempy, i };
				if (find(visited.begin(), visited.end(), wall) == visited.end())
				{
					walls.push_back(wall);
				}
			}
		}
	}
}