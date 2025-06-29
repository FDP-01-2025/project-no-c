#ifndef PIG_ENEMY_H
#define PIG_ENEMY_H
#include <iostream>
#include "../inf_window.h"
#include <windows.h>
struct pig_enemy
{
    int healht;
    int damage;
    int x;
    int y;
    int id;
    std::string name;
    std::string character_skin;
    std::string description1;

    pig_enemy(int health, int damage, int x, int y, int id, std::string name, std::string character_skin, std::string description1)
        : healht(health), damage(damage), x(x), y(y), id(id), name(name), character_skin(character_skin), description1(description1) {}

    void show_pig()
    {
        key_animation.lock();
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "P";
        key_animation.unlock();
    }
};

#endif
