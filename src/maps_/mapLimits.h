#ifndef DELIMITAR_MAPA_H
#define DELIMITAR_MAPA_H

#include <windows.h>
#include <iostream>
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
        cout << "─"; key_animation.unlock();
        key_animation.lock();
        coord.Y = bottom_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "─"; key_animation.unlock();
    }


    for (int y = top_limit + 1; y < bottom_limit; y++) {
        key_animation.lock();
        coord.Y = y;

        coord.X = left_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "│"; key_animation.unlock();
        key_animation.lock();
        coord.X = right_limit;  
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "│"; key_animation.unlock();
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


void drawRoomWalls() {
    COORD coord;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int x = 10; x <= 30; ++x) {
        key_animation.lock();
        coord = { (SHORT)x, 5 };
        SetConsoleCursorPosition(h, coord); cout << "─"; key_animation.unlock(); //Restringir acceso a la consola cuando se printee esta coord
        key_animation.lock();
        coord = { (SHORT)x, 15 };
        SetConsoleCursorPosition(h, coord); cout << "─"; key_animation.unlock();
    }
    for (int y = 6; y < 15; ++y) {
        key_animation.lock();
        coord = { 10, (SHORT)y };
        SetConsoleCursorPosition(h, coord); cout << "│"; key_animation.unlock();
        key_animation.lock();
        coord = { 30, (SHORT)y };
        SetConsoleCursorPosition(h, coord); cout << "│"; key_animation.unlock();
    }
}


void restrictRooms(int &player_x, int &player_y, int prev_x, int prev_y) {
    
    if ((player_x == 10 || player_x == 30) && (player_y >= 5 && player_y <= 15)) {
        if (!(player_y == 15 && player_x == 20)) {
            player_x = prev_x;
            player_y = prev_y;
        }
    }
    if ((player_y == 5 || player_y == 15) && (player_x >= 10 && player_x <= 30)) {
        if (!(player_y == 15 && player_x == 20)) {
            player_x = prev_x;
            player_y = prev_y;
        }
    }
}

#endif