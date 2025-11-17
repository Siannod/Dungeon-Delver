#pragma once
#include "monster.h"

bool Monster::player_in_range()
{
	for (std::pair<int, std::vector<int >> direction : moves)
	{
		for (int j = 0; j <= range; j++)
		{
			if (j != 0)
			{
				new_x = monster_x + (direction.second[0] * j);
				new_y = monster_y + (direction.second[1] * j);
				if (new_x == player_x && new_y == player_y)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void Monster::player_spots()
{
	aim[0] == 1000;
	for (int i = range; i > range - 3; i--)
	{
		if (i > 0)
		{
			for (std::pair <int, std::vector<int>> direction : moves)
			{
				new_x = player_x + (direction.second[0] * i);
				new_y = player_y + (direction.second[1] * i);
				if (check_in_range(new_x, new_y))
				{
					if (battle_field[new_x][new_y][1] == ' ')
					{
						compare_spot();
					}
				}
			}
		}
		else
		{
			break;
		}
	}
}

void Monster::compare_spot()
{
	x_diff = abs(monster_x - new_x);
	y_diff = abs(monster_y - new_y);
	total_diff = x_diff + y_diff;
	if (aim[0] > total_diff)
	{
		aim[0] = total_diff;
		aim[1] = new_x;
		aim[2] = new_y;
	}
}

void Monster::path_to_player_healthy()
{
	aim_x = aim[1];
	aim_y = aim[2];
	route.push({ 0 + abs(aim_x - monster_x) + abs(aim_y - monster_y), monster_x, monster_y });
	for (int i = 0; i < 5; i++)
	{
		for (std::pair <int, std::vector<int>> direction : moves)
		{
			new_x = monster_x + direction.second[0];
			new_y = monster_y + direction.second[1];
			if (check_in_range(new_x, new_y))
			{

			}

		}
	}
}

bool Monster::check_in_range(int x, int y)
{
	if (x > 0 && x < SIZE && y > 0 && y < SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}