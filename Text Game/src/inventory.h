#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
    
#include "commands.h"

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
    Inventory()
    {
        
        initialise();
    }
    class Command command;
    std::string command_word;
    std::string choice_string;
    int choice_int;
    int index;

    std::vector<InventorySpace::inventory_slot> inventory;

    std::map <int, InventorySpace::inventory_slot> items =
    {
        {0, {0, 0, 0, 0, "Empty"}},
        {1, {1, 1, 8, 0, "Sword"}},
        {2, {2, 2, 6, 0, "Bow"}},
        {3, {3, 3, 0, 0, "Shield"}},
        {4, {4, 4, 0, 0, "Health Potion"}}
    };

    std::map <int, std::string> item_type =
    {
        {0, "Empty"},
        {1, "Mele Weapon"},
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
};