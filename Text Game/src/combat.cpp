#pragma once
#include "combat.h"


void Combat::fill_field()
{
	for (int i = 0; i < 21; i++)
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
		for (int j = 0; j < 10; j++)
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