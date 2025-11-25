#pragma once
#include "stack.h"

void Stack::push(Node item)
{
	top += 1;
	stack.push_back(item);
}

void Stack::empty()
{
	stack.clear();
	top = -1;
}

Node Stack::pop()
{
	if (is_empty())
	{
		std::cerr << "[!] No previous movements available";
		return {};
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

void Stack::reverse_stack()
{
	while (!is_empty())
	{
		reversed_stack.push_back(pop());
		reversed_top += 1;
	}
	stack = reversed_stack;
	top = reversed_top;
	reversed_stack = {};
	reversed_top = -1;
}