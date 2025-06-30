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
        Sleep(15);
    }
}

void delete_text(std::string item){
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
        std::cout << " ";
        key_animation.unlock();
        x++;
    }
}

void delete_item_inventory(int& inventory, std::string inventory_[], std::string item_name){
    for (int i = 0; i < inventory; i++){ // El for llega hasta inventory - 1, que es el ultimo item antes de salirse del array
        if (inventory_[i] == item_name)
        { 
            for (int a = i; a < inventory - 1; a++){ // Cuando encuentra al item, desde el item encontrado copia el siguiente hasta el ulitmo elemento del array 
                inventory_[a] = inventory_[a + 1];
            }
            inventory_[inventory - 1] = ""; // Ya que no se copia nada despues de inventory - 1 lo ponemos como "" para vaciar el slot
            inventory--;
            break;
        }
    }
}

void use_item(std::string item_name, int& health, int& damage){
    std::string initial;
    initial = "You use: " + item_name;
    text(initial);
    char move = getch();
    while (move != '\r')
    {
        move = getch();
    }
    delete_text(initial);
    if (item_name == "Cookie")
    {
        health += 10;
        text("Very tasty! You recovered +10 health! ");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        delete_text("Very tasty! Your recovered +10 health! ");
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