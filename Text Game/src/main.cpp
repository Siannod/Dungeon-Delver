#pragma once

#include "dungeon_generator.h"
#include "player.h"
#include "dungeon.h"
#include "display.h"


int main()
{
    Player player;
    Dungeon dungeon;
    Display display;

    //dungeon.generate();
    //dungeon.print_dungeon();
    display.main_menu();
    //std::cout << "test";
    return 0;
}