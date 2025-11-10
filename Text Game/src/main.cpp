#pragma once
#include "display.h"


int main()
{
    Display display;
    display.dungeon.generate();
    display.main_menu();

    return 0;
}