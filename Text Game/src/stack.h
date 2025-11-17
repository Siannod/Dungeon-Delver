#pragma once
#include <iostream>
#include <vector>

struct Node
{
	std::vector<std::vector<int>> queue;
	int cost;
	int x;
	int y;
};
class Stack
{
public:
	std::vector<Node> stack;
	int top = -1;


	//FUNCTIONS
	void push(Node item);

	void pop(std::vector<int> &temp);

	bool is_empty();

	void empty();
};