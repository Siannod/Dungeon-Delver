#pragma once
#include "inventory.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>   

class Command
{
public:
	std::vector<std::string> command;
	std::string temp;
	bool go_back = false;

	//FUNCTIONS
	//back-end commands
	void delimit(std::string input);

	void do_command();

	char convert_case(char letter);
	
	//player commands
	void get_help();

	void back();
};