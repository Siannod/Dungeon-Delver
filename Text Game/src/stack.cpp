#pragma once
#include "stack.h"

void Stack::push(Node item)
{
	top += 1;
	stack.push_back(item);
}

Node Stack::pop()
{
	if (is_empty())
	{
		std::cerr << "[!] No previous movements available";
	}
	else
	{
		temp = stack[top];
		stack.pop_back();
		top -= 1;
		return temp;
	}
}

bool Stack::is_empty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::print_stack()
{
	for (Node item : stack)
	{
		std::cout << "+=-=-=-=-=+" << std::endl;
		std::cout << "Cost: " << item.cost << std::endl;
		std::cout << "Queue: #" << std::endl;
		std::cout << "Visited: #" << std::endl;
		std::cout << "X: " << item.x << std::endl;
		std::cout << "Y: " << item.y << std::endl;
		std::cout << "i: " << item.i << std::endl;
		std::cout << "\n";
	}
}