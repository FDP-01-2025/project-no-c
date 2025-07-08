#include "src/menu_options.h"
#include "src/inf_window.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <mmsystem.h> //Playsound
#include "src/mutex_key.h"
#include "src/hide_square.h"

std::mutex key_animation;
bool verify_raining = true;
bool verify_music = true;

int main(){
    SetConsoleSize(200, 40);
    HWND hwnd = GetConsoleWindow();
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ShowWindow(hwnd, SW_MAXIMIZE);
    Hide_square();
    show_menu();
    Sleep(1000);
}

//g++ main.cpp -o Tonacatale.exe -lwinmm 