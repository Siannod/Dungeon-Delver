#pragma once
#include "inventory.h"


void Inventory::initialise()
{
    for (int i = 0; i < inventory_size; i++)
    {
        inventory.push_back(items.at(0));
    }
    do
    {
        std::cout << ">> You get " << 2 - starting_items << " starting items from the following: " << std::endl;
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
        std::cout << ">> " << i << ": " << inventory[i].name << "\n";
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