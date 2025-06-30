#ifndef RIVER_H
#define RIVER_H
#include <iostream>
#include "../inf_window.h"
#include <windows.h>

void show_river(){
    int width, height, x, y;
    window_size(width, height);
    x = 5;
    y = 3;
    COORD coord;
    for (int i = 0; i < 7; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        std::cout << "■";
        key_animation.unlock();
        for (int i = 0; i < 37; i++){
            key_animation.lock();
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
            std::cout << "■";
            key_animation.unlock();
            x++;
        }
        x = 5;
        y++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void detail_river_1(){
    int width, height, x, y;
    window_size(width, height);
    x = 5;
    y = 10;
    COORD coord;
    for (int i = 0; i < 23; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        std::cout << "■";
        key_animation.unlock();
        x++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void detail_river_2(){
    
}

void river(){
    show_river();
    detail_river_1();
}



#endif 