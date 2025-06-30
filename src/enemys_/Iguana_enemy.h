#ifndef IGUANA_ENEMY_H
#define IGUANA_ENEMY_H
#include <iostream>
#include "../inf_window.h"
#include <windows.h>

struct iguana_enemy
{
    int healht;
    int damage;
    int x;
    int y;
    int id;
    std::string name;
    std::string character_skin;
    std::string description1;
    std::string description2;
    std::string description3;

iguana_enemy(int health, int damage, int x, int y, int id, std::string name, std::string character_skin, std::string description1, std::string description2, std::string description3)
        : healht(health), damage(damage), x(x), y(y), id(id), name(name), character_skin(character_skin), description1(description1), description2(description2), description3(description3) {}
    

    void show_iguana(){
        key_animation.lock();
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "I";
        key_animation.unlock();
    }
};
#endif
