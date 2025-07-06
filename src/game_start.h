#ifndef GAME_START_H
#define GAME_START_H
#include "dialogues.h"
#include "inf_window.h"
#include "mutex_key.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "player_/player.h"
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
#include "maps_/river.h"
#include "../saves/save_system.h"
#include "show_player_options.h"
#include "fighting_system_/experience_system.h"

extern bool verify_music;

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
    int t_ex = 2;
    window_size(width, height);
    x = (width / 12);
    y = (height / 4);
    health = 20;
    int max_health = 20;
    damage = 10;
    int inventory = 0;
    int experience = 0;
    player player_1(x, y, health, max_health, damage, inventory,player_level, experience, player_name); // da las coordenadas de player
    t_x = (width / 2) + 10;
    t_y = (height / 2) - 3;
    std::string t_name = "Toilet";
    std::string t_skin = "L";
    std::string t_description_1 = "Toilet wanna fight!";
    //toilet toilet_1(t_x, t_y, t_health, t_damage, t_id, t_name,t_skin, t_description_1); // da las coordenadas de toilet

    int left_limit   = 5;                     
    int right_limit  = width - 6;      
    int top_limit    = 3;                     
    int bottom_limit = height - 4;     

    int room_left = width / 4;
    int room_top = height / 4;
    int room_right = room_left + 20;
    int room_bottom = room_top + 8;
    int door_y = (room_top + room_bottom) / 2;

    //Cow stats

    int c_x = (width / 2) - 30;
    int c_y = (height / 2) + 10;
    int c_health = 30;
    int c_damage = 7;
    int c_id = 2;
    int c_ex = 5;
    std::string c_name = "Cow";
    std::string c_skin = "C";
    std::string c_description_1 = "The cow is cowing you!"; 
    std::string c_description_2 = "The cow is exhausted :c ";
    std::string c_description_3 = "Moo i'm a cow!"; 
    cow_enemy cow_1(c_health, c_damage,c_x, c_y, c_id,c_ex, c_name, c_skin, c_description_1, c_description_2, c_description_3);// Coordenadas de cow  

    //Cat stats

    int ca_x = (width / 2) - 35;
    int ca_y = (height / 2) - 10;
    int ca_health = 15;
    int ca_damage = 5;
    int ca_id = 3;
    int ca_ex = 3;
    std::string ca_name = "Cat";
    std::string ca_skin = "G";
    std::string ca_description_1 = "The cat scratches at you!";
    std::string ca_description_2 = "Meow! The cat is angry.";
    std::string ca_description_3 = "Nyaaaaa";
    cat_enemy cat_1(ca_health, ca_damage, ca_x, ca_y, ca_id, ca_ex, ca_name, ca_skin, ca_description_1, ca_description_2, ca_description_3);

    //Horse stats

    int h_x = (width / 2) + 10;
    int h_y = (height / 2) - 6;
    int h_health = 25;
    int h_damage = 8;
    int h_id = 4;
    int h_ex = 6;
    std::string h_name = "Horse";
    std::string h_skin = "H";
    std::string h_description_1 = "The horse gallops toward you!";
    std::string h_description_2 = "Its hooves thunder on the ground.";
    std::string h_description_3 = "The horse looks ready to charge.";
    horse_enemy horse_1(h_health, h_damage, h_x, h_y, h_id, h_ex, h_name, h_skin, h_description_1, h_description_2, h_description_3);

    //Iguana stats

    int i_x = 25;
    int i_y = 10;
    int i_health = 15;
    int i_damage = 5;
    int i_id = 5;
    int i_ex = 3;
    std::string i_name = "Iguana";
    std::string i_skin = "I";
    std::string i_description_1 = "The iguana eyes you suspiciously.";
    std::string i_description_2 = "It flicks its tongue.";
    std::string i_description_3 = "The iguana scurries away quickly.";
    iguana_enemy iguana_1(i_health, i_damage, i_x, i_y, i_id, i_ex, i_name, i_skin, i_description_1, i_description_2, i_description_3);

    //Pig stats

    int p_x = (width / 2) - 25;
    int p_y = (height / 2) + 5;
    int p_health = 20;
    int p_damage = 9;
    int p_id = 6;
    int p_ex = 4;
    std::string p_name = "Pig";
    std::string p_skin = "P";
    std::string p_description_1 = "The pig charges at you!";
    std::string p_description_2 = "Oink oink!";
    std::string p_description_3 = "The pig is hungry";
    pig_enemy pig_1(p_health, p_damage, p_x, p_y, p_id, p_ex, p_name, p_skin, p_description_1, p_description_2, p_description_3);

    //Sheep stats

    int s_x = (width / 2) - 20;
    int s_y = (height / 2) + 8;
    int s_health = 40;
    int s_damage = 5;
    int s_id = 7;
    int s_ex = 5;
    std::string s_name = "Sheep";
    std::string s_skin = "S";
    std::string s_description_1 = "The sheep jumps at you!";
    std::string s_description_2 = "Meeeee Meeeeee";
    std::string s_description_3 = "The sheep seems confused.";
    sheep_enemy sheep_1(s_health, s_damage, s_x, s_y, s_id, s_ex, s_name, s_skin, s_description_1, s_description_2, s_description_3);

    //Snail stats

    int sn_x = (width / 2) - 15;
    int sn_y = (height / 2) + 11;
    int sn_health = 12;
    int sn_damage = 6;
    int sn_id = 8;
    int sn_ex = 2;
    std::string sn_name = "Snail";
    std::string sn_skin = "@";
    std::string sn_description_1 = "The snail is slowly approaching...";
    std::string sn_description_2 = "Slime trails everywhere!";
    std::string sn_description_3 = "Snail is dizzy from spinning.";
    snail_enemy snail_1(sn_health, sn_damage, sn_x, sn_y, sn_id, sn_ex, sn_name, sn_skin, sn_description_1, sn_description_2, sn_description_3);

    //Thief stats

    int th_x = (width / 2) + 10;
    int th_y = (height / 2) - 6;
    int th_health = 35;
    int th_damage = 12;
    int th_id = 9;
    int th_ex = 6;
    std::string th_name = "Thief";
    std::string th_skin = "T";
    std::string th_description_1 = "The thief sneaks behind you! whit a knife";
    std::string th_description_2 = "He tries to steal you";
    std::string th_description_3 = "The thief vanishes in smoke!";
    thief_enemy thief_1(th_health, th_damage, th_x, th_y, th_id, th_ex, th_name, th_skin, th_description_1, th_description_2, th_description_3);

    //Hachi stats

    int ha_x = (width / 2) + 18;
    int ha_y = (height / 2) - 10;
    int ha_health = 50;
    int ha_damage = 15;
    int ha_id = 10;
    int ha_ex = 5;
    std::string ha_name = "Hachi";
    std::string ha_skin = "HA";
    std::string ha_description_1 = "Hachi growls with loyalty.";
    std::string ha_description_2 = "He prepares to defend his master!";
    std::string ha_description_3 = "Hachi watches you silently and farts.";
    hachi_enemy hachi_1(ha_health, ha_damage, ha_x, h_y, ha_id, ha_ex,ha_name, ha_skin, ha_description_1, ha_description_2, ha_description_3);

    //Oscar stats

    int o_x = (width / 2) + 15;
    int o_y = (height / 2) + 6;
    int o_health = 120;
    int o_damage = 30;
    int o_id = 11;
    int o_ex = 50;
    std::string o_name = "Oscar";
    std::string o_skin = "O";
    std::string o_description_1 = "Oscar flexes his muscles!";
    std::string o_description_2 = "You feel intimidated...";
    std::string o_description_3 = "Oscar takes a deep breath.";
    oscar_enemy oscar_1(o_health, o_damage, o_x, o_y, o_id, o_ex, o_name, o_skin, o_description_1, o_description_2, o_description_3);

    //show enemys 
    Sleep(1000);
    //toilet_1.show_toilet(); //show toilet in the game
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
    river();
    
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

        // if (player_1.x == toilet_1.x && player_1.y == toilet_1.y) //Si el jugador llega a las mismas coordendas de toilet retrocedera
        // {
        //     player_1.x = prev_x;
        //     player_1.y = prev_y;
        //     player_1.show_player_coord();
        // }
        
        bool is_inside_room_x = player_1.x > room_left && player_1.x < room_right;
        bool is_inside_room_y = player_1.y > room_top && player_1.y < room_bottom;
        bool is_door = player_1.x == room_left && player_1.y == door_y;

    if ((player_1.y == room_top || player_1.y == room_bottom) && is_inside_room_x) {
            player_1.x = prev_x;
            player_1.y = prev_y;
             player_1.show_player_coord();
        }
    if ((player_1.x == room_left || player_1.x == room_right) && is_inside_room_y && !is_door) {
            player_1.x = prev_x;
            player_1.y = prev_y;
            player_1.show_player_coord();
        }


        // if (std::abs(player_1.x - toilet_1.x) <= 1 && std::abs(player_1.y - toilet_1.y) <= 1) // Si player esta a 1 coordenada de toilet y presiona q, entonces pelearan
        // {
        //     PlaySound(NULL, 0, 0);
        //     PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"),NULL, SND_SYNC | SND_FILENAME);
        //     PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        //     //Sleep(800);
        //     player = false; // se detiene el ciclo player
        //     toilet_1.health = 30; // vida base de toilet
        //     bool fight = true; // inicio ciclo pelea
        //      while (toilet_1.health > 0 && fight == true)
        //      {  
        //         if (show_options(player_1.name,player_1.level,player_1.health, player_1.max_health, player_1.damage, player_1.inventory,player_1.inventory_item, toilet_1.id, toilet_1.health,toilet_1.damage, toilet_1.name, t_skin, t_description_1) == 's'){ //No importa si es array se debe poner sin []
        //             fight = false;
        //             PlaySound(NULL, 0, 0);
        //         }
        //      }
        //     PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        //     system("cls");
        //     drawMapBorders(width, height);
        // }
        
        //Cow

        if (player_1.x == cow_1.x && player_1.y == cow_1.y) 
        {
            player_1.x = prev_x;
            player_1.y = prev_y;
            player_1.show_player_coord();
            cow_1.show_cow();
        }


        if (std::abs(player_1.x - cow_1.x) <= 1 && std::abs(player_1.y - cow_1.y) <= 1) // Si player esta a 1 coordenada de cow, entonces pelearan
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"),NULL, SND_SYNC | SND_FILENAME);
            PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            //Sleep(800);
            player = false; // se detiene el ciclo player
            bool fight = true; // inicio ciclo pelea
             while (cow_1.healht > 0 && fight == true)
             {  
                if (show_options(player_1.name,player_1.level,player_1.health,player_1.max_health,player_1.damage,player_1.experience, player_1.inventory,player_1.inventory_item, cow_1.id, cow_1.experience, cow_1.healht,cow_1.damage, cow_1.name, cow_1.character_skin, cow_1.description1) == 's'){ //No importa si es array se debe poner sin []
                    fight = false;
                    PlaySound(NULL, 0, 0);
                }
             }
            PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            system("cls");
            if (cow_1.healht <= 0)
            {
                level_up(player_1);
                cow_1.x = 0;
                cow_1.y = 0;
            }
            drawMapBorders(width, height);
        }

        //Cat

        if (player_1.x == cat_1.x && player_1.y == cat_1.y) 
        {
            player_1.x = prev_x;
            player_1.y = prev_y;
            player_1.show_player_coord();
            cat_1.show_cat();
        }


        if (std::abs(player_1.x - cat_1.x) <= 1 && std::abs(player_1.y - cat_1.y) <= 1) // Si player esta a 1 coordenada de cow, entonces pelearan
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"),NULL, SND_SYNC | SND_FILENAME);
            PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            //Sleep(800);
            player = false; // se detiene el ciclo player
            bool fight = true; // inicio ciclo pelea
             while (cat_1.healht > 0 && fight == true)
             {  
                if (show_options(player_1.name,player_1.level,player_1.health,player_1.max_health,player_1.damage,player_1.experience, player_1.inventory,player_1.inventory_item, cat_1.id,cat_1.experience, cat_1.healht,cat_1.damage, cat_1.name, cat_1.character_skin, cat_1.description1) == 's'){ //No importa si es array se debe poner sin []
                    fight = false;
                    PlaySound(NULL, 0, 0);
                }
             }

            PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            system("cls");
            if (cat_1.healht <= 0)
            {
                level_up(player_1);
                cat_1.x = 0;
                cat_1.y = 0;
            }
            drawMapBorders(width, height);
        }

        // Hachi

        if (player_1.x == hachi_1.x && player_1.y == hachi_1.y) 
        {
            player_1.x = prev_x;
            player_1.y = prev_y;
            player_1.show_player_coord();
            hachi_1.show_hachi();
        }


        if (std::abs(player_1.x - hachi_1.x) <= 1 && std::abs(player_1.y - hachi_1.y) <= 1) // Si player esta a 1 coordenada de cow, entonces pelearan
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"),NULL, SND_SYNC | SND_FILENAME);
            PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            //Sleep(800);
            player = false; // se detiene el ciclo player
            bool fight = true; // inicio ciclo pelea
             while (hachi_1.healht > 0 && fight == true)
             {  
                if (show_options(player_1.name,player_1.level,player_1.health,player_1.max_health,player_1.damage,player_1.experience, player_1.inventory,player_1.inventory_item, hachi_1.id, hachi_1.experience,hachi_1.healht,hachi_1.damage, hachi_1.name, hachi_1.character_skin, hachi_1.description1) == 's'){ //No importa si es array se debe poner sin []
                    fight = false;
                    PlaySound(NULL, 0, 0);
                }
             }

            PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            system("cls");
            if (hachi_1.healht <= 0)
            {
                level_up(player_1);
                hachi_1.x = 0;
                hachi_1.y = 0;
            }
            drawMapBorders(width, height);
        }

        //thief

        if (player_1.x == thief_1.x && player_1.y == thief_1.y) 
        {
            player_1.x = prev_x;
            player_1.y = prev_y;
            player_1.show_player_coord();
            thief_1.show_thief();
        }


        if (std::abs(player_1.x - thief_1.x) <= 1 && std::abs(player_1.y - thief_1.y) <= 1) // Si player esta a 1 coordenada de cow, entonces pelearan
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"),NULL, SND_SYNC | SND_FILENAME);
            PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            //Sleep(800);
            player = false; // se detiene el ciclo player
            bool fight = true; // inicio ciclo pelea
             while (thief_1.healht > 0 && fight == true)
             {  
                if (show_options(player_1.name,player_1.level,player_1.health,player_1.max_health,player_1.damage,player_1.experience, player_1.inventory,player_1.inventory_item, thief_1.id,thief_1.experience, thief_1.healht,thief_1.damage, thief_1.name, thief_1.character_skin, thief_1.description1) == 's'){ //No importa si es array se debe poner sin []
                    fight = false;
                    PlaySound(NULL, 0, 0);
                }
             }

            PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            system("cls");
            if (thief_1.healht <= 0)
            {
                level_up(player_1);
                thief_1.x = 0;
                thief_1.y = 0;
            }
            drawMapBorders(width, height);
        }

        //horse

        if (player_1.x == horse_1.x && player_1.y == horse_1.y)  
{
    player_1.x = prev_x;
    player_1.y = prev_y;
    player_1.show_player_coord();
    horse_1.show_horse();
}

if (std::abs(player_1.x - horse_1.x) <= 1 && std::abs(player_1.y - horse_1.y) <= 1) // If player is 1 tile away from horse, they will fight
{
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"), NULL, SND_SYNC | SND_FILENAME);
    PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

    player = false; // stop player loop
    bool fight = true; // start fight loop

    while (horse_1.healht > 0 && fight == true)
    {  
        if (show_options(player_1.name, player_1.level, player_1.health, player_1.max_health, player_1.damage, player_1.experience, player_1.inventory, player_1.inventory_item, horse_1.id, horse_1.experience, horse_1.healht, horse_1.damage, horse_1.name, horse_1.character_skin, horse_1.description1) == 's')
        {
            fight = false;
            PlaySound(NULL, 0, 0);
        }
    }

    PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    system("cls");

    if (horse_1.healht <= 0)
    {
        level_up(player_1);
        horse_1.x = 0;
        horse_1.y = 0;
    }

    drawMapBorders(width, height);
}
        //iguana

if (player_1.x == iguana_1.x && player_1.y == iguana_1.y)
{
    player_1.x = prev_x;
    player_1.y = prev_y;
    player_1.show_player_coord();
    iguana_1.show_iguana();
}

if (std::abs(player_1.x - iguana_1.x) <= 1 && std::abs(player_1.y - iguana_1.y) <= 1)
{
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"), NULL, SND_SYNC | SND_FILENAME);
    PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    player = false;
    bool fight = true;
    while (iguana_1.healht > 0 && fight == true)
    {
        if (show_options(player_1.name, player_1.level, player_1.health, player_1.max_health, player_1.damage, player_1.experience, player_1.inventory, player_1.inventory_item, iguana_1.id, iguana_1.experience, iguana_1.healht, iguana_1.damage, iguana_1.name, iguana_1.character_skin, iguana_1.description1) == 's')
        {
            fight = false;
            PlaySound(NULL, 0, 0);
        }
    }
    PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    system("cls");
    if (iguana_1.healht <= 0)
    {
        level_up(player_1);
        iguana_1.x = 0;
        iguana_1.y = 0;
    }
    drawMapBorders(width, height);
}

// PIG
if (player_1.x == pig_1.x && player_1.y == pig_1.y)
{
    player_1.x = prev_x;
    player_1.y = prev_y;
    player_1.show_player_coord();
    pig_1.show_pig();
}

if (std::abs(player_1.x - pig_1.x) <= 1 && std::abs(player_1.y - pig_1.y) <= 1)
{
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"), NULL, SND_SYNC | SND_FILENAME);
    PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    player = false;
    bool fight = true;
    while (pig_1.healht > 0 && fight == true)
    {
        if (show_options(player_1.name, player_1.level, player_1.health, player_1.max_health, player_1.damage, player_1.experience, player_1.inventory, player_1.inventory_item, pig_1.id, pig_1.experience, pig_1.healht, pig_1.damage, pig_1.name, pig_1.character_skin, pig_1.description1) == 's')
        {
            fight = false;
            PlaySound(NULL, 0, 0);
        }
    }
    PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    system("cls");
    if (pig_1.healht <= 0)
    {
        level_up(player_1);
        pig_1.x = 0;
        pig_1.y = 0;
    }
    drawMapBorders(width, height);
}

// SHEEP
if (player_1.x == sheep_1.x && player_1.y == sheep_1.y)
{
    player_1.x = prev_x;
    player_1.y = prev_y;
    player_1.show_player_coord();
    sheep_1.show_sheep();
}

if (std::abs(player_1.x - sheep_1.x) <= 1 && std::abs(player_1.y - sheep_1.y) <= 1)
{
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"), NULL, SND_SYNC | SND_FILENAME);
    PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    player = false;
    bool fight = true;
    while (sheep_1.healht > 0 && fight == true)
    {
        if (show_options(player_1.name, player_1.level, player_1.health, player_1.max_health, player_1.damage, player_1.experience, player_1.inventory, player_1.inventory_item, sheep_1.id, sheep_1.experience, sheep_1.healht, sheep_1.damage, sheep_1.name, sheep_1.character_skin, sheep_1.description1) == 's')
        {
            fight = false;
            PlaySound(NULL, 0, 0);
        }
    }
    PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    system("cls");
    if (sheep_1.healht <= 0)
    {
        level_up(player_1);
        sheep_1.x = 0;
        sheep_1.y = 0;
    }
    drawMapBorders(width, height);
}

// SNAIL
if (player_1.x == snail_1.x && player_1.y == snail_1.y)
{
    player_1.x = prev_x;
    player_1.y = prev_y;
    player_1.show_player_coord();
    snail_1.show_snail();
}

if (std::abs(player_1.x - snail_1.x) <= 1 && std::abs(player_1.y - snail_1.y) <= 1)
{
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"), NULL, SND_SYNC | SND_FILENAME);
    PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    player = false;
    bool fight = true;
    while (snail_1.healht > 0 && fight == true)
    {
        if (show_options(player_1.name, player_1.level, player_1.health, player_1.max_health, player_1.damage, player_1.experience, player_1.inventory, player_1.inventory_item, snail_1.id, snail_1.experience, snail_1.healht, snail_1.damage, snail_1.name, snail_1.character_skin, snail_1.description1) == 's')
        {
            fight = false;
            PlaySound(NULL, 0, 0);
        }
    }
    PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    system("cls");
    if (snail_1.healht <= 0)
    {
        level_up(player_1);
        snail_1.x = 0;
        snail_1.y = 0;
    }
    drawMapBorders(width, height);
}

// OSCAR

if (player_1.x == oscar_1.x && player_1.y == oscar_1.y)
{
    player_1.x = prev_x;
    player_1.y = prev_y;
    player_1.show_player_coord();
    oscar_1.show_oscar();
}

if (std::abs(player_1.x - oscar_1.x) <= 1 && std::abs(player_1.y - oscar_1.y) <= 1)
{
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("assets//music//Undertale-Sound-Effect-Battle-Encounter-_wMfDRVsiuTs_.wav"), NULL, SND_SYNC | SND_FILENAME);
    PlaySound(TEXT("assets//music//Undertale-Papyrus-Theme-Song-Bonetrousle-_FezNgPThD3M_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    player = false;
    bool fight = true;
    while (oscar_1.healht > 0 && fight == true)
    {
        if (show_options(player_1.name, player_1.level, player_1.health, player_1.max_health, player_1.damage, player_1.experience, player_1.inventory, player_1.inventory_item, oscar_1.id, oscar_1.experience, oscar_1.healht, oscar_1.damage, oscar_1.name, oscar_1.character_skin, oscar_1.description1) == 's')
        {
            fight = false;
            PlaySound(NULL, 0, 0);
        }
    }
    PlaySound(TEXT("assets//music//Snowy-_BJEqdto_uGw_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    system("cls");
    if (oscar_1.healht <= 0)
    {
        level_up(player_1);
        oscar_1.x = 0;
        oscar_1.y = 0;
    }
    drawMapBorders(width, height);
}

        //Chest

        if (player_1.x >= (width - 30) && player_1.x <= (width - 26) && player_1.y >= (height / 5) && player_1.y <= (height / 5) + 1) //Si ´player quiere pisar alguna coordenada de chest retrocedera
        {
             player_1.x = prev_x;
             player_1.y = prev_y;
            player_1.show_player_coord();
        }
        
        if (player_1.x >= (width - 31) && player_1.x <= (width - 25) && player_1.y >= (height / 5) -1 && player_1.y <= (height / 5) + 2 && move == 'q'){
            dialogue_square();
            bool search_item = false;
            for (int i = 0; i < player_1.inventory + 1; i++){
                if (player_1.inventory_item[i] == "Cookie"){
                player_1.add_item("Apple"); 
                center_dialogue("You got a Apple!");
                finish_dialogue();
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
                    center_dialogue("You got a Cookie!");
                    finish_dialogue();
                    break;
                    }                
                }
            }
            drawMapBorders(width, height);
        }


        if (move == 'e') //Si player presiona e, regresara al menu principal
        //TEST! si player presiona e saldra cuadro de SAVES
        {
            player = false;
            char player_options = show_player_options(player_1,player_1.inventory, player_1.inventory_item);
            switch (player_options)
            {
            case 'a':
                delete_square_show_options();
                delete_options_();
                drawMapBorders(width, height);
                continue;
                break;
            case 'b':
                delete_square_show_options();
                delete_options_();
                drawMapBorders(width, height);   
                continue;  
                break;
            case 'c':
                //Codigo calles de guardar partida
                break;
            case 'd':
                system("cls");
                PlaySound(NULL, 0, 0);
                verify_music = true;
                verify_raining = true;
                show_menu();
                break;
            default:
                break;
            }
        }

        //toilet_1.show_toilet(); //Se volvera a mostrar toilet por si fue pisado por player
        cow_1.show_cow(); //Se volvera a mostrar cow por si fue pisado por player
        show_chest();
        river();
        cat_1.show_cat();
        horse_1.show_horse();
        iguana_1.show_iguana();
        pig_1.show_pig();
        sheep_1.show_sheep();
        snail_1.show_snail();
        thief_1.show_thief();
        hachi_1.show_hachi();
        oscar_1.show_oscar();
        //drawRoomWalls();
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