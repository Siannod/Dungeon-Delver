#pragma once
#include "dungeon.h"
#include "structs.h"


void Dungeon::generate()
{
	generator.generate(dungeon);
}

void Dungeon::print_dungeon()
{
	std::cout << "\n\n";
	for (std::vector<std::string> line : dungeon)
	{
		for (std::string column : line)
		{
			if (column == "0")
			{
				std::cout << "\033[47;37m";
				std::cout << column << " ";
			}
			else if (column == "1")
			{
				std::cout << "\033[41;31m";
				std::cout << column << " ";
			}
			else if (column == "X")
			{
				std::cout << "\033[47;30m";
				std::cout << column << " ";
			}
			else
			{
				std::cout << "\033[47;30m";
				std::cout << "?" << " ";
			}
			std::cout << "\033[0m";
		}
		std::cout << "\n";
	}
}

void Dungeon::check_paths(std::vector<int> coords, std::vector<MovementDirections>& directions)
{
	MovementDirections tempDirection;
	for (int i = 1; i < 5; i++)
	{
		temp_x = coords[0] + generator.direction.at(i)[2];
		temp_y = coords[1] + generator.direction.at(i)[3];
		tempDirection.dirNum = i;

		if (range())
		{
			if (dungeon[temp_x][temp_y] != "1")
			{
				tempDirection.available = true;
			}
			else
			{
				tempDirection.available = false;
			}
		}
		else
		{
			tempDirection.available = false;
		}
		
		directions.push_back(tempDirection);
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

}