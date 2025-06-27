#ifndef COW_ENEMY_H
#define COW_ENEMY_H
#include <iostream>
struct cow_enemy
{
    int healht;
    int damage;
    std::string name;
    std::string character_skin;
    cow_enemy(int health, int damage, std::string name, std::string character_skin):
        healht(health), damage(damage), name(name), character_skin(character_skin) {}

    
};











#endif 