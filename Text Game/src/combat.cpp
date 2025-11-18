#pragma once
#include "combat.h"


void Combat::fill_field()
{
	for (int i = 0; i < (FIELD_SIZE*2)+1; i++)
	{
		battle_field.push_back({});
		if (i % 2 == 0)
		{
			start = "top_";
		}
		else
		{
			start = "mid_";
		}
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			if (j == 0)
			{
				end = "first";
			}
			else if (j == FIELD_SIZE - 1 && start == "top_")
			{
				continue;
			}
			else
			{
				end = "rest";
			}
			battle_field[i].push_back(field_pieces.at(start + end));
		}
	}
	battle_field[player_x][player_y][1] = char('X');
	battle_field[monster.monster_x][monster.monster_y][1] = char('O');
}

void Combat::print_field()
{
	for (auto grid : battle_field)
	{
		for (auto piece : grid)
		{
			std::cout << piece;
		}
		std::cout << "\n";
	}
}

void Combat::move_player()
{
	battle_field[player_x][player_y][1] = char(' ');
	battle_field[new_x][new_y][1] = char('X');
	player_x = new_x;
	player_y = new_y;
}

void Combat::check_moves()
{
	options.clear();
	for (std::pair < int, std::vector<int>> direction : moves)
	{
		new_x = player_x + direction.second[0];
		new_y = player_y + direction.second[1];
		if (new_x < FIELD_SIZE && 0 < new_x)
		{
			if (new_y < FIELD_SIZE && 0 < new_y && battle_field[new_x][new_y][2] == char(' '))
			{
				options.push_back(direction.first);
			}
		}
	}
}

bool Combat::flee(int dex)
{
	temp = random(1, 6);
	if (temp + dex > 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Combat::random(int min, int max)
{
	if (max == 0)
	{
		return 0;
	}
	srand(time(0));
	temp = min + rand() % (max - min);
	return temp;
}

bool Combat::check_for_enemy(int range)
{
	for (std::pair<int, std::vector<int >> direction : moves) //check every direction
	{
		for (int j = 0; j <= range; j++)
		{
			if (j != 0)
			{
				new_x = player_x + (direction.second[0] * j);
				new_y = player_y + (direction.second[1] * j);
				if (battle_field[new_x][new_y][2] != char(' '))
				{
					return true;
				}
			}
		}
	}
	return false;
}

void Combat::monster_turn()
{
	monster.next_move();
	monster.path_to_player_healthy();
	monster.route.print_stack();
	std::cout << "test";
}
