#ifndef GAME_START_H
#define GAE_START_H
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\dialogues.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\inf_window.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\mutex_key.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\player_\player.h>
#include <thread>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\npcs_\toilet_1.h>
#include <C:\Users\willi\OneDrive\Escritorio\project-no-c\src\menu_options.h>

int show_menu();

void game_start(){ //inicio papu game
    int width, height, x, y, health, t_x, t_y;
    window_size(width, height);
    x = (width / 2);
    y = (height / 2);
    health = 100;
    player player_1(health, x, y); // da las coordenadas de player
    t_x = (width / 2) + 10;
    t_y = (height / 2) - 3;
    toilet toilet_1(t_x, t_y); // da las coordenadas de toilet
    Sleep(1000);
    toilet_1.show_toilet(); //show toilet in the game

    while (true) // bucle infinito para que el jugador se pueda mover
    {
        char move; // variable para almacenar los valores de player_movement()
        move = player_1.player_movement();
        if(player_1.x - toilet_1.x <= 1 && player_1.y - toilet_1.y <= 1 && move == 'q'){  // si el jugador este cerca de X y Y, de toilet y presiona q, entonces hablara
        toilet_1.toilet_dialogue();
        Sleep(3000);
    }
    
    if (move == 'e'){ //si el jugador presiona e, entonces regresara al menu
        system("cls");
        show_menu();

    }
}
}    

    // try dialogue system later
    // char next;
    // do
    // {
    //     std::string si;
    //     si = "eso tillin";
    //     std::thread thread_dialog(dialogue_square);
    //     center_dialogue(si);
    //     next = getch();
    //     thread_dialog.join();
    // } while (next != '\r');
    // delete_square();
    // delete_dialogue();
    // Sleep(1000);

#endif