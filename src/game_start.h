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
#include "enemys_/cat_enemy.h"
#include "enemys_/horse_enemy.h"
#include "enemys_/iguana_enemy.h"
#include "enemys_/pig_enemy.h"
#include "enemys_/sheep_enemy.h"
#include "enemys_/snail_enemy.h"
#include "enemys_/thief_enemy.h"
#include "enemys_/hachi_enemy.h"
#include "enemys_/oscar_enemy.h"
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
    x = (width / 4);
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

    //Cow stats

    int c_x = (width / 2) - 30;
    int c_y = (height / 2) + 10;
    int c_health = 30;
    int c_damage = 7;
    int c_id = 2;
    std::string c_name = "Cow";
    std::string c_skin = "C";
    std::string c_description_1 = "The cow is cowing you!"; 
    std::string c_description_2 = "Moo i'm a cow!";
    std::string c_description_3 = "The cow is exhausted :c"; 
    cow_enemy cow_1(c_health, c_damage,c_x, c_y, c_id, c_name, c_skin, c_description_1, c_description_2, c_description_3);// Coordenadas de cow  

    //Cat stats

    int c_x = (width / 2) - 35;
    int c_y = (height / 2) - 10;
    int c_health = 15;
    int c_damage = 5;
    int c_id = 3;
    std::string c_name = "Cat";
    std::string c_skin = "G";
    std::string c_description_1 = "The cat scratches at you!";
    std::string c_description_2 = "Meow! The cat is angry.";
    std::string c_description_3 = "Nyaaaaa";
    cat_enemy cat_1(c_health, c_damage, c_x, c_y, c_id, c_name, c_skin, c_description_1, c_description_2, c_description_3);

    //Horse stats

    int h_x = (width / 2) + 10;
    int h_y = (height / 2) - 6;
    int h_health = 25;
    int h_damage = 8;
    int h_id = 4;
    std::string h_name = "Horse";
    std::string h_skin = "H";
    std::string h_description_1 = "The horse gallops toward you!";
    std::string h_description_2 = "Its hooves thunder on the ground.";
    std::string h_description_3 = "The horse looks ready to charge.";
    horse_enemy horse_1(h_health, h_damage, h_x, h_y, h_id, h_name, h_skin, h_description_1, h_description_2, h_description_3);

    //Iguana stats

    int i_x = (width / 2) + 20;
    int i_y = (height / 2) + 4;
    int i_health = 15;
    int i_damage = 5;
    int i_id = 5;
    std::string i_name = "Iguana";
    std::string i_skin = "I";
    std::string i_description_1 = "The iguana eyes you suspiciously.";
    std::string i_description_2 = "It flicks its tongue.";
    std::string i_description_3 = "The iguana scurries away quickly.";
    iguana_enemy iguana_1(i_health, i_damage, i_x, i_y, i_id, i_name, i_skin, i_description_1, i_description_2, i_description_3);

    //Pig stats

    int p_x = (width / 2) - 25;
    int p_y = (height / 2) + 5;
    int p_health = 20;
    int p_damage = 9;
    int p_id = 6;
    std::string p_name = "Pig";
    std::string p_skin = "P";
    std::string p_description_1 = "The pig charges at you!";
    std::string p_description_2 = "Oink oink!";
    std::string p_description_3 = "The pig is hungry";
    pig_enemy pig_1(p_health, p_damage, p_x, p_y, p_id, p_name, p_skin, p_description_1, p_description_2, p_description_3);

    //Sheep stats

    int s_x = (width / 2) - 20;
    int s_y = (height / 2) + 8;
    int s_health = 40;
    int s_damage = 5;
    int s_id = 7;
    std::string s_name = "Sheep";
    std::string s_skin = "S";
    std::string s_description_1 = "The sheep jumps at you!";
    std::string s_description_2 = "Meeeee Meeeeee";
    std::string s_description_3 = "The sheep seems confused.";
    sheep_enemy sheep_1(s_health, s_damage, s_x, s_y, s_id, s_name, s_skin, s_description_1, s_description_2, s_description_3);

    //Snail stats

    int sn_x = (width / 2) - 15;
    int sn_y = (height / 2) + 11;
    int sn_health = 12;
    int sn_damage = 6;
    int sn_id = 8;
    std::string sn_name = "Snail";
    std::string sn_skin = "@";
    std::string sn_description_1 = "The snail is slowly approaching...";
    std::string sn_description_2 = "Slime trails everywhere!";
    std::string sn_description_3 = "Snail is dizzy from spinning.";
    snail_enemy snail_1(sn_health, sn_damage, sn_x, sn_y, sn_id, sn_name, sn_skin, sn_description_1, sn_description_2, sn_description_3);

    //Thief stats

    int t_x = (width / 2) + 10;
    int t_y = (height / 2) - 6;
    int t_health = 35;
    int t_damage = 12;
    int t_id = 9;
    std::string t_name = "Thief";
    std::string t_skin = "T";
    std::string t_description_1 = "The thief sneaks behind you! whit a knife";
    std::string t_description_2 = "He tries to steal you";
    std::string t_description_3 = "The thief vanishes in smoke!";
    thief_enemy thief_1(t_health, t_damage, t_x, t_y, t_id, t_name, t_skin, t_description_1, t_description_2, t_description_3);

    //Hachi stats

    int h_x = (width / 2) + 18;
    int h_y = (height / 2) - 10;
    int h_health = 50;
    int h_damage = 15;
    int h_id = 10;
    std::string h_name = "Hachi";
    std::string h_skin = "H";
    std::string h_description_1 = "Hachi growls with loyalty.";
    std::string h_description_2 = "He prepares to defend his master!";
    std::string h_description_3 = "Hachi watches you silently and farts.";
    hachi_enemy hachi_1(h_health, h_damage, h_x, h_y, h_id, h_name, h_skin, h_description_1, h_description_2, h_description_3);

    //Oscar stats

    int o_x = (width / 2) + 15;
    int o_y = (height / 2) + 6;
    int o_health = 80;
    int o_damage = 30;
    int o_id = 11;
    std::string o_name = "Oscar";
    std::string o_skin = "O";
    std::string o_description_1 = "Oscar flexes his muscles!";
    std::string o_description_2 = "You feel intimidated...";
    std::string o_description_3 = "Oscar takes a deep breath.";
    oscar_enemy oscar_1(o_health, o_damage, o_x, o_y, o_id, o_name, o_skin, o_description_1, o_description_2, o_description_3);

    //show enemys 
    Sleep(1000);
    toilet_1.show_toilet(); //show toilet in the game
    cow_1.show_cow();
    cat_1.show_cat();
    horse_1.show_horse();
    iguana_1.show_iguana();
    pig_1.show_pig();
    sheep_1.show_sheep();
    snail_1.show_snail();
    thief_1.show_thief();
    hachi_1.show_hachi();
    oscar_1.show_oscar();
    show_chest();
    drawMapBorders(width, height);
    drawRoomWalls();
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
        drawRoomWalls();
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