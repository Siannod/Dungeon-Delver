#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>   

class Command
{
public:
	Command()
	{

	}
	std::vector<std::string> command;
	std::string temp;
	bool go_back = false;

	//FUNCTIONS
	//back-end commands
	void delimit(std::string input);


	char convert_case(char letter);
	
	//player commands
	void get_help();
};