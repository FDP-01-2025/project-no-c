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

void use_item(std::string item_name, int& health, int max_health, int& damage, int& id){
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
        health += 20;
        if (health > max_health){
        health = max_health;
        }
        text("You feel the Cookie power! You recovered +20 health! ");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        delete_text("You feel the Cookie power! You recovered +20 health! ");
    }
    if (item_name == "Apple")
    {
        health += 10;
        if (health > max_health){
        health = max_health;
        }
        text("Healthy! You recovered +10 health! ");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        delete_text("You feel the Cookie power! You recovered +10 health! ");
    }
    if (item_name == "Knife")
    {
        damage += 5;
        text("You feel bad... +5 damage");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        delete_text("You feel bad... +5 damage");
    }
    if (item_name == "Cake")
    {
        if (health > max_health){
        health = max_health;
        }
        health += 30;
        text("You enjoy the cake! +30 health");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        delete_text("You enjoy the cake! +30 health");
    }
    if (item_name == "Feeling sucesfully" && id == 11)
    {
        damage += 999;
        health += 999;
        text("Your aura changed +100000 aura");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        delete_text("Your aura changed +100000 aura");
        PlaySound(NULL,0,0);
        PlaySound(TEXT("assets//music//Feeling-sucesfully-JAJAJAJ.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        Sleep(1000);
        text("Now you are sucesfully!");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        delete_text("Now you are sucesfully!");
    }
    else if (item_name == "Feeling sucesfully" && id != 11){
        text("You can't use this items yet");
        move = getch();
        while (move != '\r')
        {
            move = getch();
        }
        delete_text("You can't use this items yet");
    }
    
}



#endif