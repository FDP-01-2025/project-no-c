#ifndef DELIMITAR_MAPA_H
#define DELIMITAR_MAPA_H
#include <iostream>
#include <windows.h>
using namespace std;

void drawMapBorders(int screen_width, int screen_height) {
    int left_limit   = 4;
    int right_limit  = screen_width - 5;
    int top_limit    = 2;
    int bottom_limit = screen_height - 3;

    COORD coord;

    key_animation.lock();
    coord.X = left_limit; coord.Y = top_limit;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "┌"; key_animation.unlock();
    key_animation.lock();
    coord.X = right_limit; coord.Y = top_limit;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "┐"; key_animation.unlock();
    key_animation.lock();
    coord.X = left_limit; coord.Y = bottom_limit;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "└"; key_animation.unlock();
    key_animation.lock();
    coord.X = right_limit; coord.Y = bottom_limit;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "┘"; key_animation.unlock();

    for (int x = left_limit + 1; x < right_limit; x++) {
        key_animation.lock();
        coord.X = x;
        coord.Y = top_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "─";
        key_animation.unlock();
    
        key_animation.lock();
        coord.X = x;
        coord.Y = bottom_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "─";
        key_animation.unlock();
    }

    for (int y = top_limit + 1; y < bottom_limit; y++) {
        key_animation.lock();
        coord.Y = y;
        coord.X = left_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "│";
        key_animation.unlock();
                
        key_animation.lock();
        coord.Y = y;
        coord.X = right_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "│";
        key_animation.unlock();
    }
}

void restrictMapBorders(int &player_x, int &player_y, int screen_width, int screen_height, int previous_x, int previous_y) {
    int left_limit   = 4;
    int right_limit  = screen_width - 5;
    int top_limit    = 2;
    int bottom_limit = screen_height - 3;

    if (player_x < left_limit || player_x > right_limit || player_y < top_limit || player_y > bottom_limit) {
        player_x = previous_x;
        player_y = previous_y;
    }
}

#endif





