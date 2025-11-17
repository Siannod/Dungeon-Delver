#pragma once
#include <iostream>
#include <vector>

class Queue
{
public:
	std::vector<std::vector<int>> queue;
	int end = -1;


	//FUNCTIONS
	std::vector<int> remove();

	void add();

	bool is_empty();


};