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
        int slot;
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

public:
    Inventory()
    {
        initialise();
    }
    Command command;
    std::string command_word;

    std::vector<InventorySpace::inventory_slot> inventory;

    std::map <int, std::string> items =
    {
        {0, "Empty"},
        {1, "Sword"},
        {2, "Bow"},
        {3, "Shield"},
        {4, "Healing Potion"}
    };

    //FUNCTION
    void initialise();

    void do_command();

    void print();

    int set(int index, int id);

    void view();

    void set();

    void back();
};