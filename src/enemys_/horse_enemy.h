#ifndef HORSE_ENEMY_H
#define HORSE_ENEMY_H
#include <iostream>
#include "../inf_window.h"
#include <windows.h>
struct horse_enemy
{
    int healht;
    int damage;
    int x;
    int y;
    int id;
    int experience;
    std::string name;
    std::string character_skin;
    std::string description1;
    std::string description2;
    std::string description3;

horse_enemy(int health, int damage, int x, int y, int id, int experience, std::string name, std::string character_skin, std::string description1, std::string description2, std::string description3)
        : healht(health), damage(damage), x(x), y(y), id(id), experience(experience), name(name), character_skin(character_skin), description1(description1), description2(description2), description3(description3) {}

void show_horse() {
    std::string horse_skin = "J";
    if (healht <= 0) {
        horse_skin = "";
    }
    key_animation.lock();
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << horse_skin;
    key_animation.unlock();

    }
};

#endif
