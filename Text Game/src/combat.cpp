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
			else
			{
				end = "rest";
			}
			battle_field[i].push_back(field_pieces.at(start + end));
		}
	}
	battle_field[player_x][player_y][2] = char('X');
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
	if (player_y == 0) 
	{
		battle_field[player_x][player_y][2] = char(' ');
	}
	else
	{
		battle_field[player_x][player_y][1] = char(' ');
	}
	if (new_y == 0)
	{
		battle_field[new_x][new_y][2] = char('X');
	}
	else
	{
		battle_field[new_x][new_y][1] = char('X');
	}
	player_x = new_x;
	player_y = new_y;
}

void Combat::check_moves()
{
	options.clear();
	for (int i = 1; i < 5; i++)
	{
		new_x = player_x + moves[i].at(0);
		new_y = player_y + moves[i].at(1);
		if (new_x < FIELD_SIZE && -1 < new_x)
		{
			if (new_y < FIELD_SIZE && -1 < new_y && battle_field[new_x][new_y][2] == char(' '))
			{
				options.push_back(i);
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

void Combat::fight()
{
	player.inventory.find_weapons();
	system("cls");
	temp = 0;
	for (int item : player.inventory.weapon_index)
	{
		std::cout << ">> " << temp << ". " << player.inventory.inventory[item].name << std::endl;
		temp += 1;
	}
	std::cin >> temp;
}