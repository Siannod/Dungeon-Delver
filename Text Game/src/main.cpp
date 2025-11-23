#pragma once
#include "display.h"
#include "combat.h"


int main()
{
    Display display;
    display.main_menu(); //runs until player dies
    display.player.player_death();

    return 0;
}