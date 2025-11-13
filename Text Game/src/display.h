#pragma once
#include "dungeon_generator.h"
#include "player.h"
#include "dungeon.h"
#include "commands.h"

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
	Command command;

	int choice_int;
	int min;
	int max;
	int x_mod;
	int y_mod;
	bool valid = false;

	std::string statement;
	std::string choice_string;

	std::vector<int> temp;

	//FUNCTONS
	void setup();

	void clear();

	void main_menu();

	void dungeon_move_options();

	bool input_validation(int min, int max, std::string statement, bool valid);

	void inventory(bool valid = false);

	void monster_encounter();
};