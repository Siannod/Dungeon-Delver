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

void Monster::path_to_player()
{
	aim.clear();

}