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

<<<<<<< HEAD
    key_animation.lock();
=======
>>>>>>> cf417a2268de586198981280ccd036a7bebb46ba
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
<<<<<<< HEAD
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "─"; key_animation.unlock();
        key_animation.lock();
        coord.Y = bottom_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "─"; key_animation.unlock();
=======
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "─";

        coord.Y = bottom_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "─";
>>>>>>> cf417a2268de586198981280ccd036a7bebb46ba
    }

    
    for (int y = top_limit + 1; y < bottom_limit; y++) {
        key_animation.lock();
        coord.Y = y;

        coord.X = left_limit;
<<<<<<< HEAD
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "│"; key_animation.unlock();
        key_animation.lock();
        coord.X = right_limit;  
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "│"; key_animation.unlock();
=======
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "│";

        coord.X = right_limit;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "│";
>>>>>>> cf417a2268de586198981280ccd036a7bebb46ba
    }



draw_line(8, 4, 28, 4, '#');   
draw_line(8, 9, 28, 9, '#');   
draw_line(8, 4, 8, 9, '#');    
draw_line(28, 4, 28, 9, '#');  


draw_line(55, 3, 75, 3, '#');
draw_line(55, 8, 75, 8, '#');
draw_line(55, 3, 55, 8, '#');
draw_line(75, 3, 75, 8, '#');



draw_line(10, 15, 30, 15, '#');
draw_line(10, 20, 30, 20, '#');
draw_line(10, 15, 10, 20, '#');
draw_line(30, 15, 30, 20, '#');



draw_line(50, 16, 70, 16, '#');
draw_line(50, 21, 70, 21, '#');
draw_line(50, 16, 50, 21, '#');
draw_line(70, 16, 70, 21, '#');



draw_line(30, 25, 50, 25, '#');
draw_line(30, 30, 50, 30, '#');
draw_line(30, 25, 30, 30, '#');
draw_line(50, 25, 50, 30, '#');
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

    if ((player_x == 35 || player_x == 55) && (player_y >= 3 && player_y <= 9) && player_y != 6) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }
    if ((player_y == 3 || player_y == 9) && (player_x >= 35 && player_x <= 55)) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }

    if ((player_x == 15 || player_x == 35) && (player_y >= 13 && player_y <= 19)) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }
    if ((player_y == 13 || player_y == 19) && (player_x >= 15 && player_x <= 35) && player_x != 25) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }

   
    if ((player_x == 40 || player_x == 60) && (player_y >= 14 && player_y <= 20)) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }
    if ((player_y == 14 || player_y == 20) && (player_x >= 40 && player_x <= 60) && player_x != 50) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }
    if ((player_x == 25 || player_x == 45) && (player_y >= 22 && player_y <= 28) && player_y != 25) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }
    if ((player_y == 22 || player_y == 28) && (player_x >= 25 && player_x <= 45)) {
        player_x = previous_x;
        player_y = previous_y;
        return;
    }
}

<<<<<<< HEAD

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
=======
#endif
>>>>>>> cf417a2268de586198981280ccd036a7bebb46ba
