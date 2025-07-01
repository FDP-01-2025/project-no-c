#ifndef PLAYER_GAMES_H
#define PLAYER_GAMES_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "inf_window.h"
#include "menu_options.h"

struct X_menu_principal_option
{
    int x;
    int y;
    X_menu_principal_option(int x, int y):
    x(x), y(y) {}

    char movement_x(){
        show_x();
        int width, height;
        window_size(width, height);
        char move;
        move = getch();
        move =std::tolower(move);
        switch (move)
        {
        case   'w':
            y -= 3;
            break;
        case 's':
            y += 3;
            break;
        default:
            break;
        }
        if (move == '\r' && y == ((height / 2) - 4))
        {
            return 'a';
        }
        else if (move == '\r' && y == ((height / 2) -1))
        {
            return 'b';
        }
        else if (move == '\r' && y == ((height / 2) + 2)){
            return 'c';
        }
        else if (move == '\r' && y == ((height / 2) + 5)){
            return 'd';
        }
        show_x();
        return movement_x();
    }
    
    void show_x(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (y > ((height / 2) + 5))
        {
            y -= 3;
        }
        if(y < ((height / 2) - 4)){
            y += 3;
        }
        COORD coord;
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "X"; 
        key_animation.unlock();
        prev_x = x;
        prev_y = y;
    }
    void delete_x(int x, int y){
        COORD coord;
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
    }
};

void show_menu_principal_options_Save(){
    Sleep(1000);
    int width, height;
    window_size(width, height);
    int y_center = (height) / 2;
    center_text("Games:", y_center - 7);
    Sleep(1000);
    center_text("Game 1:", y_center - 4);
    Sleep(1000);
    center_text("Game 2:", y_center - 1);
    Sleep(1000);
    center_text("Game 3:", y_center + 2);
    Sleep(1000);
    center_text("Return", y_center + 5);
    Sleep(1000);
    int x = (width / 2) - 7;
    int y = (height / 2) - 4;
    X_menu_principal_option x_option(x, y);
    switch (x_option.movement_x())
    {
    case 'a':
        //Cargar archivo 1
        break;
    case 'b':
        //Cargar archivo 2
        break;
    case 'c':
        //Cargar archivo 3
        break;
    case 'd':
        system("cls");
        show_menu();
        break;
    default:
        break;
    }
}



#endif