#pragma once

#include "dungeon_generator.h"
#include "player.h"
#include "dungeon.h"


int main()
{
    Player player;
    Dungeon dungeon;

    dungeon.generate();
    dungeon.print_dungeon();
    return 0;
}