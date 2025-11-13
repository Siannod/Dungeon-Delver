#pragma once
#include "inventory.h"


void Inventory::initialise()
{
    
    for (int i = 0; i < inventory_size; i++)
    {
        inventory.push_back({i, 0});
    }
    std::cout << ">> You get two starting items from the following: " << std::endl;
    for (std::pair<int, std::string> item : items)
    {
        if (item.first == 0)
        {
            continue;
        }
        std::cout << ">> " << item.first << ". " << item.second << std::endl;
    }
}

void Inventory::do_command()
{
    command_word = command.command[0];
    if (command.command.empty()) { std::cout << "[!] EMPTY COMMAND, TRY AGAIN.\n"; }
    else if (command_word == "help") { command.get_help(); }
    else if (command_word == "view") { view(); }
    else if (command_word == "drop") { set(); }
    else if (command_word == "back") { back(); }
    else { std::cout << "[!] INVALID COMMAND INPUT, TRY AGAIN\n"; }
    std::cout << "\n";
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

void Inventory::view()
{
    std::cout << ">> Inventory slot " << inventory[std::stoi(command.command[1])].slot << " details:\n>> Name: " << items[inventory[std::stoi(command.command[1])].item_id];
}

void Inventory::set()
{
    inventory[std::stoi(command.command[1])].item_id = 0;
}