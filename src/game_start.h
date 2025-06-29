#ifndef GAME_START_H
#define GAME_START_H
#include "dialogues.h"
#include "inf_window.h"
#include "mutex_key.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "player_/player.h"
#include "maps_/mapLimits.h" // para delimitar el mapa
#include <thread>
#include "npcs_/toilet_1.h"
#include "enemys_/cow_enemy.h"
#include "menu_options.h"
#include "fighting_system_/fighting_system.h"
#include "rain_menu_animation.h"
#include "maps_/mapLimits.h"

int show_menu();

void show_chest_top(){
    int x, y, width, height;
    window_size(width, height);
    x = (width - 29);
    y = (height / 5); 
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "___";
    key_animation.unlock();
}
void show_chest_bottom(){
    int x, y, width, height;
    window_size(width, height);
    x = (width - 30);
    y = (height / 5) + 1; 
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "|___|";
    key_animation.unlock();
}

void show_chest(){
    show_chest_top();
    show_chest_bottom();
}

void game_start(){ //inicio papu game
    int width, height, x, y, health, damage, player_level, t_x, t_y,t_id, t_health, t_damage;
    std::string player_name;
    player_level = 1;
    player_name = "skibidi pomni";
    t_health = 30;
    t_damage = 7;
    t_id = 1;
    window_size(width, height);
    x = (width / 2);
    y = (height / 2);
    health = 20;
    damage = 10;
    int inventory = 0;
    player player_1(x, y, health, damage, inventory,player_level,player_name); // da las coordenadas de player
    t_x = (width / 2) + 10;
    t_y = (height / 2) - 3;
    std::string t_name = "Toilet";
    std::string t_skin = "L";
    std::string t_description_1 = "Toilet wanna fight!";
    toilet toilet_1(t_x, t_y, t_health, t_damage, t_id, t_name,t_skin, t_description_1); // da las coordenadas de toilet

    int left_limit   = 5;                     
    int right_limit  = width - 6;      
    int top_limit    = 3;                     
    int bottom_limit = height - 4;     

    int c_x = (width / 2) - 30;
    int c_y = (height / 2) + 10;
    int c_health = 10;
    int c_damage = 5;
    int c_id = 2;
    std::string c_name = "Cow";
    std::string c_skin = "C";
    std::string c_description_1 = "Moo, I'm a cow!";  
    cow_enemy cow_1(c_health, c_damage,c_x, c_y, c_id, c_name, c_skin, c_description_1);// Coordenadas de cow  

    Sleep(1000);
    toilet_1.show_toilet(); //show toilet in the game
    cow_1.show_cow();
    show_chest();
    drawMapBorders(width, height);

    PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

    while (bool player = true) //Bucle para mover a player
    {
        
        int prev_x = player_1.x; //Coordenadas anteriores de player
        int prev_y = player_1.y; 
        
        char move = player_1.player_movement(); //Movimiento player

        if (player_1.x < left_limit || player_1.x > right_limit || player_1.y < top_limit || player_1.y > bottom_limit ){
        player_1.x = prev_x;
        player_1.y = prev_y;
        player_1.show_player_coord();
        drawMapBorders(width, height);
        }

        if (player_1.x == toilet_1.x && player_1.y == toilet_1.y) //Si el jugador llega a las mismas coordendas de toilet retrocedera
        {
            player_1.x = prev_x;
            player_1.y = prev_y;
            player_1.show_player_coord();
        }
        
        if (std::abs(player_1.x - toilet_1.x) <= 1 && std::abs(player_1.y - toilet_1.y) <= 1 && move == 'q') // Si player esta a 1 coordenada de toilet y presiona q, entonces pelearan
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"),NULL, SND_SYNC | SND_FILENAME);
            PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            //Sleep(800);
            player = false; // se detiene el ciclo player
            toilet_1.health = 30; // vida base de toilet
            bool fight = true; // inicio ciclo pelea
             while (toilet_1.health > 0 && fight == true)
             {  
                if (show_options(player_1.name,player_1.level,player_1.health,player_1.damage, player_1.inventory,player_1.inventory_item, toilet_1.id, toilet_1.health,toilet_1.damage, toilet_1.name, t_skin, t_description_1) == 's'){ //No importa si es array se debe poner sin []
                    fight = false;
                    PlaySound(NULL, 0, 0);
                }
             }
            PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            system("cls");
            drawMapBorders(width, height);
        }
        
        if (player_1.x >= (width - 30) && player_1.x <= (width - 26) && player_1.y >= (height / 5) && player_1.y <= (height / 5) + 1) //Si ´player quiere pisar alguna coordenada de chest retrocedera
        {
             player_1.x = prev_x;
             player_1.y = prev_y;
            player_1.show_player_coord();
        }
        
        if (player_1.x >= (width - 31) && player_1.x <= (width - 25) && player_1.y >= (height / 5) -1 && player_1.y <= (height / 5) + 2 && move == 'q'){
            bool search_item = false;

            for (int i = 0; i < player_1.inventory + 1; i++){
                if (player_1.inventory_item[i] == "Cookie"){
                player_1.add_item("Apple"); 
                search_item = true; 
                break;
                }
            }
            if (search_item == false)
            {
             for (int i = 0; i < player_1.inventory + 1; i++)
                {
                if (player_1.inventory_item[i] != "Cookie"){
                    player_1.add_item("Cookie");
                    break;
                    }                
                }
            }
        }


        if (move == 'e') //Si player presiona e, regresara al menu principal
        {
            player = false;
            system("cls");
            show_menu();
        }

        toilet_1.show_toilet(); //Se volvera a mostrar toilet por si fue pisado por player
        cow_1.show_cow(); //Se volvera a mostrar cow por si fue pisado por player
        show_chest();
    }

}  // El array empieza siempre en 0, cuando se utiliza el 1 aparece el objeto 2;

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