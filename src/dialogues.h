#ifndef DIALOGUES_H
#define DIALOGUES_H
#include <iostream>
#include <conio.h>
#include "mutex_key.h"
#include "inf_window.h"
#include <windows.h>
#include <thread>

void dialogue_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = ((height / 2) + 8);
    COORD coord;
    coord.Y = y;
    while (x < width - 10)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
    }
}

void dialogue_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = height - 1;
    COORD coord;
    coord.Y = y;
    while (x < width - 10)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
    }
}

void dialogue_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = width - 10;
    y = ((height / 2) + 8);
    COORD coord;
    for (int i = 0; i < 17; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void dialogue_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = ((height / 2) + 8);
    COORD coord;
    for (int i = 0; i < 17; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void dialogue_background(){
    int width, height, x, y;
    window_size(width, height);
    x = 9;
    y = (height / 2) + 9;
    COORD coord;
    for (int i = 0; i < 16; i++)
    {
        for (int a = 0; a < width - 19; a++)
        {
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << " ";
            x++;
        }
        x = 9;
        y++;
    }
}

void dialogue_square(){
    dialogue_background();
    dialogue_square_bottom();
    dialogue_square_top();
    dialogue_square_left_side();
    dialogue_square_right_side();
}

void center_dialogue(const std::string dialogue){
    int width, height, x, y;
    window_size(width, height);
    x = (width - dialogue.length()) / 2;
    y = (height / 2) + 14;    
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i = 0; i < dialogue.length(); i++)
    {
        std::cout << dialogue[i];
        Sleep(15);
    }
    key_animation.unlock();
}

void delete_dialogue_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = ((height / 2) + 8);
    COORD coord;
    coord.Y = y;
    while (x < width - 10)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
    }
}

void delete_dialogue_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = height - 1;
    COORD coord;
    coord.Y = y;
    while (x < width - 10)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
    }
}

void delete_dialogue_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = width - 10;
    y = ((height / 2) + 8);
    COORD coord;
    for (int i = 0; i < 17; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_dialogue_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = ((height / 2) + 8);
    COORD coord;
    for (int i = 0; i < 17; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_center_dialogue(){
    int width, height, x, y;
    window_size(width, height);
    x = 9;
    y = (height / 2) + 14;    
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i = 0; i < width - 19; i++)
    {
        std::cout << " ";
        x++;
    }
    key_animation.unlock();
}

void delete_square(){
    delete_dialogue_square_top();
    delete_dialogue_square_bottom();
    delete_dialogue_square_right_side();
    delete_dialogue_square_left_side();
    delete_center_dialogue();
}










void finish_dialogue(){
    char move = getch();
    while (move != '\r')
    {
        move = getch();
    }
    delete_square();
}

#endif 