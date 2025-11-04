#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace InventorySpace
{
    struct inventory_slot
    {
        int slot;
        int item_id;
    };
};

class Inventory
{
private:
    int inventory_size = 10;

public:

    InventorySpace::inventory_slot inventory[10];

    std::map <int, std::string> items =
    {
        {0, "Empty"},
        {1, "Sword"},
        {2, "Shield"},
        {3, "Healing Potion"}
    };

    


    
    //FUNCTION
    void initialise();

    void print();

    int set(int index, int id);
};