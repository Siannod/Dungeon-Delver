#pragma once
#include "dungeon.h"

void Dungeon::generate()
{
	generator.generate(dungeon);
}

void Dungeon::print_dungeon()
{
	std::cout << "\n\n";
	for (std::vector<std::string> line : dungeon)
	{
		
		for (std::string colummn : line)
		{
			std::cout << colummn << " ";
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

bool Dungeon::range() //checks if the co-ords are in range
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

void Dungeon::move_player(int new_x, int new_y, int move_x, int move_y) //moves player icon in the dungeon
{
	dungeon[new_x][new_y] = "X";
	dungeon[new_x - move_x][new_y - move_y] = "0";
}

void Dungeon::new_dungeon()
{
	level += 0.1;
	generator.fill_dungeon(dungeon);
	generator.generate(dungeon);
	room_count.at(2) = 1;
	room_count.at(3) = 4 * level;
	room_count.at(4) = 2 * level;
	generator.gen_rooms(dungeon);
	print_dungeon();
	
}