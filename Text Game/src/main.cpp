#pragma once

#include "dungeon_generator.h"

int main()
{
    Generator generator;
    generator.fill_dungeon();
    generator.generate_2();
    generator.print_dungeon();
}