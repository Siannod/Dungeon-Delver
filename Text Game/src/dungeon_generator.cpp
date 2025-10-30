#pragma once
#include "dungeon_generator.h"

void Generator::fill_dungeon()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			dungeon[i][j] = 1;
		}
	}
	dungeon[1][1] = 0;
}

bool Generator::valid()
{
	if (std::find(visited.begin(), visited.end(), wall) != visited.end())
	{
		//NOT VIISTED
		if (wall_min < wallx && wallx + directionx < wall_max && wall_min < wally && wally + directiony < wall_max)
		{
			//IN RANGE
			if (dungeon[wallx][wally] == 1 && dungeon[wallx + directionx][wally + directiony] == 1)
			{
				//ISNT A PATH
				if (dungeon[wallx][wally + 1] != 1)
				{
					//NOT BORDERING A ROOM
					return true;
				}
			}
		}
	}
	return false;
}

void Generator::generate()
{
	do
	{
		rand_wall = random(0, walls.size());
		wall = walls[rand_wall];
		wallx = wall[0];
		wally = wall[1];
		directionx = directions[wall[2]][0];
		directiony = directions[wall[2]][1];
		if (valid())
		{

		}
		else
		{
			visited.push_back(wall);
		}
		if (walls.empty())
		{
			finished = true;
		}
	} while (!finished);
}


int Generator::random(int min, int max)
{
	srand(time(0));
	return min + rand() % (max - min);
}