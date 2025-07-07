#ifndef PLAYER_GAMES_H
#define PLAYER_GAMES_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "inf_window.h"
#include "menu_options.h"
#include "rain_menu_animation.h"
#include "../saves/savepls.h"

extern bool verify_music;
extern bool verify_raining;

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

void show_menu_alternate_options_Save(){
    verify_raining = true;
    verify_music = true;
    Sleep(1000);
    std::thread rain_animation1(rain_main);
    int width, height;
    window_size(width, height);
    int y_center = (height) / 2;
    center_text("Games:", y_center - 7);
    std::thread rain_animation2(rain_main2);
    Sleep(1000);
    center_text("Game 1:", y_center - 4);
    std::thread rain_animation3(rain_main);
    Sleep(1000);
    std::thread rain_animation4(rain_main2);
    center_text("Game 2:", y_center - 1);
    std::thread rain_animation5(rain_main);
    Sleep(1000);
    std::thread rain_animation6(rain_main2);
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
        use_save1();
        break;
    case 'b':
        use_save2();
        break;
    case 'c':
        use_save3();
        break;
    case 'd':
        verify_music = false;
        verify_raining = false;
        rain_animation1.join();
        rain_animation2.join();
        rain_animation3.join();
        rain_animation4.join();
        rain_animation5.join();
        rain_animation6.join();
        verify_raining = true;
        drawMapBorders(width, height);
        continue;
        
        break;
    default:
        break;
    }
}



#endif