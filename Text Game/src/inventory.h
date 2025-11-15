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
        int damage;
        int dmg_bonus;
        std::string name;
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

    Inventory()
    {
        choice_int = 1;
    }

    
    std::string command_word;
    std::string choice_string;
    int choice_int;
    int index;

    bool go_back = true;
    bool item_picked = false;

    std::vector<InventorySpace::inventory_slot> inventory;
    std::vector<int> weapon_index;

    std::map <int, InventorySpace::inventory_slot> items =
    {
          //ID TYPE DMG DMG_BONUS NAME
        {0, {0, 0, 0, 0, "Empty"}},
        {1, {1, 1, 8, 0, "Sword"}},
        {2, {2, 1, 6, 0, "Bow"}},
        {3, {3, 2, 0, 0, "Shield"}},
        {4, {4, 3, -2, 0, "Health Potion"}}
    };

    std::map <int, std::string> item_type =
    {
        {0, "Empty"},
        {1, "Weapon"},
        {2, "Ranged Weapon"},
        {3, "Defense"},
        {4, "Potion"}
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