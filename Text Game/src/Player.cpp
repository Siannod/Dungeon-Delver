#pragma once
#include "player.h"

void Player::level_up()
{
	if (to_level)
	{
		std::cout << "What would you like to increase:\n1: Strength\n2: Dexterity\n3: Constituion" << std::endl;
		range_validation(3);
		stats.at(stat_names[choice_int - 1]) += 1;
		std::cout << ">> Increased " << stat_names[choice_int - 1] << "by 1 to " << stats.at(stat_names[choice_int - 1]) << std::endl;
		print_stats();
	}
	else
	{
		std::cout << "[!} You cannot level up at this time." << std::endl;
	}
}

void Player::print_stats()
{
	for (int i = 0; i < stats.size(); i++)
	{
		std::cout << stat_names[i] << ": " << stats.at(stat_names[i]) << std::endl;
	}
}


void Player::range_validation(int max)
{
	valid = false;
	do
	{
		while (!(std::cin >> choice_int))
		{
			std::cout << "[!] Invalid input, input must be number." << std::endl;
		}
		if (0 < choice_int || choice_int < 3)
		{
			valid = true;
		}
		else
		{
			std::cout << "[!] Invalid input, number not in raange." << std::endl;
		}
	} while (!valid);
}

`