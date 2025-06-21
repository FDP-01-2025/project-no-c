#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\menu_options.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\inf_window.h>
#include <iostream>
#include <windows.h>
#include <thread>
#include <mmsystem.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\mutex_key.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\hide_square.h>

std::mutex key_animation;
bool verify_raining = true;

int main(){
    SetConsoleSize(200, 40);
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
    PlaySound(TEXT("assets//music//Undertale-OST-063-It_s-Raining-Somewhere-Else-Misaki-pruebasonido.wav"),NULL, SND_ASYNC || SND_FILENAME || SND_LOOP);
    Hide_square();
    show_menu();
    Sleep(1000);
}

//g++ main.cpp -lwinmm