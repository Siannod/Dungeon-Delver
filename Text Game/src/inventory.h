#pragma once
#include "commands.h"
#include "structs.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

#include <conio.h>



class Inventory
{
private:
    int inventory_size = 10;
    int starting_items = 0;
  

public:
    //CLASSES
    Command command;


    //INTS
    int choice_int;
    int index;
    int healing;

    //BOOLS
    bool go_back = false;
    bool item_picked = false;
    bool valid;

    //STRINGS
    std::string command_word;
    std::string choice_string;
   
    //VECTORS
    std::vector<InventorySpace::inventory_slot> inventory;
    std::vector<int> weapon_index;

    //MAPS
    std::map <int, InventorySpace::inventory_slot> items =
    {//SPECIFIC ITEMS
      //ID TYPE DMG_BONUS NAME
        {0, {0, 0, 0, "Empty"}},
        {1, {1, 1, 0, "Sword"}},
        {2, {2, 2, 0, "Bow"}},
        {3, {3, 3, 0, "Shield"}},
        {4, {4, 4, 0, "Health Potion"}}
    };

    std::map <int, InventorySpace::item_type> item_types =
    {//GENERAL ITEM CLASSIFICATIONS
        {0, {"Empty", NULL, NULL}},
        {1, {"Weapon", 1, 8}},
        {2, {"Ranged Weapon", 10, 6}},
        {3, {"Defense", 0, 0}},
        {4, {"Potion", 0 ,0}}
    };

    //FUNCTION
    void initialise(); //sets up the inventory + starting items

    bool input_validation(int min, int max, std::string statement);

    void do_command(PlayerStats &stats); //checks what command has been inputted and calls relevant functions

    void print(); //prints the inventory

    int set(int index, int id); 

    void view();

    void set();

    void back();

    void find_weapons(); //finds all weapons

    bool find_item_of_type(int type); //finds a specific type of item

    void use(PlayerStats &stats); 

    void use_health_potion(PlayerStats& stats);

    int random(int min, int max);
};