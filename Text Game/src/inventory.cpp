#pragma once
#include "inventory.h"


void Inventory::initialise()
{
    starting_items = 0;
    choice_int = 0;
    for (int i = 0; i < inventory_size; i++)
    {
        inventory.push_back(items.at(0));
    }
    do
    {
        std::cout << ">> You get " << 2 - starting_items << " starting items from the following: " << std::endl;
        for (std::pair<int, InventorySpace::inventory_slot> item : items)
        {
            if (item.first == 0 || item.second.item_id == inventory[0].item_id)
            {
                continue;
            }
            std::cout << ">> " << item.first << ". " << item.second.name << std::endl;
        }
        std::cout << "- ";
        input_validation(1, 4, "- ");
        inventory[starting_items] = items.at(choice_int);
        starting_items += 1;
    } while (starting_items < 2);
    system("cls");
    print();
    do
    {
        std::cout << "Are you happy with your starting items? (y/n) ";
        std::cin >> choice_string;
        if (choice_string == "y" || choice_string == "Y")
        {
            system("cls");
            item_picked = true;
        }
        else if (choice_string == "n" || choice_string == "N")
        {
            system("cls");
            inventory.clear();
            initialise();
        }
        else
        {
            std::cout << "[!] INVALID INPUT, PLEASE TRY AGAIN" << std::endl;
        }
    } while (!item_picked);

}

bool Inventory::input_validation(int min, int max, std::string statement)
{
    valid = false;
    while (!valid)
    {
        std::cin >> choice_string;
        try
        {
            choice_int = stoi(choice_string);
            if (min <= choice_int && choice_int <= max)
            {
                return true;
            }
            else
            {
                throw 505;
            }
        }
        catch (...)
        {
            std::cout << "[!] INVALID INPUT" << std::endl;
            std::cout << statement;
        }
    }
}

void Inventory::do_command(PlayerStats &stats)
{
    command_word = command.command[0];
    if (command.command.empty()) { std::cout << "[!] EMPTY COMMAND, TRY AGAIN.\n"; }
    else if (command_word == "help") { command.get_help(); _getch(); }
    else if (command_word == "view") { view(); _getch();}
    else if (command_word == "drop") { set(); _getch();}
    else if (command_word == "back") { back(); }
    else if (command_word == "use") { use(stats); _getch();}
    else { std::cout << "[!] INVALID COMMAND INPUT, TRY AGAIN\n"; }
    std::cout << "\n";
}

void Inventory::print()
{
    for (int i = 0; i < inventory_size; i++)
    {
        std::cout << ">> " << i << ": " << inventory[i].name << "\n";
    }
}

int Inventory::set(int index, int id)
{
    inventory[index] = items[id];
    return 0;
}

void Inventory::view()
{
    index = stoi(command.command[1]);
    std::cout << ">> Inventory slot " << index << " details:" << std::endl;
    std::cout << ">> Name: " << inventory[index].name << std::endl;
    std::cout << ">> Damage: 1 - " << item_types.at(inventory[index].item_type).damage << std::endl;
    std::cout << ">> Range: " << item_types.at(inventory[index].item_type).range << std::endl;
}

void Inventory::set()
{
    inventory[std::stoi(command.command[1])].item_id = 0;
}

void Inventory::back()
{
    go_back = true;
}

void Inventory::find_weapons()
{
    weapon_index.clear();

    for (int i = 0; i < inventory_size; i++)
    {   
        if (inventory[i].item_type == 1 || inventory[i].item_type == 2)
        {
            weapon_index.push_back(i);
        }
    }
}

bool Inventory::find_item_of_type(int type)
{
    index = 0;
    for (InventorySpace::inventory_slot item : inventory)
    {
        if (item.item_type == type)
        {
            return true;
        }
        index += 1;
    }
    return false;
}

void Inventory::use(PlayerStats &stats)
{
    if (command.command[1] == "health_potion") 
    { 
        if (find_item_of_type(4))
        {
            use_health_potion(stats);
        }
    }
    else
    {
        std::cout << "[!] NO ITEM FOUND THAT CAN BE USED" << std::endl;
    }
}

void Inventory::use_health_potion(PlayerStats& stats)
{
    valid = false;
    do
    {
        if (stats.health == stats.MAX_HEALTH)
        {
            std::cout << ">> Health is already at max." << std::endl;
            valid = true;
        }
        else
        {
            healing = stats.level + random(2, 8);
            if (healing + stats.health <= stats.MAX_HEALTH)
            {
                set(index, 0);
                valid = true;
            }
        }
    } while (!valid);
    stats.health += healing;
}



int Inventory::random(int min, int max)
{
    int temp;
    if (max == 0)
    {
        return 0;
    }
    srand(time(0));
    temp = min + rand() % (max - min);
    return temp;
}