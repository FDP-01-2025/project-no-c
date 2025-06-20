#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\inf_window.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\rain_menu_animation.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\mutex_key.h>
#include <thread>
#include <mutex>

struct X_menu
{
    int x;
    int y;
    X_menu(int x, int y):
    x(x), y(y) {}

    void movement_x(){
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
            std::cout << "cpapuxdd"; //call funtion new_game
        }
        else if (move == '\r' && y == ((height / 2) -1))
        {
            std::cout << "ostia tio xdd"; // call funtion optional_menu_2
        }
        else if (move == '\r' && y == ((height / 2) + 2))
            std::cout << "a papu salir papu xdd"; // return 0;
        show_x();
        return movement_x();
    }
    
    void show_x(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (y > ((height / 2) + 2))
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

void show_menu(){
    int width, height;
    window_size(width, height);
    int y_center = (height) / 2;
    std::thread thread_rain1(rain_main);
    Sleep(2000);
    center_text("Tonacatale", y_center - 7);
    Sleep(1000);
    center_text("New Game", y_center - 4);
    Sleep(1000);
    center_text("Options", y_center - 1);
    Sleep(1000);
    center_text("Exit", y_center + 2);
    int x = (width / 2) - 7;
    int y = (height / 2) - 4;
    X_menu x1(x, y);
    x1.movement_x();
    thread_rain1.join();
}

#endif