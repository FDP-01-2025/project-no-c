#ifndef OSCAR_ENEMY_H
#define OSCAR_ENEMY_H
#include <iostream>
#include "../inf_window.h"
#include <windows.h>
struct oscar_enemy
{
    int healht;
    int damage;
    int x;
    int y;
    int id;
    std::string name;
    std::string character_skin;
    std::string description1;

    oscar_enemy(int health, int damage, int x, int y, int id, std::string name, std::string character_skin, std::string description1)
        : healht(health), damage(damage), x(x), y(y), id(id), name(name), character_skin(character_skin), description1(description1) {}

    void show_oscar() {
        key_animation.lock();
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "O";
        key_animation.unlock();
    }
};
#endif
