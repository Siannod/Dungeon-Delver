#pragma once
#include "dungeon_generator.h"
#include "player.h"
#include "dungeon.h"
#include "inventory.h"
#include "combat.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>


class Display
{
private:
	bool running = true;


public:
	Player player = Player(true);
	Dungeon dungeon;
	Combat combat = Combat(player.stats_ptr);

	int choice_int;
	int min;
	int max;
	int x_mod;
	int y_mod;
	bool valid = false;
	int count;
	int index;
	int bonus;

	int int_temp;
	std::string statement;
	std::string choice_string;
	std::string menu_top = "+ - - - - - - - - - - - - - - +";


	std::vector<int> temp;
	InventorySpace::inventory_slot temp_item;

	//FUNCTONS
	void clear();

	void wait();

	void main_menu();

	void dungeon_move_options();

	bool input_validation(int min, int max, std::string statement);

	void print_inventory(bool valid = false);

	void monster_encounter();

	void combat_menu();

	void combat_move();

	void combat_fight();

	void print_weapons();

	void print_monster_moves();

	void monster_attack();

	void loot_room();

	bool yes_no_validation(std::string question);

	void boss_encounter();
};