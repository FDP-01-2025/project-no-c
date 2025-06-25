#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H

#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

void window_size(int &width, int &height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

struct Player {
    int x;
    int y;
    int max_width;
    int max_height;

    Player(int x_, int y_, int w, int h)
        : x(x_), y(y_), max_width(w), max_height(h) {}

    void show() {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "X";
    }

    void clear() {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << " ";
    }

    void move() {
        while (true) {
            char input = getch();
            input = tolower(input);
            clear();

            if (input == 'w' && y > 2) y--;                    
            else if (input == 's' && y < max_height - 3) y++;  
            else if (input == 'a' && x > 2) x--;               
            else if (input == 'd' && x < max_width - 4) x++;   
            else if (input == 'q') break;                      

            show();
        }
    }
};

void start_map() {
    system("cls");
    int width, height;
    window_size(width, height);

    int start_x = width / 2;
    int start_y = height / 2;

    Player player(start_x, start_y, width, height);
    player.show();
    player.move();
}

#endif
