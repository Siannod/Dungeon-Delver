#pragma once
#include <iostream>
#include <vector>

class Stack
{
public:
	std::vector<std::vector<int>> stack;
	int top = -1;


	//FUNCTIONS
	void push(std::vector<int> item);

	void pop(std::vector<int> &temp);

	bool is_empty();

	void empty();
};