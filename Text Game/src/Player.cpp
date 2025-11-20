#pragma once
#include "player.h"

void Player::level_up()
{
	if (to_level)
	{
		print_stats();
		std::cout << "- Which stat do you want to level up? ";

		range_validation(1, stats.stats.size(), "- Which stat do you want to level up? ");
		stats.level += 1;

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
	for (int i = 0; i < stats.stats.size(); i++)
	{
		std::cout << ">> " << (i + 1) << "- " << stat_names[i] << ": " << stats.stats.at(stat_names[i]) << std::endl;
	}
	if (check_level_up)
	{
		std::cout << ">> Level Up Available! Press Enter to level up." << std::endl;
	}
	else
	{
		std::cout << ">> Press enter to return...";
	}
}

void Player::move(int x_mod, int y_mod)
{
	stats.x = stats.x + x_mod;
	stats.y = stats.y + y_mod;
}

void Player::create_character()
{
	for (int i = 0; i < stats.stats.size(); i++)
	{
		stats.stats.at(stat_names[i]) = 0;
	}
	stats.upgrade_points = 5;
	do
	{
		std::cout << ">> You currently have: " << stats.upgrade_points << " points left." << std::endl;
		std::cout << ">> Your current stats: " << std::endl; 
		for (int i = 0; i < stats.stats.size(); i++)
		{
			std::cout << ">> " << i+1 << ". " << stat_names[i] << ": " << stats.stats.at(stat_names[i]) << std::endl;
		}
		std::cout << "- ";
		range_validation(1, 3, "- ");
		stats.stats.at(stat_names[choice_int - 1]) = stats.stats.at(stat_names[choice_int - 1]) + 1;
		stats.upgrade_points -= 1;
		system("cls");
	} while (stats.upgrade_points > 0);
	for (int i = 0; i < stats.stats.size(); i++)
	{
		std::cout << ">> " << i + 1 << ". " << stat_names[i] << ": " << stats.stats.at(stat_names[i]) << std::endl;
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
	stats.MAX_HEALTH = 5 + (stats.stats.at("Constitution") * 2);
	stats.health = stats.MAX_HEALTH;
	std::cout << ">> Enter your name: " << std::endl;
	std::cout << "- ";
	std::cin >> stats.name;
	system("cls");
}

bool Player::check_level_up()
{
	if (stats.monsters_killed > stats.level * 1.2)
	{
		to_level = true;
		return true;
	}
	return false;
}