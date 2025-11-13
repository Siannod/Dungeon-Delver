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
	location.push({player_x, player_y});
	player_x = player_x + x_mod;
	player_y = player_y + y_mod;
}

void Player::create_character()
{
	for (int i = 0; i < stats.size(); i++)
	{
		stats.at(stat_names[i]) = 0;
	}
	upgrade_points = 5;
	do
	{
		std::cout << ">> You currently have: " << upgrade_points << " points left." << std::endl;
		std::cout << ">> Your current stats: " << std::endl; 
		for (int i = 0; i < stats.size(); i++)
		{
			std::cout << ">> " << i+1 << ". " << stat_names[i] << ": " << stats.at(stat_names[i]) << std::endl;
		}
		std::cout << "- ";
		range_validation(1, 3, "- ");
		stats.at(stat_names[choice_int - 1]) = stats.at(stat_names[choice_int - 1]) + 1;
		upgrade_points -= 1;
		system("cls");
	} while (upgrade_points > 0);
	for (int i = 0; i < stats.size(); i++)
	{
		std::cout << ">> " << i + 1 << ". " << stat_names[i] << ": " << stats.at(stat_names[i]) << std::endl;
	}
	do
	{
		std::cout << "[?] Are you happy with these stats? (y/n) ";
		std::cin >> choice_string;
		if (choice_string == "y" || choice_string == "Y")
		{
			system("cls");
			valid = true;
		}
		else if (choice_string == "n" || choice_string == "N")
		{
			system("cls");
			create_character();
		}
		else
		{
			std::cout << "[!] INVALID INPUT, PLEASE TRY AGAIN" << std::endl;
		}
	} while (!valid);
}