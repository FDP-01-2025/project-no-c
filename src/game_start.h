#ifndef GAME_START_H
#define GAE_START_H
#include "dialogues.h"
#include "inf_window.h"
#include "mutex_key.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "player_/player.h"
#include <thread>
#include "npcs_/toilet_1.h"
#include "menu_options.h"
#include "fighting_system_/fighting_system.h"
#include "rain_menu_animation.h"

int show_menu();

void game_start(){ //inicio papu game
    int width, height, x, y, health, damage, player_level, t_x, t_y, t_health, t_damage;
    std::string player_name;
    player_level = 1;
    player_name = "skibidi pomni";
    t_health = 30;
    t_damage = 7;
    window_size(width, height);
    x = (width / 2);
    y = (height / 2);
    health = 20;
    damage = 10;
    player player_1(x, y, health, damage,player_level,player_name); // da las coordenadas de player
    t_x = (width / 2) + 10;
    t_y = (height / 2) - 3;
    std::string t_name = "Toilet";
    toilet toilet_1(t_x, t_y, t_health, t_damage, t_name); // da las coordenadas de toilet
    Sleep(1000);

    toilet_1.show_toilet(); //show toilet in the game

    while (bool player = true)
    {


        int prev_x = player_1.x;
        int prev_y = player_1.y;

        char move = player_1.player_movement();

        if (player_1.x == toilet_1.x && player_1.y == toilet_1.y)
        {
            player_1.x = prev_x;
            player_1.y = prev_y;
            player_1.show_player_coord();
        }

        if (std::abs(player_1.x - toilet_1.x) <= 1 && std::abs(player_1.y - toilet_1.y) <= 1 && move == 'q')
        {
             player = false;
             toilet_1.health = 30;
             bool fight = true;
             while (toilet_1.health > 0 && fight == true)
             {  
                if (show_options(player_1.name,player_1.level,player_1.health,player_1.damage, toilet_1.health, toilet_1.name) == 's'){
                    fight = false;
                }
             }
             system("cls");
        }
        
        if (move == 'e')
        {
            player = false;
            system("cls");
            show_menu();
        }
        
        toilet_1.show_toilet();
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