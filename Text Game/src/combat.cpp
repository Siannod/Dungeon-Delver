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
	battle_field[player.x][player.y][1] = char('X');
	battle_field[(*monster_types[type]).monster.x][(*monster_types[type]).monster.y][1] = char('O');
	//monster.battle_field = battle_field;
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

void Combat::move_player(int choice_int)
{
	moves_left -= 1;
	new_coords.x = player.x + moves.at(options[choice_int - 1])[0];
	new_coords.y = player.y + moves.at(options[choice_int - 1])[1];
	battle_field[player.x][player.y][1] = char(' ');
	battle_field[new_coords.x][new_coords.y][1] = char('X');
	player.x = new_coords.x;
	player.y = new_coords.y;
}

void Combat::check_moves()
{
	options.clear();
	for (std::pair < int, std::vector<int>> direction : moves)
	{
		new_coords.x = player.x + direction.second[0];
		new_coords.y = player.y + direction.second[1];
		if (new_coords.x < FIELD_SIZE && 0 < new_coords.x)
		{
			if (new_coords.y < FIELD_SIZE && 0 < new_coords.y && battle_field[new_coords.x][new_coords.y][2] == char(' '))
			{
				options.push_back(direction.first);
			}
		}
	}
}

bool Combat::able_to_flee(int dex)
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
	for (std::pair<int, std::vector<int>> direction : moves)
	{
		for (int i = 1; i < range + 1; i++)
		{
			new_coords.x = player.x + direction.second[0] * i;
			new_coords.y = player.y + direction.second[1] * i;
			if (in_range(new_coords.x, new_coords.y))
			{
				if (battle_field[new_coords.x][new_coords.y][1] != char(' '))
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
	(monster_types[type])->next_move(player.x, player.y);
	(monster_types[type])->path_to_player_healthy();
	(monster_types[type])->route.reverse_stack();
	(monster_types[type])->route.pop();
}

void Combat::move_monster(int x, int y)
{
	battle_field[(*monster_types[type]).monster.x][(*monster_types[type]).monster.y][1] = char(' ');
	(*monster_types[type]).monster.x = x;
	(*monster_types[type]).monster.y = y;
	battle_field[(*monster_types[type]).monster.x][(*monster_types[type]).monster.y][1] = char('O');
}

int Combat::calculate_damage(struct InventorySpace::inventory_slot weapon)
{
	if (weapon.item_type == 1)
	{
		damage = monster->random(1, inv.item_types[1].damage);
		damage = damage + weapon.dmg_bonus + stats->stats.at("Strength");
		return 100; //DEBUG ONLY
	}
	else
	{
		damage = monster->random(1, inv.item_types[2].damage);
		damage = damage + weapon.dmg_bonus + stats->stats.at("Dexterity");
		return damage;
	}
}

void Combat::flee(bool &flee, int dex)
{
	if (flee)
	{
		flee = false;
		if (able_to_flee(dex))
		{
			system("cls");
			std::cout << ">> You succesfully fled the monster" << std::endl;
			flee = true;
			alive = false;
		}
		else
		{
			std::cout << ">> You were unsuccessful in fleeing the monster, you must stay and fight" << std::endl;
		}
	}
	else
	{
		std::cout << ">> You cannot try to flee again this round, you must stay and fight" << std::endl;
	}
}

bool Combat::in_range(int x, int y)
{
	if (0 < x && x < FIELD_SIZE && 0 < y && y < FIELD_SIZE)
	{
		return true;
	}
	return false;
}

bool Combat::check_monster_alive()
{
	if ((*monster_types[type]).stats.health <= 0)
	{
		return false;
	}
	return true;
}

