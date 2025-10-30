#pragma once
#include <string>
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
	print_visited();
	print_walls();
	if (std::find(visited.begin(), visited.end(), wall) != visited.end() || visited.empty())
	{
		//NOT VIISTED
		std::cout << "visi" << std::endl;
		if (wall_min < wallx && wallx + directionx < wall_max && wall_min < wally && wally + directiony < wall_max)
		{
			//IN RANGE
			std::cout << "rnage" << std::endl;
			if (dungeon[wallx][wally] == 1 && dungeon[wallx + directionx][wally + directiony] == 1)
			{
				//ISNT A PATH
				//std::cout << "path";
				if (dungeon[wallx][wally + 1] == 1)
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
		std::cout << wall[0] << wall[1] << wall[2] << std::endl;
		wallx = wall[0];
		wally = wall[1];
		move = wall[2];
		directionx = directions.at(move)[0];
		directiony = directions[move][1];
		visited.push_back(wall);
		walls.erase(find(walls.begin(), walls.end(), wall));
		if (valid())
		{
			dungeon[wallx][wally] = 0;
			dungeon[wallx - directionx][wally - directiony] = 0;
			for (int i = 0; i < 4; i += 2)
			{
				//std::cout << i;
				directionx = direction_fill.at(wall[2])[i];
				directiony = direction_fill.at(wall[2])[i + 1];
				dungeon[wallx - directionx][wally - directiony] = 0;
			}
			new_walls();
			
		}
		if (walls.empty())
		{
			finished = true;
		}
		print_dungeon();
	} while (!finished);
}


int Generator::random(int min, int max)
{
	srand(time(0));
	return min + rand() % (max - min);
}

void Generator::print_dungeon()
{
	std::cout << "\n\n";
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			std::cout << dungeon[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Generator::new_walls()
{
	std::cout << "test" << std::endl;
	for (int i = 1; i < 5; i++)
	{
		tempx = wallx + directions.at(i)[0];
		tempy = wally + directions.at(i)[1];
		wall = { tempx, tempy, i };
		std::cout << tempx << tempy << i << std::endl;
		if (std::find(visited.begin(), visited.end(), wall) != visited.end() || visited.empty())
		{
			std::cout << "visit" << std::endl;
			//NOT VISITED
			if (wall_min < tempx && tempx < wall_max && wall_min < tempy && tempy < wall_max)
			{
				if (dungeon[tempx][tempy] == 1)
				{
					walls.push_back(wall);
				}
			}
		}
	}
}

void Generator::print_visited()
{
	std::cout << "visited: " << std::endl;
	for (int i = 0; i < visited.size(); i++)
	{
		std::cout << visited[i][0] << " " << visited[i][1] << " "<<  visited[i][2] << std::endl;
	}
}

void Generator::print_walls()
{
	std::cout << "walls: " << std::endl;
	for (int i = 0; i < walls.size(); i++)
	{
		std::cout << walls[i][0] << " " << walls[i][1] << " " << walls[i][2] << std::endl;
	}
}

void Generator::generate_2()
{
	wallx = 1;
	wally = 1;
	dungeon[wallx][wally] = 0;
	do
	{
		//std::cout << "test";
		if (!(walls.empty()))
		{
			//std::cout << "test";
			rand_wall = random(0, walls.size());
			wall = walls[rand_wall];
			wallx = wall[0];
			wally = wall[1];
			move = wall[2];
			if (dungeon[wallx][wally] != 0)
			{
				//std::cout << "test";
				dungeon[wallx][wally] = 0;
				for (int i = 0; i < 4; i += 2)
				{
					//std::cout << "test";
					tempx = wallx - direction_fill.at(move)[i];
					tempy = wally - direction_fill.at(move)[i + 1];
					dungeon[tempx][tempy] = 0;
				}
			}
			visited.push_back(wall);
			walls.erase(find(walls.begin(), walls.end(), wall));
			new_walls();
		}
		else
		{
			finished = true;
		}

	} while (!finished);
}