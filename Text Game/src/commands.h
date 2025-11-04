#pragma once

#include <iostream>
#include <vector>
#include <string>

class Command
{
public:
	std::vector<std::string> command;
	std::string temp;
	bool rstrt = false;
};