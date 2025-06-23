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
    int id = 1;
    toilet(int x, int y, int health, int damage):
    x(x), y(y), health(health), damage(damage) {}

    void show_toilet(){
        key_animation.lock();
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
        std::cout << "L";
        key_animation.unlock();
    }
};



#endif