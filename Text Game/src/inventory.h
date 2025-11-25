#pragma once
#include "commands.h"
#include "structs.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <conio.h>



class Inventory
{
private:
    int inventory_size = 10;
    int starting_items = 0;
  

public:
    Command command;
    Inventory(bool run)
    {
        initialise();
    }
    Inventory()
    {

    }
    std::string command_word;
    std::string choice_string;
    int choice_int;
    int index;

    bool go_back = false;
    bool item_picked = false;

    std::vector<InventorySpace::inventory_slot> inventory;
    std::vector<int> weapon_index;

    std::map <int, InventorySpace::inventory_slot> items =
    {
      //ID TYPE DMG_BONUS NAME
        {0, {0, 0, 0, "Empty"}},
        {1, {1, 1, 0, "Sword"}},
        {2, {2, 2, 0, "Bow"}},
        {3, {3, 3, 0, "Shield"}},
        {4, {4, 4, 0, "Health Potion"}}
    };

    std::map <int, InventorySpace::item_type> item_types =
    {
        {0, {"Empty", NULL, NULL}},
        {1, {"Weapon", 1, 8}},
        {2, {"Ranged Weapon", 10, 6}},
        {3, {"Defense", 0, 0}},
        {4, {"Potion", 0 ,0}}
    };

    int healing;
    bool valid;

    //FUNCTION
    void initialise();

    bool input_validation(int min, int max, std::string statement);

    void do_command(PlayerStats &stats);

    void print();

    int set(int index, int id);

    void view();

    void set();

    void back();

    void find_weapons();

    bool find_item_of_type(int type);

    void use(PlayerStats &stats);

    void use_health_potion(PlayerStats& stats);

    int random(int min, int max);
};