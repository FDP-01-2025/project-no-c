#ifndef DELIMITAR_MAPA_H
#define DELIMITAR_MAPA_H

#include <windows.h>
#include <iostream>
using namespace std;

void draw_line(int x1, int y1, int x2, int y2, char symbol) {
    COORD coord;
    if (x1 == x2) {
        for (int y = y1; y <= y2; y++) {
            coord.X = x1;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << symbol;
        }
    } else {
        for (int x = x1; x <= x2; x++) {
            coord.X = x;
            coord.Y = y1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << symbol;
        }
    }
}

void drawMapBorders(int screen_width, int screen_height) {
    int left_limit   = 4;
    int right_limit  = screen_width - 5;
    int top_limit    = 2;
    int bottom_limit = screen_height - 3;

    COORD coord;


    coord.X = left_limit; coord.Y = top_limit;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "┌";

    coord.X = right_limit; coord.Y = top_limit;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "┐";

    coord.X = left_limit; coord.Y = bottom_limit;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "└";

    coord.X = right_limit; coord.Y = bottom_limit;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "┘";

    for (int x = left_limit + 1; x < right_limit; x++) {
        coord.X = x;

        coord.Y = top_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "─";

        coord.Y = bottom_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "─";
    }

    for (int y = top_limit + 1; y < bottom_limit; y++) {
        coord.Y = y;

        coord.X = left_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "│";

        coord.X = right_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "│";
    }


    // Sala 1
    draw_line(10, 5, 30, 5, '#');   
    draw_line(10, 10, 30, 10, '#'); 
    draw_line(10, 5, 10, 10, '#');  
    draw_line(30, 5, 30, 10, '#');  

    
}

void restrictMapBorders(int &player_x, int &player_y, int screen_width, int screen_height, int previous_x, int previous_y) {
    int left_limit   = 4;
    int right_limit  = screen_width - 5;
    int top_limit    = 2;
    int bottom_limit = screen_height - 3;

    if (player_x < left_limit || player_x > right_limit || player_y < top_limit || player_y > bottom_limit) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }

    if ((player_x == 10 || player_x == 30) && (player_y >= 5 && player_y <= 10) && player_x != 30 && player_y != 7) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }
    if ((player_y == 5 || player_y == 10) && (player_x >= 10 && player_x <= 30) && player_x != 30) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }


}

#endif
