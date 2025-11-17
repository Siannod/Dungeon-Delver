#pragma once
#include <iostream>
#include <vector>

class Queue
{
private:
	int MAX_SIZE;
	const std::vector<int> blank_space = { 100, 0 ,0 };
public:
	std::vector<std::vector<int>> queue;
	int end = -1;
	std::vector<int> temp;
	
	Queue(int size)
	{
		MAX_SIZE = size;
		fill_queue();
	}

	//FUNCTIONS
	void fill_queue();

	std::vector<int> remove();

	void add(std::vector<int> item);

	bool is_empty();

	bool is_full();

};

