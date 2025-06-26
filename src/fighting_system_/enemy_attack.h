#ifndef ENEMY_ATTACK_H
#define ENEMY_ATTACK_H
#include <windows.h>
#include <iostream>
#include "../inf_window.h"
#include "fighting_system.h"

/////////////// continuar mas tarde
#define MAX_PROJECTILES 30 //Define que los proyectiles maximos de cualquier ataque seran 30

struct Projectile {
    int x, y;
    bool active; 
};

Projectile projectiles[MAX_PROJECTILES]; // definimos como arreglo simple

struct enemy_attack_X
{
    int x;
    int y;
    int health;
    int e_damage;
    enemy_attack_X(int x, int y, int health, int e_damage):
        x(x), y(y), health(health), e_damage(e_damage) {}
    
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
        default:
            break;
        }
        show_player_coord();
        return player_movement();
    }


    void show_player_coord(){
        int width, height;
        window_size(width, height);
        int static prev_x, prev_y;
        delete_prev_coord(prev_x, prev_y);
        COORD coord;
        if (x < 70)
        {
            x++;
        }
        if (x > width - 72){
            x--;
        }
        if (y > height - 10){
            y--;
        }
        if (y < height - 16){
            y++;
        }
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
};

void delete_big_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 10;
    y = (height - 9);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < width -20 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        x++;
    }
}

void delete_big_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 10;
    y = (height - 17);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < width -20 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        x++;
    }
}

void delete_big_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 9;
    y = (height - 17);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 9; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_big_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (width) - 10;
    y = (height - 17);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 9; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_big_square(){
    delete_big_square_bottom();
    delete_big_square_top();
    delete_big_square_right_side();
    delete_big_square_left_side();
}

/////////////////////////////////////////

void fight_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 70;
    y = (height - 9);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < width -140 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void fight_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 70;
    y = (height - 17);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < width -140 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void fight_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 69;
    y = (height - 17);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 9; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void fight_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (width) - 71;
    y = (height - 17);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 9; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void fight_square(){
    fight_square_bottom();
    fight_square_top();
    fight_square_right_side();
    fight_square_left_side();
}

void show_enemy(std::string enemy_skin);

void projectiles_init(){ // Inicializamos la variable active para cada proyectil en False
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        projectiles[i].active = false;   
    }
}

void spawn_projectiles(int min_x, int max_x, int y){
    srand(time(0));
    for (int i = 0; i < MAX_PROJECTILES; i++){
        if (projectiles[i].active == false)
        {
            projectiles[i].x = min_x + rand() % (max_x - min_x);
            projectiles[i].y = y;
            projectiles[i].active = true;
            break;
        }
    }
}

void update_projectiles(int max_y){
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (projectiles[i].active)
        {
            projectiles[i].y++;
            if (projectiles[i].y > max_y){
            projectiles[i].active = false;
        }     
        }   
    }
}

void delete_prev_projectile(int x, int y){
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << " ";
    key_animation.unlock();
}


void show_projectiles(){
    int width, height;
    window_size(width, height);
    int prev_x, prev_y;
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        while (projectiles[i].active && projectiles[i].y != (height-9))
        {
            delete_prev_projectile(prev_x, prev_y);
            projectiles[i].y++;
            COORD coord;
            key_animation.lock();
            coord.X = projectiles[i].x;
            coord.Y = projectiles[i].y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << "+"; 
            key_animation.unlock();
            Sleep(800);
            prev_x = projectiles[i].x;
            prev_y = projectiles[i].y;
        }
    }   
}


bool player_collision(int player_x, int player_y){
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (projectiles[i].active && projectiles[i].x == player_x && projectiles[i].y == player_y);
        {
            return true;
        }
    }
    return false;    
}


void enemy_attack(int id, int& health,int& e_damage){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2);
    y = (height / 2 + 12);
    enemy_attack_X player_fight(x, y, health, e_damage);
    switch (id)
    {
    case 1:
        projectiles_init();
        delete_big_square();
        show_enemy("L");
        fight_square();
        while (projectiles->x != player_fight.x && projectiles->y != player_fight.y)
        {
            spawn_projectiles(69,(width - 71),(height - 17));
            update_projectiles(height - 10);
            std::thread thread_projectiles(show_projectiles);
            player_fight.player_movement();
            if (player_collision(player_fight.x, player_fight.y) == true)
            {
                health = health - e_damage; 
            }
            
        }
        /* code */
        break;
    
    default:
        break;
    }
    
}






#endif