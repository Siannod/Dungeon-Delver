#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

//ALL STRUCTS USED IN PROGRAM SO ALL FILES CAN READ
namespace InventorySpace
{
    struct inventory_slot
    {
        int item_id;
        int item_type;
        int dmg_bonus;
        std::string name;
    };

    struct item_type
    {
        std::string name;
        int range;
        int damage;
    };
};

struct coords
{
    int x;
    int y;
    int cost;
};

struct MovementDirections
{
    int dirNum;
    bool available;
};

struct MonsterStats
{
    std::string name;
    int MAX_HEALTH;
    int health;
    int range;
    std::vector<int> damage;
    int bonus;
    int moves_left = 5;
    int MAX_MOVES = 5;
};

struct PlayerStats
{
    int x = 1;
    int y = 1;
    int MAX_HEALTH;
    int health = MAX_HEALTH;
    int level;
    int coin;
    int upgrade_points;
    int monsters_killed;
    std::string name;
    std::map <std::string, int> stats =
    {
        {"Strength", 0},
        {"Dexterity", 0},
        {"Constitution", 0}
    };
};