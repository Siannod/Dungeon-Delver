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