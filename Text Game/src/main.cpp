#pragma once

#include "dungeon_generator.h"
#include "player.h"


int main()
{
    Generator generator;
    Player player;

    generator.generate();
    generator.print_dungeon();
    //player.inventory.initialise();
    //player.inventory.set(0, 1);
    //player.inventory.print();
   
    return 0;
}