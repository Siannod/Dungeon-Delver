#pragma once
#include "monster.h"

bool Monster::player_in_range()
{
	for (std::pair<int, std::vector<int >> direction : moves)
	{
		for (int j = 0; j <= range; j++)
		{
			if (j != 0)
			{
				new_x = monster_x + (direction.second[0] * j);
				new_y = monster_y + (direction.second[1] * j);
				if (new_x == *player_x && new_y == *player_y)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void Monster::next_move()
{
	aim[0] = 1000;
	for (int i = range; i > range - 3; i--)
	{
		if (i > 0)
		{
			for (std::pair <int, std::vector<int>> direction : moves)
			{
				new_x = *player_x + (direction.second[0] * i);
				new_y = *player_y + (direction.second[1] * i);
				if (check_in_range_visited(new_x, new_y))
				{
					if (battle_field->at(new_x)[new_y][1] == ' ')
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
	x_diff = abs(monster_x - new_x);
	y_diff = abs(monster_y - new_y);
	total_diff = x_diff + y_diff;
	if (aim[0] > total_diff)
	{
		aim[0] = total_diff;
		aim[1] = new_x;
		aim[2] = new_y;
	}
}

void Monster::path_to_player_healthy()
{
	route.empty();
	queue.empty();
	visited.clear();
	aim_x = aim[1];
	aim_y = aim[2];

	start_cost = 0 + abs(aim_x - monster_x) + abs(aim_y - monster_y);

	visited.push_back({ monster_x, monster_y });

	current_node = { queue.queue, visited, start_cost ,monster_x, monster_y, 0 };

	route.push(current_node);

	for (int i = 0; i < 5; i++)
	{
		current_node = route.stack[route.top];
		i = current_node.i;
		queue.queue = current_node.queue;
		visited = current_node.visited;
		check_next_steps(i);
		next_node = queue.remove();
		if (current_node.x == aim_x && current_node.y == aim_y) // get to end
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
	std::cout << ";";
}

bool Monster::check_in_range_visited(int x, int y)
{
	if (x > 0 && x < SIZE && y > 0 && y < SIZE) // in range
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
		temp_x = current_node.x + direction.second[0];
		temp_y = current_node.y + direction.second[1];
		if (check_in_range_visited(temp_x, temp_y))
		{
			visited.push_back({ temp_x, temp_y });
			temp_cost = abs(aim_x - temp_x) + abs(aim_y - temp_y);
			queue.add({ temp_cost, temp_x, temp_y });
		}
	}
}