#ifndef FIGHTING_SYSTEM_H
#define FIGHTING_SYSTEM_H
#include <iostream>
#include <windows.h>
#include "../inf_window.h"
#include <conio.h>
#include <thread>


struct X_menu_options  
{
    int x;
    int y;
    X_menu_options(int x, int y):
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
            x -= 40;
            break;
        case 'd':
            x += 40;
            break;
        default:
            break;
        }

        if (move == '\r' && x == ((width / 4) - 8))
        {
            return 'a';
        }
        else if (move == '\r' && x == (((width / 4) - 8)+ 40))
        {
            return 'b';
        }
        else if (move == '\r' && x == (((width / 4) - 8) + 80)){
            return 'c';
        }
        else if (move == '\r' && x == ((width / 4) - 8) + 120){
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

        if (x < ((width / 4) - 10))
        {
            x += 40;
        }
        if(x > ((width / 4) + 120)){
            x -= 40;
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


void show_options_fighting(){
    int width, height, x, y;
    std::string fight;
    fight = "FIGHT";
    window_size(width, height);
    x = (width / 4) - fight.length();
    y = (height) - 3;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << fight;
    key_animation.unlock();
}

void show_options_items(){
    int width, height, x, y;
    std::string items;
    items = "ITEMS";
    window_size(width, height);
    x = ((width / 4) + 40) - items.length();
    y = (height) - 3;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << items;
    key_animation.unlock();
}

void show_options_actions(){
    int width, height, x, y;
    std::string actions;
    actions = "ACTIONS";
    window_size(width, height);
    x = ((width / 4) + 82) - actions.length();
    y = (height) - 3;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << actions;
    key_animation.unlock();
}

void show_options_run(){
    int width, height, x, y;
    std::string run;
    run = "RUN";
    window_size(width, height);
    x = ((width / 4) + 118) - run.length();
    y = (height) - 3;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << run;
    key_animation.unlock();
}

void show_square_option_top(){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) - 10);
    y = (height - 5);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}
void show_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) - 11);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) + 4);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_option_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) - 10);
    y = (height - 1);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}



void show_square_option(){
    show_square_option_top();
    show_square_option_bottom();
    show_square_left_side();
    show_square_right_side();
}

void big_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 10;
    y = (height - 9);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < width -20 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void big_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 10;
    y = (height - 17);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < width -20 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void big_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 9;
    y = (height - 17);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 9; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void big_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (width) - 10;
    y = (height - 17);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 9; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void square_line(){
    big_square_bottom();
    big_square_top();
    big_square_right_side();
    big_square_left_side();
}

void player_name(std::string name){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 5) - 8);
    y = (height) - 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << name;
    key_animation.unlock();
}

void player_level(int level){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) + 10);
    y = (height) - 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "Level: " << level;
    key_animation.unlock();
}

void player_(std::string name,int level){
    player_name(name);
    player_level(level);
}
char show_options(std::string name, int level){
    int x, y, width, height;
    window_size(width, height);
    x = ((width / 4) - 8);
    y = (height - 3);
    X_menu_options x_options(x, y);
    system("cls");
    Sleep(1000);
    std::thread thread_line(square_line);
    std::thread thread_square1(show_square_option);
    player_(name, level);
    show_options_fighting();
    thread_square1.join();
    thread_line.join();
    Sleep(100);
    show_options_items();
    Sleep(100);
    show_options_actions();
    Sleep(100);
    show_options_run();
    Sleep(100);
    switch (x_options.movement_x())
    {
    case 'a':
        std::cout << "eso tillin xdd ";
        system("cls");
        // llamar funcion ataque
        break;
    case 'b':
        break;
    case 'c':
        break;
    case 'd':
        return 's';
        break;
    default:
        break;
    }
    return 'o';
}


#endif