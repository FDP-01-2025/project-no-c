#ifndef FIGHTING_SYSTEM_H
#define FIGHTING_SYSTEM_H
#include <iostream>
#include <windows.h>
#include "../inf_window.h"
#include <conio.h>
#include <thread>
#include "fight_interaction.h"
#include "enemy_attack.h"
#include "items_system.h"

std::string item_used;

struct X_menu_options  
{
    int x;
    int y;
    int inventory;
    std::string* inventory_item; // Asterisco para señalar que el puntero es array
    std::string e_name;
    std::string description1;
    X_menu_options(int x, int y,int inventory,std::string* inventory_item, std::string e_name, std::string description1):
    x(x), y(y), inventory(inventory), inventory_item(inventory_item),e_name(e_name), description1(description1) {}

    char movement_x(){
        static bool description_start = false; //static inicializa una sola vez la variable, y si se vuelve a llamar la funcion la variable sigue con un mismo valor
        static std::thread description_thread;
        if (description_start == false)
        {
            description_thread = std::thread(&X_menu_options::enemy_description, this, description1); /*Cuando se pone un thread de un struct
            se debe configurar como (&struct::funcion, argumentos y si es en el mismo struct, this)*/
            description_start = true;
        }
        show_x();
        int width, height;
        window_size(width, height);
        while (_kbhit()){ getch();} // limpia las teclas pendientes 
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
            delete_enemy_description(description1);
            delete_x(x, y);
            description_start = false; // se pone falso, para reiniciar el thread
            x = 12;
            y = (height - 15);
            char menu_fight = x_menu_fight();
            if(menu_fight == 'a'){
                return 'a';
            }
        }
        else if (move == '\r' && x == (((width / 4) - 8)+ 40))
        {
            if (description_thread.joinable())
            {
                description_thread.join();
            }
            delete_x(x, y);
            delete_enemy_description(description1);
            description_start = false;
            x = 12;
            y = (height - 15);
            char menu_item = x_menu_Item();
            if (menu_item == 'b')
            {
                return 'b';
            }
        }
        else if (move == '\r' && x == (((width / 4) - 8) + 80)){
            if (description_thread.joinable())
            {
                description_thread.join();
            }   
            delete_x(x, y);
            delete_enemy_description(description1);
            description_start = false;     
            x = 12;
            y = (height - 15);
            char menu_action = x_menu_Action();
            if (menu_action == 'c')
            {
                return 'c';
            }     
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
        // Ni description_start = false, dado que esto haria que fuera un bucle normal
        show_x();
        return movement_x();
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
//////////////Enemy descriptions /////////////////////////////////  
    void enemy_description(std::string string){
    int width, height, x, y;
    window_size(width, height);
    x = 14;
    y = (height - 15);
    COORD coord;
    for (int i = 0; i < string.length(); i++)
    {
        x++;
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << string[i];
        key_animation.unlock();
        Sleep(20);
    }
    
}

void delete_enemy_description(std::string string){
    int width, height, x, y;
    window_size(width, height);
    x = 14;
    y = (height - 15);
    COORD coord;
    for (int i = 0; i < string.length(); i++)
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
/////////////////////////Show item options////////////////////////////

   void item_name(){
    int width, height, x, y;
    window_size(width, height);
    x = 14;
    y = (height - 15);
    COORD coord;
    bool fifth_item = false;
    for (int a = 0; a < inventory + 1; a++)
    {
        
        for (int i = 0; i < inventory_item[a].length(); i++)
        {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << inventory_item[a][i]; //Poner dos arrays, uno para el item y otro para su cadena string
        key_animation.unlock();
        x++;
        Sleep(15);
        }

        if (fifth_item == true)
        {
            x = 26;
            y += 2;
        }
        else if (y == (height - 11))
        {
            y = (height - 15);
            x = 26;
            fifth_item = true;
        }
        else if (y != (height - 11))
        {
            x = 14;
            y += 2;
        }
        
    }
}

   void delete_item_name(){
    int width, height, x, y;
    window_size(width, height);
    x = 14;
    y = (height - 15);
    COORD coord;
    bool fifth_item = false;
    for (int a = 0; a < inventory + 1; a++)
    {
        
        for (int i = 0; i < inventory_item[a].length(); i++)
        {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " "; //Poner dos arrays, uno para el item y otro para su cadena string
        key_animation.unlock();
        x++;
        }

        if (fifth_item == true)
        {
            x = 26;
            y += 2;
        }
        else if (y == (height - 11))
        {
            y = (height - 15);
            x = 26;
            fifth_item = true;
        }
        else if (y != (height - 11))
        {
            x = 14;
            y += 2;
        }
        
    }
}



//////////////////////////////////Menu fight /////////////////////////////
    char x_menu_fight(){
        static bool enemy_name = false;
        static std::thread thread_name;
        if (enemy_name == false)
        {
            thread_name = std::thread(&X_menu_options::enemy_description, this,e_name);
            enemy_name = true;
        }
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
        if (thread_name.joinable())
        {
            thread_name.join();
        }
            enemy_name = false;
            delete_x(x, y);
            delete_enemy_description(e_name);
            x = ((width / 4) - 8);
            y = (height - 3);
            return 'm';
            break;
        default:
            break;
    }
    if (choose == '\r' && y == (height - 15)){
        if (thread_name.joinable())
        {
            thread_name.join();
        }
        delete_enemy_description(e_name);
        delete_x(x,y);
        enemy_name = false;
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

/////////////ITEM MENU///////////////////////////
char x_menu_Item(){
         static bool item_name_ = false;
         static std::thread item_name_thread;
         if (item_name_ == false)
         {
             item_name_thread = std::thread(item_name, this);
             item_name_ = true;
        }
        
        int width, height, item_x, item_y;
        window_size(width, height);
        show_x_Item();
        char choose;
        choose = getch();
        choose = std::tolower(choose);
        switch (choose)
        {
        case 'w':
            y -= 2;
            break;
        case 's':
            y += 2;
            break;
        case 'a':
            x -= 12;
            break;
        case 'd':
            x += 12;
            break;
        case 'e':
            if (item_name_thread.joinable())
            {
                item_name_thread.join();
            }
            item_name_ = false;
            delete_item_name();
            delete_x(x, y);
            x = (((width / 4) - 8) + 40);
            y = (height - 3);
            return 'm';
            break;
        default:
            break;
    }
    if (choose == '\r' && y == (height - 15)){
        if (item_name_thread.joinable())
        {
                item_name_thread.join();
        }
        item_name_ = false;
        delete_item_name();
        delete_x(x,y);
        int choose = 0;
        item_used = inventory_item[choose];
        return 'b';
    }
    show_x_Item();
    return x_menu_Item();
}
    void show_x_Item(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);
        if(inventory == 0){
        if (y < (height - 15))
            {
            y += 2;
        }
        if(y > (height - 15)){
            y -= 2;    
        }   
        if(x > 12){
            x -= 12;
        }
        if(x < 12){
            x += 12;
        }
        }
        if (inventory == 1)
        {
        if (y < (height - 15))
            {
            y += 2;
        }
        if(y > (height - 15)){
            y -= 2;    
        }   
        if(x > 12){
            x -= 12;
        }
        if(x < 12){
            x += 12;
        }
        }
        if (inventory == 2)
        {
        if (y < (height - 15))
        {
            y += 2;
        }
        if(y > (height - 13)){
            y -= 2;    
        }   
        if(x > 12){
            x -= 12;
        }
        if(x < 12){
            x += 12;
        }
        }
        if (inventory == 3)
        {
        if (y < (height - 15))
            {
            y += 2;
        }
        if(y > (height - 11)){
            y -= 2;    
        }   
        if(x > 12){
            x -= 12;
        }
        if(x < 12){
            x += 12;
        }
        }       
        if (inventory == 4)
        {
        if (y < (height - 15))
            {
            y += 2;
        }
        if(y > (height - 11)){
            y -= 2;    
        }   
        if(y == (height -15) && x > 24){
            x -= 12;
        }
        if(x < 12){
            x += 12;
        }
        if (y != (height -15) && x > 12)
        {
            x -= 12;
        }
        }
        if (inventory == 5){
        if (y < (height - 15))
            {
            y += 2;
        }
        if(y > (height - 11)){
            y -= 2;    
        }   
        if(y >= (height -15) && y <= (height - 13) && x > 24){
            x -= 12;
        }
        if(x < 12){
            x += 12;
        }
        if (y == (height -11) && x > 12)
        {
            x -=12;
        }
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
///////////////////Action menu/////////////////////////////
char x_menu_Action(){
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
        return 'c';
    }
    show_x_fight();
    return x_menu_Action();
}
    void show_x_Action(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (y < height - 15)
        {
            y++;
        }
        if(y > height - 15){
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

char show_options(std::string name, int& level, int& health, int& damage, int inventory,std::string inventory_item[], int id,int& e_health, int& e_damage, std::string e_name, std::string character_skin, std::string description1){ //Cuando se pide un array seutiliza [] sin nada dentro
    int x, y, width, height;
    window_size(width, height);
    x = ((width / 4) - 8);
    y = (height - 3);
    X_menu_options x_options(x, y, inventory,inventory_item, e_name, description1);
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
        //enemy_attack(id, health, e_damage);
        break;
    case 'b':
        use_item(item_used,health,damage);
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