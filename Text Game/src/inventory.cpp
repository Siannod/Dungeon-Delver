#pragma once
#include "inventory.h"


void Inventory::initialise()
{
    
    for (int i = 0; i < inventory_size; i++)
    {
        inventory.push_back({i, 0});
    }
}

void Inventory::print()
{
    for (int i = 0; i < inventory_size; i++)
    {
        std::cout << ">> " << i << ": " << items[inventory[i].item_id] << "\n";
    }
}

int Inventory::set(int index, int id)
{
    inventory[index].item_id = id;
    return 0;
}