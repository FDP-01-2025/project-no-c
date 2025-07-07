#ifndef BEGINNING_H
#define BEGINNING_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "inf_window.h"
#include "game_start.h"

struct Player_Start
{
    int x;
    int y;
    Player_Start(int x, int y):
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
        case   'a':
            x -= 2;
            break;
        case 'd':
            x += 2;
            break;
        default:
            break;
        }
        if (move == '\r')
        {
            return 'a';
        }
        show_x();
        return movement_x();
    }
    
    void show_x(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (x > ((width / 2) + 4))
        {
            x -= 2;
        }
        if(x < ((width / 2) - 4)){
            x += 2;
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

void animated_text(std::string text, int y){
    int width, height, x;
    window_size(width, height);
    x = (width - text.length()) / 2;
    COORD coord;
    for (int i = 0; i < text.length() + 1; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << text[i];
        key_animation.unlock();
        Sleep(30);
        x++;
    }
}

void animated_text_slower(std::string text, int y){
    int width, height, x;
    window_size(width, height);
    x = (width - text.length()) / 2;
    COORD coord;
    for (int i = 0; i < text.length() + 1; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << text[i];
        key_animation.unlock();
        Sleep(200);
        x++;
    }
}

void delete_text(std::string text, int y){
    int width, height, x;
    window_size(width, height);
    x = (width - text.length()) / 2;
    COORD coord;
    for (int i = 0; i < text.length() + 1; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        x++;
    }
}

void show_things(std::string thing, int y, int x){
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << thing;
    key_animation.unlock();
}

void show_things_with_color(std::string thing, int y, int x, int color){
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    std::cout << thing;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    key_animation.unlock();
}

void create_player(){
    int width, height, x, y;
    window_size(width, height);
    int y_center = height / 2;
    int x_center = width / 2;
    system("cls");
    Sleep(2000);
    std::string player_name;
    PlaySound(TEXT("assets//music//ANOTHER-HIM-Toby-Fox.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    Player_Start Player1(x_center, y_center);
    Player_Start Player2(x_center, y_center);
    Sleep(3000);
    animated_text("WHO ARE YOU?", y_center - 3);
    COORD coord1;
    coord1.X = x_center;
    coord1.Y = y_center;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord1);
    std::cin >> player_name;
    system("cls");
    Sleep(2000);
    animated_text("GOOD", y_center);
    Sleep(3000);
    delete_text("GOOD", y_center);
    Sleep(2000);
    animated_text("NOW, HOW ARE YOU?", y_center - 3);
    Sleep(1000);
    show_things("X", y_center, x_center - 4);
    Sleep(1000);
    show_things("x", y_center, x_center - 2);
    Sleep(1000);
    show_things("*", y_center, x_center + 2);
    Sleep(1000);
    show_things("+", y_center, x_center + 4);
    Player1.movement_x();
    system("cls");
    Sleep(2000);
    animated_text("GOOD", y_center);
    Sleep(3000);
    delete_text("GOOD", y_center);
    Sleep(2000);
    animated_text("WHAT IS YOUR COLOR?", y_center - 3);
    Sleep(1000);
    show_things_with_color("■", y_center, x_center - 4, 15);
    Sleep(1000);
    show_things_with_color("■", y_center, x_center - 2, 1);
    Sleep(1000);
    show_things_with_color("■", y_center, x_center + 2, 5);
    Sleep(1000);
    show_things_with_color("■", y_center, x_center + 4, 3);
    Player2.movement_x();
    system("cls");
    Sleep(2000);
    animated_text("GOOD", y_center);
    Sleep(4000);
    delete_text("GOOD", y_center);
    Sleep(2000);
    animated_text("Wonderful", y_center);
    Sleep(4000);
    delete_text("Wonderful", y_center);
    Sleep(2000);
    animated_text("Really wonderful", y_center);
    Sleep(4000);
    delete_text("Really wonderful", y_center);
    Sleep(2000);
    animated_text("Now, your...", y_center);
    Sleep(3000);
    delete_text("Now, your...", y_center);
    Sleep(1000);
    animated_text("Creation", y_center);
    Sleep(3000);
    delete_text("Creation", y_center);
    Sleep(2000);
    animated_text("Will be...", y_center);
    Sleep(3000);
    delete_text("Will be...", y_center);
    Sleep(2000);
    PlaySound(NULL, 0,0);
    animated_text_slower("DESTROYED", y_center);
    Sleep(2000);
    delete_text("DESTROYED", y_center);
    Sleep(2000);
    animated_text("Nobody in this world, can decide who he is.", y_center);
    Sleep(4000);
    delete_text("Nobody in this world, can decide who he is.", y_center);
    Sleep(2000);
    animated_text_slower("Your name is...", y_center);
    Sleep(1000);
    system("cls");
    game_start();


}





#endif