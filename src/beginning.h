#ifndef BEGINNING_H
#define BEGINNING_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "inf_window.h"
#include "game_start.h"
#include <limits>

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
            x -= 3;
            break;
        case 'd':
            x += 3;
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

        if (x > ((width / 2) + 6))
        {
            x -= 3;
        }
        if(x < ((width / 2) - 3)){
            x += 3;
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
        Sleep(100);
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
        Sleep(250);
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
    std::string player_name = "";
    std::string vessel_name = "";
    PlaySound(TEXT("assets//music//ANOTHER-HIM-Toby-Fox.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    Player_Start Player1(x_center, y_center);
    Player_Start Player2(x_center, y_center);
    animated_text("Oh...", y_center);
    Sleep(3000);
    delete_text("Oh...", y_center);
    Sleep(2000);
    animated_text("Is someone there?", y_center);
    Sleep(3000);
    delete_text("Is someone there?", y_center);
    Sleep(2000);
    Sleep(1000);
    animated_text("WHO ARE YOU, WHAT IS YOUR NAME?", y_center - 3);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia el buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    COORD coord1;
    coord1.X = x_center - 5;
    coord1.Y = y_center;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord1);
    std::cin >> player_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    system("cls");
    Sleep(2000);
    animated_text("Good...", y_center);
    Sleep(3000);
    delete_text("Good...", y_center);
    Sleep(2000);
    animated_text("NOW, what is your vessel's name?", y_center - 3);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    COORD coord2;
    coord2.X = x_center - 5;
    coord2.Y = y_center;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord2);
    std::cin >> vessel_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia el buffer
    system("cls");
    Sleep(2000);
    animated_text("Weird name but ok... ", y_center);
    Sleep(3000);
    delete_text("Weird name but ok... ", y_center);
    Sleep(2000);
    animated_text("Choose your character: ", y_center - 3);
    Sleep(1000);
    show_things("X", y_center +2, x_center - 3);
    Sleep(1000);
    show_things("x", y_center +2, x_center);
    Sleep(1000);
    show_things("*", y_center +2, x_center + 3);
    Sleep(1000);
    show_things("+", y_center +2, x_center + 6);
    Sleep(1000);
    Player1.movement_x();
    system("cls");
    Sleep(2000);
    animated_text("...", y_center);
    Sleep(3000);
    delete_text("...", y_center);
    Sleep(2000);
    animated_text("Select his color: ", y_center - 3);
    Sleep(1000);
    show_things_with_color("■", y_center +2, x_center - 3, 15);
    Sleep(1000);
    show_things_with_color("■", y_center +2, x_center, 1);
    Sleep(1000);
    show_things_with_color("■", y_center +2, x_center + 3, 5);
    Sleep(1000);
    show_things_with_color("■", y_center +2, x_center + 6, 3);
    Sleep(1000);
    Player2.movement_x();
    system("cls");
    Sleep(2000);
    animated_text("Out of every color you chose that?", y_center);
    Sleep(2000);
    delete_text("Out of every color you chose that?", y_center);
    Sleep(2000);
    animated_text("Wonderful, I don't care at all, I'll choose what you'll be.", y_center);
    Sleep(2000);
    delete_text("Wonderful, I don't care at all, I'll choose what you'll be.", y_center);
    Sleep(2000);
    animated_text("HAHAHAHA", y_center);
    Sleep(2000);
    delete_text("HAHAHAHA", y_center);
    Sleep(2000);
    animated_text("Now ", y_center);
    Sleep(1000);
    delete_text("Now ", y_center);
    Sleep(1000);
    animated_text("Your creation", y_center);
    Sleep(1000);
    delete_text("Your creation", y_center);
    Sleep(1000);
    animated_text("Will be...", y_center);
    Sleep(1000);
    delete_text("Will be...", y_center);
    Sleep(1000);
    PlaySound(NULL, 0,0);
    animated_text_slower("Destroyed.", y_center);
    Sleep(1000);
    delete_text("Destroyed.", y_center);
    Sleep(1000);
    animated_text("Noone in this world deserves to be free.", y_center);
    Sleep(1000);
    delete_text("Noone in this world deserves to be free.", y_center);
    Sleep(1000);
    animated_text_slower("Have fun...", y_center);
    Sleep(1000);
    system("cls");
    game_start();


}





#endif