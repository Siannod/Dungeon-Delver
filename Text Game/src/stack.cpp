#pragma once
#include "stack.h"

void Stack::push(std::vector<int> item)
{
	top += 1;
	stack.push_back(item);
}

void Stack::pop(std::vector<int> &temp)
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