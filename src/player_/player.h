#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\inf_window.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\mutex_key.h>

struct player
{
    int health;
    int x;
    int y;
    std::string nombre;
    player(int health, int x, int y):
        health(health), x(x), y(y) {}
    
    char player_movement(){
        show_player_coord();
        char move;
        move = getch();
        move = std::tolower(move);
        switch (move)
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        case 'q':
            return 'q'; 
            break;
        case 'e':
            return 'e';
            break;
        default:
            break;
        }
        show_player_coord();
        return player_movement();
    }


    void show_player_coord(){
        int width, height;
        window_size(width, height);
        int static prev_x, prev_y;
        delete_prev_coord(prev_x, prev_y);
        COORD coord;
        if (x > width - 1)
        {
            x--;
        }
        if (x < 0){
            x++;
        }
        if (y > height - 1){
            y--;
        }
        if (y < 0){
            y++;
        }
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "X";
        key_animation.unlock();
        prev_x = x;
        prev_y = y;
    }
    void delete_prev_coord(int prev_x, int prev_y){
        COORD coord;
        key_animation.lock();
        coord.X = prev_x;
        coord.Y = prev_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
    }
};






#endif