#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "inf_window.h"
#include "rain_menu_animation.h"
#include "mutex_key.h"
#include "game_start.h"
#include <thread>
#include <mutex>
#include "player_games.h"
#include "beginning.h"

extern bool verify_music;

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


int show_menu(){
    if (verify_music == true)
    {
        PlaySound(TEXT("assets//music//Undertale-OST-063-It_s-Raining-Somewhere-Else-Misaki-pruebasonido.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    }
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
    center_text("Continue", y_center - 1);
    Sleep(1000);
    center_text("Options", y_center + 2);
    std::thread thread_rain5(rain_main);
    Sleep(1000);
    center_text("Exit", y_center + 5);
    std::thread thread_rain6(rain_main2);
    int x = (width / 2) - 7;
    int y = (height / 2) - 4;
    X_menu x1(x, y);
    switch (x1.movement_x())
    {
    case 'a':
    PlaySound(NULL, 0, 0);
    verify_raining = false;
    thread_rain1.join();
    thread_rain2.join();
    thread_rain3.join();
    thread_rain4.join();
    thread_rain5.join();
    thread_rain6.join();
    system("cls");
    //Nueva partida codigo calles
    create_player();
        break;
    case 'b':
        verify_raining = false;
        thread_rain1.join();
        thread_rain2.join();
        thread_rain3.join();
        thread_rain4.join();
        thread_rain5.join();
        thread_rain6.join();
        system("cls");  
        show_menu_principal_options_Save();
        break;
    case 'c':
    system("cls");

        // code music option
    break;
    case 'd':
    PlaySound(NULL, 0, 0);
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