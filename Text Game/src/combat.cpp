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
	battle_field[monster.monster.x][monster.monster.y][1] = char('O');
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

void Combat::move_player()
{
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
	for (std::pair<int, std::vector<int>> direction : moves)
	{
		new_coords.x = player.x + direction.second[0];
		new_coords.y = player.y + direction.second[1];
		if (battle_field[new_coords.x][new_coords.y][1] != char(' '))
		{
			return true;
		}
	}
	return false;
}

void Combat::monster_turn()
{
	monster.next_move(player.x, player.y);
	monster.path_to_player_healthy();
	monster.route.reverse_stack();
	monster.route.pop();
}

void Combat::move_monster(int x, int y)
{
	battle_field[monster.monster.x][monster.monster.y][1] = char(' ');
	monster.monster.x = x;
	monster.monster.y = y;
	battle_field[monster.monster.x][monster.monster.y][1] = char('O');
}

int Combat::calculate_damage(struct InventorySpace::inventory_slot weapon)
{
	int damage;
	if (weapon.item_type == 1)
	{
		damage = monster.random(1, inv.item_types[1].damage);
		damage = damage + weapon.dmg_bonus + stats->stats.at("Strength");
		return damage;
	}
	else
	{
		damage = monster.random(1, inv.item_types[2].damage);
		damage = damage + weapon.dmg_bonus + stats->stats.at("Dexterity");
		return damage;
	}
}