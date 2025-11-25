#pragma once
#include "player.h"

void Player::level_up() 
{
	do
	{
		print_stats();
		std::cout << "- Which stat do you want to level up? ";

		range_validation(1, stats.stats.size(), "- Which stat do you want to level up? ");
		stats.level += 1;
		stat_name = stat_names[choice_int - 1];
		std::cout << ">> You wish to increase " << stat_name << " from " << stats.stats.at(stat_name) << " to " << stats.stats.at(stat_name) + 1 << "? (y/n) ";
		std::cin >> choice_string;
		if (choice_string == "y")
		{
			stats.stats.at(stat_name) += 1;
			to_level = false;
		}
		else if (choice_string == "n")
		{
			system("cls");
		}
		else
		{
			std::cout << "[!] Invalid Input, try again." << std::endl;
			_getch();
		}
	} while (to_level);
	stats.MAX_HEALTH = calculate_max_health();
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

void Player::print_stats_menu()
{
	std::cout << ">> Current Stats:" << std::endl;
	print_stats();
	if (check_level_up())
	{
		std::cout << ">> Level Up Available! Press Enter to level up." << std::endl;
	}
	else
	{
		std::cout << ">> Press enter to return...";
	}
}

void Player::print_stats()
{
	for (int i = 0; i < stats.stats.size(); i++)
	{
		std::cout << ">> " << (i + 1) << " - " << stat_names[i] << ": " << stats.stats.at(stat_names[i]) << std::endl;
	}
}

void Player::move(int x_mod, int y_mod)
{
	stats.x = stats.x + x_mod;
	stats.y = stats.y + y_mod;
}

void Player::create_character()
{
	for (int i = 0; i < stats.stats.size(); i++) //sets all stats to 0
	{
		stats.stats.at(stat_names[i]) = 0;
	}
	stats.upgrade_points = 5;
	do //player picks which stats they want to increase
	{
		std::cout << ">> You currently have: " << stats.upgrade_points << " points left." << std::endl;
		std::cout << ">> Your current stats: " << std::endl; 
		print_stats();
		std::cout << "- ";
		range_validation(1, 3, "- ");
		stats.stats.at(stat_names[choice_int - 1]) = stats.stats.at(stat_names[choice_int - 1]) + 1;
		stats.upgrade_points -= 1;
		system("cls");
	} while (stats.upgrade_points > 0);
	print_stats();
	do //checks player is happy with stats
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
	stats.level = 1;
	stats.MAX_HEALTH = calculate_max_health(); //calculates player max health
	stats.health = stats.MAX_HEALTH;
	std::cout << ">> Enter your name: " << std::endl; //takes player name
	std::cout << "- ";
	std::cin >> stats.name;
	
	system("cls");
}

bool Player::check_level_up()
{
	if (stats.monsters_killed >= (stats.level * 1.2))
	{
		to_level = true;
		return true;
	}
	return false;
}

void Player::player_death()
{
	system("cls");
	std::cout << ">> You died." << std::endl;
	std::cout << ">> Your final stats were as follows: " << std::endl;
	std::cout << ">> Level: " << stats.level << std::endl;
	std::cout << ">> Monsters Killed: " << stats.monsters_killed << std::endl;
	std::cout << ">> Coins: " << stats.coin << std::endl;
	std::cout << ">> Stats: " << std::endl;
	print_stats();
}

int Player::calculate_max_health()
{
	return 5 + (stats.stats.at("Constitution") * 2) + (stats.level * 2);
}