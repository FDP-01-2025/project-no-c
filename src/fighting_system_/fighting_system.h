#ifndef FIGHTING_SYSTEM_H
#define FIGHTING_SYSTEM_H
#include <iostream>
#include <windows.h>
#include "../inf_window.h"
#include <conio.h>
#include <thread>
#include "fight_interaction.h"

struct X_menu_options  
{
    int x;
    int y;
    std::string e_name;
    X_menu_options(int x, int y, std::string e_name):
    x(x), y(y), e_name(e_name) {}

    char movement_x(){
        static bool description_start = false; //static inicializa una sola vez la variable, y si se vuelve a llamar la funcion la variable sigue con un mismo valor
        static std::thread description_thread;
        if (description_start == false)
        {
            description_thread = std::thread(&X_menu_options::enemy_description, this ); /*Cuando se pone un thread de un struct
            se debe configurar como (&struct::funcion, argumentos y si es en el mismo struct, this)*/
            description_start = true;
        }

        while (true) // ciclo while para evitar la recursividad
        {
        
        while (_kbhit()){ getch();} // limpia las teclas pendientes
        
        show_x();
        int width, height;
        window_size(width, height);
        char move = getch();
        move =std::tolower(move);
        switch (move)
        {
        case   'a':
            x -= 40;
            break;
        case 'd':
            x += 40;
            break;
        default:
            break;
        }

        if (move == '\r' && x == ((width / 4) - 8)) 
        {
            if (description_thread.joinable()) /*Para evitar que crashee el programa se debe verificar si el thread
                                                puede hacer join, y para eso es este codigo*/
            {
                description_thread.join();
            }
            delete_enemy_description();
            delete_x(x, y);
            x = 12;
            y = (height - 15);
            description_start = false; // se pone falso, para reiniciar el thread
            if(x_menu_fight() == 'a'){
                return 'a';
            }
        }
        else if (move == '\r' && x == (((width / 4) - 8)+ 40))
        {
            if (description_thread.joinable())
            {
                description_thread.join();
            }
                description_start = false;
            return 'b';
        }
        else if (move == '\r' && x == (((width / 4) - 8) + 80)){
            if (description_thread.joinable())
            {
                description_thread.join();
            }   
                description_start = false;         
            return 'c';
        }
        else if (move == '\r' && x == ((width / 4) - 8) + 120){
            if (description_thread.joinable())
            {
                description_thread.join();
            }            
            description_start = false;
            return 'd';
        }
        // No se pone los anteriores casos de joinable, ya que esto haria que no se viera la descripcion
        show_x();
        }
    }
    
    void show_x(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (x < ((width / 4) - 10))
        {
            x += 40;
        }
        if(x > ((width / 4) + 120)){
            x -= 40;
        }
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
    void delete_x(int x, int y){
        COORD coord;
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
    }

    void enemy_description(){
    int width, height, x, y;
    window_size(width, height);
    x = 14;
    y = (height - 15);
    COORD coord;
    for (int i = 0; i < e_name.length(); i++)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << e_name[i];
        key_animation.unlock();
        Sleep(100);
    }
    
}

void delete_enemy_description(){
    int width, height, x, y;
    window_size(width, height);
    x = 14;
    y = (height - 15);
    COORD coord;
    for (int i = 0; i < e_name.length(); i++)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
    }
    
}

    char x_menu_fight(){
        int width, height;
        window_size(width, height);
        show_x_fight();
        char choose;
        choose = getch();
        choose = std::tolower(choose);
        switch (choose)
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'e':
            delete_x(x, y);
            x = ((width / 4) - 8);
            y = (height - 3);
            return 'm';
            break;
        default:
            break;
    }
    if (choose == '\r' && y == (height - 15)){
        delete_x(x,y);
        return 'a';
    }
    show_x_fight();
    return x_menu_fight();
}
    void show_x_fight(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (y < height - 15)
        {
            y++;
        }
        if(y > height - 14){
            y--;
        }
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

};


void show_options_fighting(){
    int width, height, x, y;
    std::string fight;
    fight = "FIGHT";
    window_size(width, height);
    x = (width / 4) - fight.length();
    y = (height) - 3;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << fight;
    key_animation.unlock();
}

void show_options_items(){
    int width, height, x, y;
    std::string items;
    items = "ITEMS";
    window_size(width, height);
    x = ((width / 4) + 40) - items.length();
    y = (height) - 3;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << items;
    key_animation.unlock();
}

void show_options_actions(){
    int width, height, x, y;
    std::string actions;
    actions = "ACTIONS";
    window_size(width, height);
    x = ((width / 4) + 82) - actions.length();
    y = (height) - 3;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << actions;
    key_animation.unlock();
}

void show_options_run(){
    int width, height, x, y;
    std::string run;
    run = "RUN";
    window_size(width, height);
    x = ((width / 4) + 118) - run.length();
    y = (height) - 3;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << run;
    key_animation.unlock();
}

void show_square_option_top(){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) - 10);
    y = (height - 5);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}
void show_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) - 11);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) + 4);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_option_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) - 10);
    y = (height - 1);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

//////////////////////////////////////////////////////////////////////////////

void show_square_Item_top(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 40) - 10);
    y = (height - 5);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}
void show_square_Item_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 40) - 11);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_Item_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 40) + 4);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_Item_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 40) - 10);
    y = (height - 1);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}


void show_square_item(){ //show cuadro item
    show_square_Item_top();
    show_square_Item_bottom();
    show_square_Item_left_side();
    show_square_Item_right_side();
}

///////////////////////////////////////////////////////

void show_square_Action_top(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 80) - 10);
    y = (height - 5);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}
void show_square_Action_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 80) - 11);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_Action_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 80) + 4);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_Action_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 80) - 10);
    y = (height - 1);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}


void show_square_Action(){ //show cuadro action
    show_square_Action_top();
    show_square_Action_bottom();
    show_square_Action_left_side();
    show_square_Action_right_side();
}

//////////////////////////////////

void show_square_Run_top(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 120) - 10);
    y = (height - 5);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}
void show_square_Run_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 120) - 11);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_Run_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 120) + 4);
    y = (height - 5);
    COORD coord;
    coord.X = x;
    for (int i = 0; i < 5; i++){
        key_animation.lock();
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_square_Run_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = (((width / 4) + 120) - 10);
    y = (height - 1);
    COORD coord;
    coord.Y = y;
    for (int i = 0; i < 14 ; i++){
        key_animation.lock();
        coord.X = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}


void show_square_Run(){ //show cuadro run
    show_square_Run_top();
    show_square_Run_bottom();
    show_square_Run_left_side();
    show_square_Run_right_side();
}

//////////////////////////////////////////////////////////////

void show_square_option(){ //show cuadro fight
    show_square_option_top();
    show_square_option_bottom();
    show_square_left_side();
    show_square_right_side();
}

void big_square_bottom(){
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
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void big_square_top(){
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
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void big_square_right_side(){
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
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void big_square_left_side(){
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
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void square_line(){
    big_square_bottom();
    big_square_top();
    big_square_right_side();
    big_square_left_side();
}

void player_name(std::string name){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 5) - 8);
    y = (height) - 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << name;
    key_animation.unlock();
}

void player_level(int level){
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) + 10);
    y = (height) - 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "Level: " << level;
    key_animation.unlock();
}

void player_health(int health){
    const int max_health = health;
    int width, height, x, y;
    window_size(width, height);
    x = ((width / 4) + 30);
    y = (height) - 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << health << "/" << max_health;
    key_animation.unlock();
}


void player_(std::string name,int level, int health){
    player_name(name);
    player_level(level);
    player_health(health);
}

void show_enemy(std::string enemy_skin){
    int width, height;
    window_size(width, height);
    int x = (width / 2);
    int y = (height / 2);
    COORD coord;
    key_animation.lock();
    coord.X = x;    
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << enemy_skin;
    key_animation.unlock();
}

char show_options(std::string name, int level, int& health, int& damage, int& e_health, std::string e_name, std::string character_skin){
    int x, y, width, height;
    window_size(width, height);
    x = ((width / 4) - 8);
    y = (height - 3);
    X_menu_options x_options(x, y, e_name);
    system("cls");
    Sleep(1000);
    std::thread thread_line(square_line);
    std::thread thread_square1(show_square_option);
    player_(name, level, health);
    show_options_fighting();
    thread_square1.join();
    thread_line.join();
    Sleep(100);
    std::thread thread_square_item(show_square_item);
    show_options_items();
    thread_square_item.join();
    Sleep(100);
    std::thread thread_square_action(show_square_Action);
    show_options_actions();
    thread_square_action.join();
    Sleep(100);
    std::thread thread_square_run(show_square_Run);
    show_options_run();
    thread_square_run.join();
    Sleep(100);
    show_enemy(character_skin);
    switch (x_options.movement_x())
    {
    case 'a':
        player_attack(damage, e_health);
        break;
    case 'b':
        break;
    case 'c':

        break;
    case 'd':

        return 's';
        break;
    default:
        break;
    }
    
    return 'o';
}



#endif