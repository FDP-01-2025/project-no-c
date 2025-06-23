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
    x = 0;
    y = ((height / 2) + 8);
    COORD coord;
    coord.Y = y;
    while (x < width - 1)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        Sleep(1);
    }
}

void dialogue_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 0;
    y = height - 1;
    COORD coord;
    coord.Y = y;
    while (x < width - 1)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        Sleep(1);
    }
}

void dialogue_background(){

}

void dialogue_square(){
    std::thread thread_dialogue_top(dialogue_square_top);
    std::thread thread_dialogue_bottom(dialogue_square_bottom);
    thread_dialogue_top.join();
    thread_dialogue_bottom.join();
}

void center_dialogue(const std::string dialogue){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2);
    y = (height / 2) + 10;    
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i = 0; i < dialogue.length(); i++)
    {
        std::cout << dialogue[i];
        Sleep(3);
    }
    key_animation.unlock();

}

void delete_square_top(){
        int width, height, x, y;
    window_size(width, height);
    x = 0;
    y = ((height / 2) + 8);
    COORD coord;
    coord.Y = y;
    while (x < width - 1)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        Sleep(1);
    }
}

void delete_square_bottom(){
        int width, height, x, y;
    window_size(width, height);
    x = 0;
    y = height - 1;
    COORD coord;
    coord.Y = y;
    while (x < width - 1)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        Sleep(1);
    }
}

void delete_square(){
    std::thread thread_delete_square_top(delete_square_top);
    std::thread thread_delte_square_bottom(delete_square_bottom);
    thread_delete_square_top.join();
    thread_delte_square_bottom.join();
}

void delete_dialogue(){
int width, height, x, y;
    window_size(width, height);
    x = 0;
    y = (height / 2) + 10;    
    COORD coord;
    for (int i = 0; i < width - 1; i++)
    {
        x++;
        key_animation.lock();
        coord.Y = y;
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
    }
    
}

#endif 