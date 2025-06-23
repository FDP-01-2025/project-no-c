#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "src/inf_window.h"
#include "src/rain_menu_animation.h"
#include "src/mutex_key.h"
#include "src/game_start.h"
#include <thread>
#include <mutex>

struct X_menu
{
    int x;
    int y;
    X_menu(int x, int y):
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

int show_menu(){
    verify_raining = true;
    int width, height;
    window_size(width, height);
    int y_center = (height) / 2;
    std::thread thread_rain1(rain_main);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread thread_rain2(rain_main2);
    Sleep(2000);
    center_text("Tonacatale", y_center - 7);
    std::thread thread_rain3(rain_main);
    Sleep(2000);
    center_text("New Game", y_center - 4);
    std::thread thread_rain4(rain_main2);
    Sleep(1000);
    center_text("Options", y_center - 1);
    std::thread thread_rain5(rain_main);
    Sleep(1000);
    center_text("Exit", y_center + 2);
    std::thread thread_rain6(rain_main2);
    int x = (width / 2) - 7;
    int y = (height / 2) - 4;
    X_menu x1(x, y);
    switch (x1.movement_x())
    {
    case 'a':
    verify_raining = false;
    thread_rain1.join();
    thread_rain2.join();
    thread_rain3.join();
    thread_rain4.join();
    thread_rain5.join();
    thread_rain6.join();
    system("cls");
    game_start();
        break;
    case 'b':
        system("cls");
        
        // code options music
        break;
    case 'c':
    verify_raining = false;
    system("cls");
    thread_rain1.join();
    thread_rain2.join();
    thread_rain3.join();
    thread_rain4.join();
    thread_rain5.join();
    thread_rain6.join();
    exit(0);
    break;
    default:
        break;
    }
    // x1.movement_x();
    // thread_rain1.join();
    // thread_rain2.join();
    // thread_rain3.join();
    // thread_rain4.join();
    return 0;
}

#endif