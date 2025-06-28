#ifndef ITEMS_SYSTEM_H
#define ITEMS_SYSTEM_H
#include <iostream>
#include <mmsystem.h>
#include <windows.h>

void use_item(std::string item_name, int& health, int& damage){
    if (item_name == "Cookie")
    {
        health += 10;
        std::cout << "SI FUNCIONOOOOOOO";
        Sleep(1000);
    }
    if (item_name == "Apple")
    {
        health += 5;
    }
    if (item_name == "Knife")
    {
        damage += 5;
    }
    if (item_name == "Cake")
    {
        health += 20;
    }
    if (item_name == "Feeling sucesfully")
    {
    }
}



#endif