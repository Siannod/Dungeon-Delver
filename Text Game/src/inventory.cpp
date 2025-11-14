#pragma once
#include "inventory.h"


void Inventory::initialise()
{
    //Command command;
    for (int i = 0; i < inventory_size; i++)
    {
        inventory.push_back({i, 0});
    }
    do
    {
        std::cout << ">> You get " << starting_items << "starting items from the following: " << std::endl;
        for (std::pair<int, InventorySpace::inventory_slot> item : items)
        {
            if (item.first == 0 || item.first == choice_int)
            {
                continue;
            }
            std::cout << ">> " << item.first << ". " << item.second.name << std::endl;
        }
        std::cout << "- ";
        input_validation(1, 4, "- ");
        inventory[starting_items].item_id = choice_int;
        inventory[starting_items].dmg_bonus = 0;

    } while (starting_items < 2);

}

bool Inventory::input_validation(int min, int max, std::string statement, bool valid)
{
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
        std::cout << ">> " << i << ": " << items.at(inventory[i].item_id).name << "\n";
    }
}

int Inventory::set(int index, int id)
{
    inventory[index].item_id = id;
    return 0;
}

void Inventory::view()
{
    index = stoi(command.command[1]);
    std::cout << ">> Inventory slot " << index << " details:\n>> Name: " << inventory[index].name;
}

void Inventory::set()
{
    inventory[std::stoi(command.command[1])].item_id = 0;
}