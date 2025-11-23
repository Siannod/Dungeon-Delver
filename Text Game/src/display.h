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
	


public:
	bool running = true;
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
	int chance;

	int int_temp;
	std::string statement;
	std::string choice_string;
	std::string menu_top = "+ - - - - - - - - - - - - - - +";


	std::vector<int> temp;
	InventorySpace::inventory_slot temp_item;

	//FUNCTONS
	//prints
	void print_inventory_menu();

	void combat_menu();

	void print_main_menu();

	void print_dunegon_move_options();

	//others
	void end_of_turn(int type, bool& alive);
	
	void inventory_menu(bool valid = false);

	void clear();

	void wait();

	void main_menu();

	void dungeon_move_options();

	bool input_validation(int min, int max, std::string statement);

	

	void monster_encounter(int type);

	

	void combat_move();

	void combat_fight(int type);

	void print_weapons();

	void print_monster_moves(int type);

	void monster_attack(int type);

	void loot_room();

	bool yes_no_validation(std::string question);

	void new_level();
};