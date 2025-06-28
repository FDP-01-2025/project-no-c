#ifndef COW_ENEMY_H
#define COW_ENEMY_H
#include <iostream>
#include "../inf_window.h"
#include <windows.h>
struct cow_enemy
{
    int healht;
    int damage;
    int x;
    int y;
    int id;
    std::string name;
    std::string character_skin;
    std::string description1;
<<<<<<< HEAD
    cow_enemy(int health, int damage,int x, int y, int id, std::string name, std::string character_skin, std::string description1):
        healht(health),damage(damage),x(x), y(y), id(id), name(name), character_skin(character_skin), description1(description1) {}

        void show_cow() {
=======
    cow_enemy(int health, int damage, int id, std::string name, std::string character_skin):
        x(x), y(y), healht(health), damage(damage), id(id), name(name), character_skin(character_skin), description1(description1) {}
void show_cow() {
>>>>>>> 028a799e60df1c96e844633e4b79b8cf02acdddc
        key_animation.lock();
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "C";
        key_animation.unlock();
}
};
<<<<<<< HEAD
#endif




=======
#endif
>>>>>>> 028a799e60df1c96e844633e4b79b8cf02acdddc
