#pragma once
#include "display.h"


int main()
{
    Display display;
    //display.dungeon.generate();
    display.setup();
    display.main_menu();

    return 0;
}