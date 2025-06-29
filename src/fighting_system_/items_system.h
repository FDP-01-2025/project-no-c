#ifndef ITEMS_SYSTEM_H
#define ITEMS_SYSTEM_H
#include <iostream>
#include <mmsystem.h>
#include <windows.h>
#include <conio.h>
#include "../inf_window.h"


void text(std::string item){
    int width, height, x, y;
    window_size(width, height);
    x = (14);
    y = (height - 15);
    COORD coord;
    for (int i = 0; i < item.length(); i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << item[i];
        key_animation.unlock();
        x++;
    }
    
}

void use_item(std::string item_name, int& health, int& damage){

    std::cout << " You use: " << item_name;
    Sleep(1000);
    char move = getch();
    while (move != '\r')
    {
        move = getch();
    }
    if (item_name == "Cookie")
    {
        health += 10;
        text("Very tasty! You recovered +10 health! ");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        
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