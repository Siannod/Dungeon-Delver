#pragma once

#include "dungeon_generator.h"

void Generator::fill_dungeon(std::vector<std::vector<std::string>> &dungeon)
{
	dungeon.clear();
	for (int i = 0; i < wall_max; i++)
	{
		dungeon.push_back({});
		for (int j = 0; j < wall_max; j++)
		{
			dungeon[i].push_back("1");
		}
	}
	dungeon[1][1] = "0";
}

void Generator::generate(std::vector<std::vector<std::string>> &dungeon)
{
	wall_x = 1;
	wall_y = 1;
	walls = { {3, 1 ,3}, {1, 3, 2} };
	visited = {};
	dungeon[1][1] = "0";
	do
	{
		new_wall = random(0, walls.size() - 1);
		wall = walls[new_wall];
		wall_x = wall[0];
		wall_y = wall[1];
		back = wall[2];
		if (dungeon[wall_x][wall_y] == "1")
		{
			dungeon[wall_x][wall_y] = "0";
			nodes.push_back(wall);
			dungeon[wall_x - direction.at(back)[2]][wall_y - direction.at(back)[3]] = "0";
		}
		visited.push_back(wall);
		walls.erase(find(walls.begin(), walls.end(), wall));
		check_new_walls(dungeon);
		
	
	} while (walls.size() != 0);
	dungeon[1][1] = "X";
	gen_rooms(dungeon);
}

void Generator::gen_rooms(std::vector<std::vector<std::string>>& dungeon, bool generating)
{
	do
	{
		room_type = random(2, 5);
		if (room_count.at(room_type) != 0)
		{
			new_room = random(0, nodes.size());
			wall = nodes[new_room];
			wall_x = wall[0];
			wall_y = wall[1];
			if (room_type == 2)
			{
				if (wall_x > 15 && wall_y > 15)
				{
					dungeon[wall_x][wall_y] = "2";
					room_count.at(2) = 0;
				}
			}
			else
			{
				dungeon[wall_x][wall_y] = std::to_string(room_type);
				room_count.at(room_type) = room_count.at(room_type) - 1;
			}
			nodes.erase(nodes.begin() + new_room);
		}
		else if (room_count.at(2) == 0 && room_count.at(3) == 0 && room_count.at(4) == 0)
		{
			generating = false;
		}
	} while (generating);
	std::cout << "\n";
}


void Generator::check_new_walls(std::vector<std::vector<std::string>> dungeon)
{
	for (int i = 1; i < direction.size() + 1; i++)
	{
		tempx = wall_x + direction.at(i)[0];
		tempy = wall_y + direction.at(i)[1];
		if (0 < tempx && tempx < wall_max && 0 < tempy && tempy < wall_max)
		{
			if (dungeon[tempx][tempy] == "1")
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

int Generator::random(int min, int max)
{
	if (max == 0)
	{
		return 0;
	}
	srand(time(0));
	temp = min + rand() % (max - min);
	return temp;
}

