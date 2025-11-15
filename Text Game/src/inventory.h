#pragma once
#include "commands.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
    


namespace InventorySpace
{
    struct inventory_slot
    {
        int item_id;
        int item_type;
        int dmg_bonus;
        std::string name;
    };

    struct item_type
    {
        std::string name;
        int range;
        int damage;
    };
};

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

    std::map <int, InventorySpace::item_type> item_type =
    {
        {0, {"Empty", NULL, NULL}},
        {1, {"Weapon", 1, 8}},
        {2, {"Ranged Weapon", 10, 6}},
        {3, {"Defense", 0, 0}},
        {4, {"Potion", 0 ,0}}
    };

    //FUNCTION
    void initialise();

    bool input_validation(int min, int max, std::string statement, bool valid = false);

    void do_command();

    void print();

    int set(int index, int id);

    void view();

    void set();

    void back();

    void find_weapons();

};