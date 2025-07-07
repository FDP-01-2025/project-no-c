#ifndef END_H
#define END_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "inf_window.h"
#include "menu_options.h"
#include "fighting_system_/dead_system.h"

int show_menu();

void show_win(){
    int width, height, x, y;
    window_size(width, height);
    std::string game_over = "YOU WIN!!! :D";
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
        Sleep(100);
        x++;
    }
}

void show_final_dialogue(){
    int width, height, x, y;
    window_size(width, height);
    std::string continue_option = "You saved Oscar, and now you are the final sigma!";
    x = ((width - continue_option.length()) / 2);
    y = (height / 2) + 2;
    COORD coord;
    for (int i = 0; i < continue_option.length() + 1; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << continue_option[i];
        key_animation.unlock();
        Sleep(50);
        x++;
    }
}

void show_player_end_menu(){
    verify_raining = true;
    system("cls");
    PlaySound(TEXT("assets//music//It_s-Showtime_-Toby-Fox.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    int width, height;
    window_size(width, height);
    int x = (width / 2) - 9;
    int y = (height / 2) - 4;
    int y_center = height / 2;
    std::thread thread_rain(rain_main2);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread thread_rain1(rain_main);
    show_win();
    std::thread thread_rain2(rain_main2);
    show_principal_menu();
    std::thread thread_rain3(rain_main);
    show_continue_option();
    std::thread thread_rain4(rain_main2);
    Sleep(1000);
    std::thread thread_rain5(rain_main);
    show_final_dialogue();
    X_menu_player_dead player_dead(x, y);
    char final_choose = player_dead.movement_x();
    while (final_choose != 'a' && final_choose != 'b')
    {
        show_final_dialogue();
    }
    switch (final_choose)
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
        //codigo calles cargar partida
        break;
    default:
        break;
    }

}



#endif