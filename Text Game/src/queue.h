#pragma once
#include <iostream>
#include <vector>
namespace QueueSpace
{
	struct Node
	{
		int cost;
		int x;
		int y;
	};
};

class Queue
{
private:
	int MAX_SIZE;
	const QueueSpace::Node blank_space = { 100, 0 ,0 };
public:
	std::vector<QueueSpace::Node> queue;
	int end = -1;
	QueueSpace::Node temp;
	
	Queue(int size)
	{
		MAX_SIZE = size;
		fill_queue();
	}

	//FUNCTIONS
	void fill_queue();

	QueueSpace::Node remove();

	void add(QueueSpace::Node item);

	bool is_empty();

	bool is_full();

	void empty();
};

