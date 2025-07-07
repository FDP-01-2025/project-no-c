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
    int width, height;
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
    animated_text("There is someone there?", y_center);
    Sleep(3000);
    delete_text("There is someone there?", y_center);
    Sleep(2000);
    Sleep(3000);
    animated_text("WHO ARE YOU?", y_center - 3);
    COORD coord1;
    coord1.X = x_center - 5;
    coord1.Y = y_center;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord1);
    std::cin >> player_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia el buffer
    system("cls");
    Sleep(2000);
    animated_text("GOOD", y_center);
    Sleep(3000);
    delete_text("GOOD", y_center);
    Sleep(2000);
    animated_text("NOW, HOW IS YOUR VESSEL'S NAME?", y_center - 3);
    COORD coord2;
    coord2.X = x_center - 5;
    coord2.Y = y_center;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord2);
    std::cin >> vessel_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia el buffer
    system("cls");
    Sleep(2000);
    animated_text("GOOD", y_center);
    Sleep(3000);
    delete_text("GOOD", y_center);
    Sleep(2000);
    animated_text("NOW, HOW IS YOUR VESSEL?", y_center - 3);
    Sleep(1000);
    show_things("X", y_center +2, x_center - 3);
    Sleep(1000);
    show_things("x", y_center +2, x_center);
    Sleep(1000);
    show_things("*", y_center +2, x_center + 3);
    Sleep(1000);
    show_things("+", y_center +2, x_center + 6);
    Sleep(1000);
    while (_kbhit()){ getch();} // limpia las teclas pendientes 
    Player1.movement_x();
    system("cls");
    Sleep(2000);
    animated_text("GOOD", y_center);
    Sleep(3000);
    delete_text("GOOD", y_center);
    Sleep(2000);
    animated_text("WHAT IS HIS COLOR?", y_center - 3);
    Sleep(1000);
    show_things_with_color("■", y_center +2, x_center - 3, 15);
    Sleep(1000);
    show_things_with_color("■", y_center +2, x_center, 1);
    Sleep(1000);
    show_things_with_color("■", y_center +2, x_center + 3, 5);
    Sleep(1000);
    show_things_with_color("■", y_center +2, x_center + 6, 3);
    Sleep(1000);
    while (_kbhit()){ getch();} // limpia las teclas pendientes 
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
    Sleep(1500);
    delete_text("Now, your...", y_center);
    Sleep(1000);
    animated_text("Creation", y_center);
    Sleep(3000);
    delete_text("Creation", y_center);
    Sleep(2000);
    animated_text("Will be...", y_center);
    Sleep(3000);
    delete_text("Will be...", y_center);
    Sleep(3000);
    PlaySound(NULL, 0,0);
    animated_text_slower("DESTROYED", y_center);
    Sleep(3000);
    delete_text("DESTROYED", y_center);
    Sleep(2000);
    animated_text("Nobody in this world, can decide who he is.", y_center);
    Sleep(4000);
    delete_text("Nobody in this world, can decide who he is.", y_center);
    Sleep(2000);
    animated_text_slower("Your name is...", y_center);
    Sleep(1000);
    system("cls");
    //crear archivo codigo calles

    //New game
    bool new_game = false;
    //Player creation
    int x = (width / 12);
    int y = (height / 4);
    int health = 10;
    int max_health = 10;
    int damage = 10;
    int level = 1;
    int inventory = 0;
    int experience = 0;
    std::string player_name_1 = "Skibidi pomni";
    std::string inventory_item[6] = {""};

    //Enemys stats
    int c_health = 30;
    int ca_health = 15;
    int ha_health = 50;
    int i_health = 15;
    int th_health = 35;
    int sn_health = 12;
    int h_health = 25;
    int s_health = 40;
    int p_health = 20;

    game_start(new_game,x, y, health, max_health, damage, level, player_name, player_name_1,inventory_item,inventory, experience, c_health, ca_health, ha_health,i_health, th_health, sn_health, h_health, s_health,p_health );


}





#endif