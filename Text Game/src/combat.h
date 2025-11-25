#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>


#include "player.h"
#include "monster.h"
#include "boss_monster.h"
#include "inventory.h"



class Combat
{
public:
	Inventory inv;
	const int FIELD_SIZE = 11;
	PlayerStats* stats;
	Combat(PlayerStats* stats_ptr)
	{
		fill_field();
		stats = stats_ptr;
	}
	std::map <std::string, std::string> field_pieces =
	{
		{"top_first" , "+-=-+"},
		{"mid_first", "|"},
		{"top_rest", "-=-+"},
		{"mid_rest", "   |"}
	};

	std::vector<std::string> field_rows = { "|", " ", " ", "|" };

	std::vector<std::vector<std::string>> battle_field;

	std::vector<std::vector<std::string>>* field_ptr = &battle_field;

	std::map <int, std::vector<int>> moves =
	{
		{1, {-2, 0}},
		{2, {0, 1}},
		{3, {2, 0}},
		{4, {0, -1}}
	};

	std::vector<int> options;

	std::string start;
	std::string end;

	coords player = { 1, 1, 0 };
	coords new_coords;
	coords diff;

	

	bool alive;

	int moves_left = 5;
	bool action_left = true;
	
	int temp;
	int damage;

	int* x_ptr = &player.x;
	int* y_ptr = &player.y;

	

	Node next_step;

	Monster* monster = new Monster(stats, FIELD_SIZE, field_ptr);
	BossMonster* boss_monster = new BossMonster(stats, FIELD_SIZE, field_ptr);
	std::vector<Monster*> monster_types = { monster, boss_monster};
	int type;
	//Monster monster_;
	//FUNCTIONS
	void fill_field(); //CREATES THE FIELD

	void print_field(); //PRINTS THE FIELD

	void move_player(int choice_int); //MOVES THE PLAYER

	void move_monster(int x, int y); 

	void check_moves(); //CHECKS WHICH MOVES ARE FREE FOR THE PLAYER

	bool able_to_flee(int dex); //CHECKS IF THE PLAYER IS ABLE TO FLEE THE FIGHT

	int random(int min, int max);

	bool check_for_enemy(int range); //CHECKS IF AN ENEMY IS WITHIN RANGE

	void monster_turn();

	int calculate_damage(struct InventorySpace::inventory_slot weapon); //CALCULATES HOW MUCH DAMAGE THE PLAYER DOES

	void flee(bool &flee, int dex);

	bool in_range(int x, int y);

	bool check_monster_alive();

	bool check_player_alive(int health);
};