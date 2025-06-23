#ifndef INF_WINDOW_H
#define INF_WINDOW_H
#include <windows.h>
#include <iostream>
#include "src/mutex_key.h"
inline void window_size(int &width, int &height){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hconsole, &csbi);
    width = csbi.dwSize.X;
    height = csbi.dwSize.Y;
}

inline void center_text(const std::string &text, int y){
    int width, height;
    window_size(width, height);
    int x = (width - text.length()) / 2;

    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << text;
    key_animation.unlock();
}

void SetConsoleSize(int width, int height){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    // SMALL_RECT WindowSize = {0, 0, 1, 1};
    // SetConsoleWindowInfo(hConsole, TRUE, &WindowSize);

    COORD bufferSize = { (SHORT)width, (SHORT)height };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SMALL_RECT windowSize = { 0, 0, (SHORT)(width - 1), (SHORT)(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
    // WindowSize.Right = width -1;
    // WindowSize.Bottom = height -1;
    // SetConsoleWindowInfo(hConsole, TRUE, &WindowSize);
}


#endif