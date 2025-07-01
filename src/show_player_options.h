#ifndef SHOW_PLAYER_OPTIONS_H
#define SHOW_PLAYER_OPTIONS_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "inf_window.h"


struct X_menu_player_option
{
    int x;
    int y;
    X_menu_player_option(int x, int y):
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
        if (move == '\r' && x == (width / 4))
        {
            return 'a';
        }
        else if (move == '\r' && x == (width / 4) + 40)
        {
            return 'b';
        }
        else if (move == '\r' && x == (width / 4) + 80){
            return 'c';
        }
        else if (move == '\r' && x == (width / 4) + 120){
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

        if (x > ((width / 4) + 120))
        {
            x -= 40;
        }
        if(x < (width / 4) - 10){
            x += 40;
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


void show_options_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 2;
    COORD coord;
    for (int i = 0; i < width - 15; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void show_options_continue(){
    int width, height, x, y;
    std::string continue_;
    continue_ = "CONTINUE";
    window_size(width, height);
    x = (width / 4) + 3;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << continue_;
    key_animation.unlock();
}

void show_options_items_(){
    int width, height, x, y;
    std::string show_items;
    show_items = "ITEMS";
    window_size(width, height);
    x = (width / 4) + 43;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << show_items;
    key_animation.unlock();
}

void show_options_save(){
    int width, height, x, y;
    std::string save;
    save = "SAVE";
    window_size(width, height);
    x = (width / 4) + 83;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << save;
    key_animation.unlock();
}

void show_options_principal_menu(){
    int width, height, x, y;
    std::string principal_menu;
    principal_menu = "PRINCIPAL MENU";
    window_size(width, height);
    x = (width / 4) + 123;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << principal_menu;
    key_animation.unlock();
}

void show_option_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 12;
    COORD coord;
    for (int i = 0; i < width - 15; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void show_option_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 7;
    y = 2;
    COORD coord;
    for (int i = 0; i < 11; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_option_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = width - 7;
    y = 2;
    COORD coord;
    for (int i = 0; i < 11; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_option_square_background(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 3;
    COORD coord;
    for (int i = 0; i < 9; i++)
    {
        for (int a = 0; a < width -15; a++)
        {
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << " ";
            x++;
        }
        x = 8;
        y++;
    }
}

///////////////////////DELETE///////////////////

void delete_show_options_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 2;
    COORD coord;
    for (int i = 0; i < width - 15; i++)
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

void delete_show_option_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 12;
    COORD coord;
    for (int i = 0; i < width - 15; i++)
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

void delete_show_option_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 7;
    y = 2;
    COORD coord;
    for (int i = 0; i < 11; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_show_option_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = width - 7;
    y = 2;
    COORD coord;
    for (int i = 0; i < 11; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_square_show_options(){
    delete_show_option_square_bottom();
    delete_show_option_square_left_side();
    delete_show_option_square_right_side();
    delete_show_options_square_top();
}

void delete_show_options_continue(){
    int width, height, x, y;
    std::string continue_;
    continue_ = "         ";
    window_size(width, height);
    x = (width / 4) + 3;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << continue_;
    key_animation.unlock();
}

void delete_show_options_items_(){
    int width, height, x, y;
    std::string show_items;
    show_items = "      ";
    window_size(width, height);
    x = (width / 4) + 43;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << show_items;
    key_animation.unlock();
}

void delete_show_options_save(){
    int width, height, x, y;
    std::string save;
    save = "     ";
    window_size(width, height);
    x = (width / 4) + 83;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << save;
    key_animation.unlock();
}

void delete_show_options_principal_menu(){
    int width, height, x, y;
    std::string principal_menu;
    principal_menu = "               ";
    window_size(width, height);
    x = (width / 4) + 123;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << principal_menu;
    key_animation.unlock();
}

void delete_options_(){
    delete_show_options_continue();
    delete_show_options_items_();
    delete_show_options_save();
    delete_show_options_principal_menu();
}

///////////////////////////////////////////

char show_player_options(){
    int width, height, x, y;
    window_size(width, height);
    x = width / 4;
    y = 7;
    show_options_square_top();
    show_option_square_bottom();
    show_option_square_left_side();
    show_option_square_right_side();
    show_option_square_background();
    show_options_continue();
    show_options_items_();
    show_options_save();
    show_options_principal_menu();
    X_menu_player_option x_player_option(x, y);
    switch (x_player_option.movement_x())
    {
    case 'a':
        x_player_option.delete_x(x_player_option.x, x_player_option.y);
        delete_options_();
        delete_square_show_options();
        return 'a';
        break;
    case 'b':
        return 'b';
        break;
    case 'c':
        return 'c';
        break;
    case 'd':
        return 'd';
        break;
    default:
        break;
    }
    return 'i';
}





#endif