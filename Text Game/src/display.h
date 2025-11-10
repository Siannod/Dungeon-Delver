#pragma once
#include "dungeon_generator.h"
#include "player.h"
#include "dungeon.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

class Display
{
private:
	


public:
	Player player;
	Dungeon dungeon;
	int choice_int;
	int min;
	int max;
	bool valid = false;

	std::string statement;
	std::string choice_string;

	std::vector<int> temp;

	//FUNCTONS
	void clear();

	void main_menu();

	void move_options();

	bool input_validation(int min, int max, std::string statement, bool valid);

};