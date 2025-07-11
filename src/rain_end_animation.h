#ifndef RAIN_END_ANIMATION_H
#define RAIN_END_ANIMATION_H
#include <iostream>
#include <random>
#include "inf_window.h"
#include "mutex_key.h"

extern bool verify_raining;

void rain_main3(){
    int static prev_x, prev_y;
    int x, y;
    int width, height;
    window_size(width, height);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, ((width / 2) - 25));
    COORD coord;
    x = dis(gen);   
    coord.X = x;  
    y = 0;  
    while (y < height - 1 && verify_raining == true)
    {
        y++;
        key_animation.lock();
        COORD prev_coord;
        prev_coord.X = prev_x;
        prev_coord.Y = prev_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        Sleep(100);
        prev_x = x;
        prev_y = y;
    }
    COORD last_coord;
    key_animation.lock();
    last_coord.X = x;
    last_coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), last_coord);
    std::cout << " ";
    key_animation.unlock();
    if (y == height - 1 && verify_raining == true)
    {
        return rain_main3();
    }
}

void rain_main4(){
    int static prev_x, prev_y;
    int x, y;
    int width, height;
    window_size(width, height);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis((width / 2) + 25, (width - 3));
    COORD coord;
    x = dis(gen);   
    coord.X = x;  
    y = 0;  
    while (y < height - 1 && verify_raining == true)
    {
        y++;
        key_animation.lock();
        COORD prev_coord;
        prev_coord.X = prev_x;
        prev_coord.Y = prev_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        Sleep(100);
        prev_x = x;
        prev_y = y;
    }
    COORD last_coord;
    key_animation.lock();
    last_coord.X = x;
    last_coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), last_coord);
    std::cout << " ";
    key_animation.unlock();
    if (y == height - 1 && verify_raining == true)
    {
        return rain_main4();
    }
}

//};


#endif 