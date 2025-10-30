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

void Generator::generate()
{
	do
	{
		temp = random(0, walls.size());
		wall = walls[temp];
		wallx = wall[0];
		wally = wall[1];
		directionx = directions[wall[2]][0];
		directiony = directions[wall[2]][1];
		if (std::find(visited.begin(), visited.end(), wall) != visited.end())
		{
			//NOT VIISTED
			if (wall_min < wallx && wallx + directionx < wall_max && wall_min < wally && wally + directiony < wall_max)
			{
				//NOT VISITED & IN RANGE
				if (dungeon[wallx][wally] == 1 && dungeon[wallx + directionx][wally + directiony] == 1)
				{
					//NOT VISITED & IN RANGE & IS A WALL
					if (dungeon[wallx][wally + 1] != 1)
					{
						//NOT VISITED & IN RANGE & IS A WALL & NOT BORDERING ROOM
						if (directionx + directiony > 0)
						{
							for (int i = 0; i < 2; i++)
							{
								for (int j = 0; j < directions[wall[2]][i]; j++)
								{

								}
							}
						}
						else
						{

						}
					}
					else
					{
						visited.push_back(wall);
					}
				}
				else
				{
					visited.push_back(wall);
				}
			}
			else
			{
				visited.push_back(wall);
			}
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