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
	void delimit(std::string input); //splits the input up into a vector

	char convert_case(char letter); //converts a given character into the opposite case
	
	//player commands
	void get_help();
};