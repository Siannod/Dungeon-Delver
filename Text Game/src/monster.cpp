#pragma once
#include "monster.h"

void Monster::create_monster(PlayerStats* player_stats)
{
	int level = (*player_stats).level;
	//HEALTH
	stats.name = "normal";
	stats.MAX_HEALTH = player_stats->MAX_HEALTH + random(3, 10 * (player_stats->level) + player_stats->stats.at("Strength"));
	stats.health = stats.MAX_HEALTH;
	//RANGE
	int temp = random(0, 1);
	if (temp == 0)
	{
		stats.range = 1;
	}
	else
	{
		stats.range = 7;
	}
	//DAMAGE
	if (stats.range == 1)
	{
		stats.damage.push_back(random(3, 6 + player_stats->level));
	}
	else
	{
		stats.damage.push_back(random(2, 4 + player_stats->level));
	}
}

bool Monster::player_in_range(int player_x, int player_y)
{
	diff.x = abs(player_x - monster.x);
	diff.y = abs(player_y - monster.y);
	if ((diff.x <= 2 * stats.range && diff.y == 0) || (diff.x == 0 && diff.y <= 1 * stats.range))
	{
		return true;
	}
	return false;
}

void Monster::next_move(int player_x, int player_y)
{
	aim.cost = 1000;
	for (int i = stats.range; i > stats.range - 3; i--)
	{
		if (i > 0)
		{
			for (std::pair <int, std::vector<int>> direction : moves)
			{
				new_coords.x = player_x + (direction.second[0] * i);
				new_coords.y = player_y + (direction.second[1] * i);
				if (check_in_range_visited(new_coords.x, new_coords.y))
				{
					if (battle_field->at(new_coords.x)[new_coords.y][1] == ' ')
					{
						compare_spot();
					}
				}
			}
		}
		else
		{
			break;
		}
	}
	
}

void Monster::compare_spot()
{
	diff.x = abs(monster.x - new_coords.x);
	diff.y = abs(monster.y - new_coords.y);
	diff.cost = diff.x + diff.y;
	if (aim.cost > diff.cost)
	{
		aim.cost = diff.cost;
		aim.x = new_coords.x;
		aim.y = new_coords.y;
	}
}

void Monster::path_to_player_healthy()
{
	route.empty();
	queue.empty();
	visited.clear();

	start_cost = 0 + abs(aim.x - monster.x) + abs(aim.y - monster.y);

	visited.push_back({ monster.x, monster.y });

	current_node = { queue.queue, visited, start_cost ,monster.x, monster.y, 0 };

	route.push(current_node);

	for (int i = 0; i < stats.MAX_MOVES; i++)
	{
		current_node = route.stack[route.top];
		i = current_node.i;
		queue.queue = current_node.queue;
		visited = current_node.visited;
		check_next_steps(i);
		next_node = queue.remove();
		if (current_node.x == aim.x && current_node.y == aim.y) // get to end
		{
			route.push({ queue.queue, visited, next_node.cost, current_node.x, current_node.y, i + 1 });
			break;
		}
		else if (next_node.cost <= current_node.cost)
		{
			route.push({ queue.queue, visited, next_node.cost, next_node.x, next_node.y, i + 1});
		}
		else
		{
			route.pop();
		}
		
	}
}

bool Monster::check_in_range_visited(int x, int y)
{
	if (x > 0 && x < SIZE && y > 0 && y < SIZE && battle_field->at(x)[y][1] == char(' ')) // in range
	{
		if (visited.size() != 0) //items in visited
		{
			for (std::vector<int> item : visited)
			{
				if (item[0] == x && item[1] == y)
				{
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void Monster::check_next_steps(int i)
{
	for (std::pair <int, std::vector<int>> direction : moves)
	{
		temp.x = current_node.x + direction.second[0];
		temp.y = current_node.y + direction.second[1];
		if (check_in_range_visited(temp.x, temp.y))
		{
			visited.push_back({ temp.x, temp.y });
			temp.cost = abs(aim.x - temp.x) + abs(aim.y - temp.y);
			queue.add({ temp.cost, temp.x, temp.y });
		}
	}
}

int Monster::random(int min, int max)
{
	int temp;
	if (max == 0)
	{
		return 0;
	}
	srand(time(0));
	temp = min + rand() % (max - min);
	return temp;
}

int Monster::calculate_damage()
{
	int damage = random(1, stats.damage[0]);
	return damage;
}

bool Monster::does_hit()
{
	if (random(0, 1))
	{
		return true;
	}
	return false;
}

int Monster::coin_worth(int level)
{
	value = 0;
	//HEALTH
	value = stats.MAX_HEALTH / 2;
	//DAMAGE
	
	//LEVEL
	value += level;
	return value;
}