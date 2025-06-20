#ifndef HIDE_SQUARE_H
#define HIDE_SQUARE_H
#include <windows.h>

void Hide_square() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO hide_cursor;
    GetConsoleCursorInfo(consoleHandle, &hide_cursor);
    hide_cursor.bVisible = false; 
    SetConsoleCursorInfo(consoleHandle, &hide_cursor);
}

#endif