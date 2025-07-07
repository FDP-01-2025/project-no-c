#ifndef TOILET_1_H
#define TOILET_1_H
#include <iostream>
#include "../inf_window.h"
#include <windows.h>

struct toilet{
    int x;
    int y;
    int health;
    int damage;
    int id;
    std::string description1;
    std::string name;
    std::string character_skin;
    toilet(int x, int y, int health, int damage, int id,std::string name, std::string character_skin, std::string description1):
    x(x), y(y), health(health), damage(damage), id(id), name(name), character_skin(character_skin), description1(description1) {}

    void show_toilet(){
        key_animation.lock();
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        std::cout << "Q";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        key_animation.unlock();
    }
};



#endif