#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "../inf_window.h"
#include "../mutex_key.h"

struct player
{
    int x;
    int y;
    int health;
    int max_health = 20;
    int damage;
    int level;
    std::string name;
    std::string inventory_item[6];
    int inventory;
    player(int x, int y, int health, int max_health, int damage, int inventory, int level,std::string name):
     x(x), y(y), health(health),max_health(max_health), damage(damage), inventory(inventory), level(level), name(name) {}
    
    char player_movement(){
        show_player_coord();
        char move;
        move = getch();
        move = std::tolower(move);
        switch (move)
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        case 'q':
            return 'q'; 
            break;
        case 'e':
            return 'e';
            break;
        case 'g':
            show_inventory();
            break;
        default:
            break;
        }
        show_player_coord();
        return 'p';
    }


    void show_player_coord(){
        int width, height;
        window_size(width, height);
        int static prev_x, prev_y;
        delete_prev_coord(prev_x, prev_y);
        COORD coord;
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "X";
        key_animation.unlock();
        prev_x = x;
        prev_y = y;
    }
    void delete_prev_coord(int prev_x, int prev_y){
        COORD coord;
        key_animation.lock();
        coord.X = prev_x;
        coord.Y = prev_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
    }

    bool add_item(const std::string &item){
        if (inventory < 5)
        {
            inventory_item[inventory++] = item;
            return true;
        }
            return false;
    }

    void show_inventory(){
        for (int i = 0; i < inventory; i++){
            std::cout << inventory_item[i];
        }
    }

    void use_item(const std::string& item_name){
        static bool knife = false;
        for (int i = 0; i < inventory; i++){
            if (inventory_item[i] == item_name)
            {
                if (item_name == "Being sucesfully")
                {
                    //funcion playsound mi compa JAJAJAJ
                }
                if (item_name == "Cookie"){
                    health += 10;
                }
                if (item_name == "Apple"){
                    health += 5;
                }
                if (item_name == "Knife" && knife == false)
                {
                    knife = true;
                    damage = 15;
                }
                if (item_name == "Knife" && knife == true){
                    knife = false;
                    damage = 10;
                }
                if (item_name == "Cake")
                {
                    health += 20;
                }
            }
        }
    }
};






#endif