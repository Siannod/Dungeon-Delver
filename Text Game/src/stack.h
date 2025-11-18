#pragma once
#include <iostream>
#include <vector>
#include "queue.h"

struct Node
{
	std::vector<QueueSpace::Node> queue;
	std::vector<std::vector<int>> visited;
	int cost;
	int x;
	int y;
	int i;
};


class Stack
{
public:
	std::vector<Node> stack;
	Node temp;
	int top = -1;


	//FUNCTIONS
	void push(Node item);

	Node pop();

	bool is_empty();

	void empty();

	void print_stack();
};