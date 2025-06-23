#ifndef TOILET_1_H
#define TOILET_1_H
#include <iostream>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\inf_window.h>
#include <windows.h>

struct toilet{
    int x;
    int y;
    toilet(int x, int y):
    x(x), y(y) {}

    void show_toilet(){
        key_animation.lock();
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
        std::cout << "L";
        key_animation.unlock();
    }

    void toilet_dialogue(){
        std::cout << "HOLA PAPUUUUUUUUU";
    }
};



#endif