#ifndef FIGHT_INTERACTION_H
#define FIGHT_INTERACTION_H
#include "../inf_window.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
struct attack {
    int x;
    int y;
    attack(int x, int y):
        x(x), y(y) {}

    void delete_(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << " ";
}

void player_Attack1(){
    int static prev_x, prev_y;
    delete_(prev_x, prev_y);
    int width, height;
    window_size(width, height);
    x = 12;
    y = height - 12;
    COORD coord;
    for (int i = 0; i < width - 30; i++)
    {
        x++;
        key_animation.lock();
        coord.Y = y;
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "*";
        key_animation.unlock();
        Sleep(10);
        prev_x = x;
        prev_y = y;
        delete_(prev_x, prev_y);
    }
    delete_(x, y);
}

void player_attack2(int damage, int& e_health){
    char attack;
    int width, height;
    window_size(width, height);
    std::thread thread_attack(player_Attack1, this);
    attack = getch();
    attack = std::tolower(attack);
    if (x == width - 42){
        attack = '\r';
        e_health = e_health;
    }
    if (attack == '\r' && x > (width / 2) - 10 && x < (width / 2) + 10)
    {
        e_health = e_health - damage;
    }
    else if (attack == '\r' && x > 12 && x < (width / 2) - 10)
    {
        e_health = e_health - (damage - 3);
    }
    else if (attack == '\r' && x > (width / 2) + 10 && x < width - 30){
        e_health = e_health - (damage -5); 
    }


    thread_attack.join();
    int x_, y_;
    x_ = (width / 2) + 2;
    y_ = (height / 2) - 1;
    if(e_health > 0)
    {
        COORD coord;
        key_animation.lock();
        coord.X = x_;
        coord.Y = y_;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << e_health;
        key_animation.unlock();
        Sleep(500);
        delete_e_health(x_, y_);
    }
    else {
    int last_x, last_y;
    last_x = width / 2;
    last_y = height / 2;
    COORD coord;
    key_animation.lock();
    coord.X = last_x;
    coord.Y = last_y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "Enemy defeat! :D";
    key_animation.unlock();
    Sleep(500);}
}

void delete_e_health(int x, int y){
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "   ";
    key_animation.unlock();
}

};

void player_attack(int damage, int& e_health){
    // int width, height;
    // window_size(width, height);
    // int x = 12;
    // int y = height - 12;
    int x = 0, y = 0;
    attack player_attack(x, y);
    player_attack.player_attack2(damage, e_health);
}



#endif 