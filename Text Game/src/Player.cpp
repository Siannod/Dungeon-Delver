#pragma once
#include "player.h"

void Player::level_up()
{
	//to_level = true;
	if (to_level)
	{
		print_stats();
		std::cout << "- Which stat do you want to level up? ";

		range_validation(1, stats.size(), "- Which stat do you want to level up? ");
	}
	else
	{
		std::cout << "[!] You cannot level up at this time." << std::endl;
	}
}

bool Player::range_validation(int min, int max, std::string statement, bool valid)
{
	while (!valid)
	{
		std::cin >> choice_string;
		try
		{
			choice_int = stoi(choice_string);
			if (min <= choice_int && choice_int <= max)
			{
				return true;
			}
			else
			{
				throw 505;
			}
		}
		catch (...)
		{
			std::cout << "[!] INVALID INPUT" << std::endl;
			std::cout << statement;
		}
	}
}

void Player::print_stats()
{
	std::cout << ">> Current Stats:" << std::endl;
	for (int i = 0; i < stats.size(); i++)
	{
		std::cout << ">> " << (i + 1) << "- " << stat_names[i] << ": " << stats.at(stat_names[i]) << std::endl;
	}
}

void Player::move(int x_mod, int y_mod)
{
	location.push(co_ords);
	player_x = co_ords[0] + x_mod;
	player_y = co_ords[1] + y_mod;
	co_ords = { player_x, player_y};
}