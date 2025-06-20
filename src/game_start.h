#ifndef GAME_START_H
#define GAE_START_H
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\dialogues.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\inf_window.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\mutex_key.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

void game_start(){
    char next;
    do
    {
       std::string si;
        si = "eso tillin";
        std::thread thread_dialog(dialogue_square);
        center_dialogue(si);
        next = getch();
        thread_dialog.join();
    } while (next != '\r');
    delete_square();
    delete_dialogue();
    Sleep(1000);
    
}

#endif