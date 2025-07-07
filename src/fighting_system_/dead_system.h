#ifndef DEAD_SYSTEM_H
#define DEAD_SYSTEM_H
#include <iostream>
#include "../inf_window.h"
#include <windows.h>
#include <conio.h>
#include "../rain_menu_animation.h"
#include "../menu_options.h"
#include <chrono>
#include "../../saves/savepls.h"

int show_menu();

struct X_menu_player_dead
{
    int x;
    int y;
    X_menu_player_dead(int x, int y):
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
        show_x();
        return movement_x();
    }
    
    void show_x(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (y > ((height / 2) -1))
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

void show_game_over(){
    int width, height, x, y;
    window_size(width, height);
    std::string game_over = "GAME OVER";
    x = ((width - game_over.length()) / 2) - 1;
    y = (height / 2) - 7;
    COORD coord;
    for (int i = 0; i < game_over.length() + 1; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << game_over[i];
        key_animation.unlock();
        Sleep(200);
        x++;
    }
}

void show_principal_menu(){
    int width, height, x, y;
    window_size(width, height);
    std::string principal_menu_ = "Principal Menu";
    x = ((width - principal_menu_.length()) / 2);
    y = (height / 2) - 4;
    COORD coord;
    for (int i = 0; i < principal_menu_.length() + 1; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << principal_menu_[i];
        key_animation.unlock();
        Sleep(100);
        x++;
    }
}

void show_continue_option(){
    int width, height, x, y;
    window_size(width, height);
    std::string continue_option = "Continue";
    x = ((width - continue_option.length()) / 2);
    y = (height / 2) - 1;
    COORD coord;
    for (int i = 0; i < continue_option.length() + 1; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << continue_option[i];
        key_animation.unlock();
        Sleep(100);
        x++;
    }
}

void show_player_dead_menu(std::string creator_name){
    verify_raining = true;
    system("cls");
    PlaySound(TEXT("assets//music//Determination-Toby-Fox.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    int width, height;
    window_size(width, height);
    int x = (width / 2) - 9;
    int y = (height / 2) - 4;
    int y_center = height / 2;
    std::thread thread_rain(rain_main2);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread thread_rain1(rain_main);
    show_game_over();
    std::thread thread_rain2(rain_main2);
    show_principal_menu();
    std::thread thread_rain3(rain_main);
    show_continue_option();
    std::thread thread_rain4(rain_main2);
    Sleep(1000);
    std::thread thread_rain5(rain_main);
    X_menu_player_dead player_dead(x, y);
    switch (player_dead.movement_x())
    {
    case 'a':
        verify_raining = false;
        thread_rain.join();
        thread_rain1.join();
        thread_rain2.join();
        thread_rain3.join();
        thread_rain4.join();
        thread_rain5.join();
        system("cls");
        PlaySound(NULL, 0, 0);
        verify_raining = true;
        show_menu();
        break;
    case 'b':
        verify_raining = false;
        thread_rain.join();
        thread_rain1.join();
        thread_rain2.join();
        thread_rain3.join();
        thread_rain4.join();
        thread_rain5.join();
        system("cls");
        PlaySound(NULL, 0, 0);
        loadGame(creator_name);
        //codigo calles cargar partida
        break;
    default:
        break;
    }

}



#endif