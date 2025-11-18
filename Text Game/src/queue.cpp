#pragma once
#include "queue.h"

void Queue::fill_queue()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		queue.push_back(blank_space);
	}
}

void Queue::add(QueueSpace::Node item)
{
	if (is_empty())
	{
		queue.push_back(item);
		end += 1;
	}
	else if (!is_full())
	{
		for (int i = 0; i < end + 1; i++)
		{
			if (i == end)
			{
				queue[end] = item;
				end += 1;
				break;
			}
			else if (item.cost < queue[i].cost)
			{
				queue.insert(queue.begin() + i, item);
				end += 1;
				break;
			}
		}
	}
}

QueueSpace::Node Queue::remove()
{
	if (!is_empty())
	{
		temp = queue[0];
		queue.push_back(blank_space);
		end -= 1;
		return temp;
	}
	else
	{
		return {};
	}
}


bool Queue::is_empty()
{
	if (end == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Queue::is_full()
{
	if (end == MAX_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}