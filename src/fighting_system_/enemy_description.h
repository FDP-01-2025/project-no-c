#ifndef ENEMY_DESCRIPTION_H
#define ENEMY_DESCRIPTION_H
#include <iostream>
#include <windows.h>
#include "../inf_window.h"
#include <conio.h>

void delete_show_enemy_description(int& e_health, int& e_damage, std::string e_name, std::string e_description2){
    int width, height, x, y;
    window_size(width, height);
    x = 14;
    y = (height - 15);
    COORD coord;    
    std::string enemy_name_description;
    enemy_name_description = "The enemy is: " + e_name;
    for (int i = 0; i < enemy_name_description.length(); i++)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        x++;
    }

    x = 14;
    y += 2;
    std::string enemy_health_description;
    enemy_health_description = "Enemy's health is: "; 

    for (int i = 0; i < enemy_health_description.length(); i++)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        x++;
    }
    std::cout << "    ";
    x = 14;
    y += 2;
    std::string enemy_damage_description;
    enemy_damage_description = "Enemy's damage is: ";

    for (int i = 0; i < enemy_damage_description.length(); i++)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        x++;
    }
    std::cout << "    ";  
    x = 40;
    y = (height - 15);
    for (int i = 0; i < e_description2.length(); i++)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        x++;
    }
}

void show_enemy_description(int& e_health, int& e_damage, std::string e_name, std::string e_description2){
    int width, height, x, y;
    window_size(width, height);
    x = 14;
    y = (height - 15);
    COORD coord;    
    std::string enemy_name_description;
    enemy_name_description = "The enemy is: " + e_name;
    for (int i = 0; i < enemy_name_description.length(); i++)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << enemy_name_description[i];
        Sleep(15);
        x++;
    }

    x = 14;
    y += 2;
    std::string enemy_health_description;
    enemy_health_description = "Enemy's health is: "; 

    for (int i = 0; i < enemy_health_description.length(); i++)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << enemy_health_description[i];
        x++;
        Sleep(15);   
    }
    std::cout << e_health;
    x = 14;
    y += 2;
    std::string enemy_damage_description;
    enemy_damage_description = "Enemy's damage is: ";

    for (int i = 0; i < enemy_damage_description.length(); i++)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << enemy_damage_description[i];
        x++;
        Sleep(15);
    }
    std::cout << e_damage;  
    x = 40;
    y = (height - 15);
    for (int i = 0; i < e_description2.length(); i++)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << e_description2[i];
        x++;
        Sleep(15);   
    }
    char move = getch();
    while (move != '\r')
    {
        move = getch();
    }
    delete_show_enemy_description(e_health, e_damage, e_name, e_description2);
}



#endif