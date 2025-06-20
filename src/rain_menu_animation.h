#ifndef RAIN_MENU_ANIMATION_H
#define RAIN_MENU_ANIMATION_H
#include <iostream>
#include <random>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\inf_window.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\mutex_key.h>
// struct rain{
// int x;
// int y;
// rain(int x, int y):
//     x(x), y(y) {}

void rain_main(){
    int static prev_x, prev_y;
    int x, y;
    int width, height;
    window_size(width, height);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, ((width / 2) - 5));
    COORD coord;   
    coord.X = dis(gen);  
    y = 0;  
    while (y < height - 1)
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
    if (y == height - 1)
    {
        return rain_main();
    }
}

//};


#endif