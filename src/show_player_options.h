#ifndef SHOW_PLAYER_OPTIONS_H
#define SHOW_PLAYER_OPTIONS_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "inf_window.h"
#include "player_/player.h"
#include "fighting_system_/items_system.h"

struct X_menu_player_option
{
    int x;
    int y;
    int& inventory;
    std::string* inventory_items;
    X_menu_player_option(int x, int y, int& inventory, std::string* inventory_items):
    x(x), y(y), inventory(inventory), inventory_items(inventory_items) {}

    char movement_x(){
        show_x();
        int width, height;
        window_size(width, height);
        char move;
        move = getch();
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
        if (move == '\r' && x == (width / 4))
        {
            return 'a';
        }
        else if (move == '\r' && x == (width / 4) + 40)
        {
            delete_x(x, y);
            x = (width / 2) - 13;
            y = 16;
            show_square_items_menu();
            if (movement_x_menu_items() == 'b'){
                return 'b';
            }
        }
        else if (move == '\r' && x == (width / 4) + 80){
            return 'c';
        }
        else if (move == '\r' && x == (width / 4) + 120){
            return 'd';
        }
        show_x();
        return movement_x();
    }
    
    void show_x(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (x > ((width / 4) + 120))
        {
            x -= 40;
        }
        if(x < (width / 4) - 10){
            x += 40;
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

    ///////////Items menu//////////////////////////////

void item_name() {
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 11;
    y = 16;
    COORD coord;
    for (int a = 0; a < inventory; a++) { 
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << inventory_items[a];
        key_animation.unlock();
        y += 2; // Espacio entre items
    }
}

void delete_item_name() {
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 11;
    y = 16;
    COORD coord;
    for (int a = 0; a < inventory; a++) {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (size_t i = 0; i < inventory_items[a].length(); i++) {
            std::cout << " ";
        }
        key_animation.unlock();
        y += 2;
    }
}

void show_return_menu_options(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 11;
    y = 26;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "RETURN"; 
    key_animation.unlock();
}

void delete_show_return_menu_options(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 11;
    y = 26;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "       "; 
    key_animation.unlock();
}

    char movement_x_menu_items(){
        show_x_items();
        item_name();
        show_return_menu_options();
        int width, height;
        window_size(width, height);
        char move;
        move = getch();
        move =std::tolower(move);
        switch (move)
        {
        case   'w':
            y -= 2;
            break;
        case 's':
            y += 2;
            break;
        case 'e':
            delete_show_return_menu_options();
            delete_item_name();
            delete_show_square_items();
            delete_x(x, y);
            x = width / 4;
            y = 7;
            return 'm';
            break;
        default:
            break;
        }
        if (move == '\r' && y == (16) && inventory != 0)
        {
            int choose = 0;
            item_used = inventory_items[choose];
            delete_show_return_menu_options();
            delete_item_name();
            delete_show_square_items();
            delete_x(x, y);
            delete_item_inventory(inventory, inventory_items, item_used);
            return 'b';
        }
        else if (move == '\r' && y == (16) + 2 && inventory != 0)
        {
            int choose = 1;
            item_used = inventory_items[choose];
            delete_show_return_menu_options();
            delete_item_name();
            delete_show_square_items();
            delete_x(x, y);
            delete_item_inventory(inventory, inventory_items, item_used);
            return 'b';
        }
        else if (move == '\r' && y == (16) + 4 && inventory != 0){
            int choose = 2;
            item_used = inventory_items[choose];
            delete_show_return_menu_options();
            delete_item_name();
            delete_show_square_items();
            delete_x(x, y);
            delete_item_inventory(inventory, inventory_items, item_used);
            return 'b';
        }
        else if (move == '\r' && y == (16) + 6 && inventory != 0){
            int choose = 3;
            item_used = inventory_items[choose];
            delete_show_return_menu_options();
            delete_item_name();
            delete_show_square_items();
            delete_x(x, y);
            delete_item_inventory(inventory, inventory_items, item_used);
            return 'b';
        }
        else if (move == '\r' && y == (16) + 8 && inventory != 0){
            int choose = 4;
            item_used = inventory_items[choose];
            delete_show_return_menu_options();
            delete_item_name();
            delete_show_square_items();
            delete_x(x, y);
            delete_item_inventory(inventory, inventory_items, item_used);
            return 'b';
        }
        else if (move == '\r' && y == (16) + 10){
            delete_show_return_menu_options();
            delete_item_name();
            delete_show_square_items();
            delete_x(x, y);
            x = width / 4;
            y = 7;
            return 'm';
        }
        show_x_items();
        return movement_x_menu_items();
    }

        void show_x_items(){
        int static prev_x, prev_y;
        delete_x(prev_x, prev_y);
        int width, height;
        window_size(width, height);

        if (y > ((16)) + 10)
        {
            y -= 2;
        }
        if(y < (16)){
            y += 2;
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

    void show_square_items_top(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 15;
    y = 13;
    COORD coord;
    for (int i = 0; i < 20; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void show_square_items_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 15;
    y = 13 + 16;
    COORD coord;
    for (int i = 0; i < 20; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void show_square_items_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 16;
    y = 13;
    COORD coord;
    for (int i = 0; i < 17; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }

}

void show_square_items_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) + 5;
    y = 13;
    COORD coord;
    for (int i = 0; i < 17; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void square_item_background(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) -15;
    y = 14;
    COORD coord;
    for (int i = 0; i < 17; i++)
    {
        for (int a = 0; a < 19; a++)
        {
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << " ";
            x++;
        }
        x = (width / 2) - 15;
        y++;
    }
}

    void show_square_items_menu(){
    square_item_background();
    show_square_items_bottom();
    show_square_items_top();
    show_square_items_right_side();
    show_square_items_left_side();

    }

    //////////////////DELETES////////////////

    void delete_show_square_items_top(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 15;
    y = 13;
    COORD coord;
    for (int i = 0; i < 20; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        x++;
    }
}

void delete_show_square_items_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 15;
    y = (height / 2) + 5;
    COORD coord;
    for (int i = 0; i < 20; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        x++;
    }
}

void delete_show_square_items_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) - 16;
    y = 13;
    COORD coord;
    for (int i = 0; i < 17; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }

}

void delete_show_square_items_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 2) + 5;
    y = 13;
    COORD coord;
    for (int i = 0; i < 17; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_show_square_items(){
    delete_show_square_items_bottom();
    delete_show_square_items_top();
    delete_show_square_items_left_side();
    delete_show_square_items_right_side();
}

};


void show_options_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 2;
    COORD coord;
    for (int i = 0; i < width - 15; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void show_options_continue(){
    int width, height, x, y;
    std::string continue_;
    continue_ = "CONTINUE";
    window_size(width, height);
    x = (width / 4) + 3;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << continue_;
    key_animation.unlock();
}

void show_options_items_(){
    int width, height, x, y;
    std::string show_items;
    show_items = "ITEMS";
    window_size(width, height);
    x = (width / 4) + 43;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << show_items;
    key_animation.unlock();
}

void show_options_save(){
    int width, height, x, y;
    std::string save;
    save = "SAVE";
    window_size(width, height);
    x = (width / 4) + 83;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << save;
    key_animation.unlock();
}

void show_options_principal_menu(){
    int width, height, x, y;
    std::string principal_menu;
    principal_menu = "PRINCIPAL MENU";
    window_size(width, height);
    x = (width / 4) + 123;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << principal_menu;
    key_animation.unlock();
}

void show_option_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 12;
    COORD coord;
    for (int i = 0; i < width - 15; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "-";
        key_animation.unlock();
        x++;
    }
}

void show_option_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 7;
    y = 2;
    COORD coord;
    for (int i = 0; i < 11; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_option_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = width - 7;
    y = 2;
    COORD coord;
    for (int i = 0; i < 11; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "|";
        key_animation.unlock();
        y++;
    }
}

void show_option_square_background(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 3;
    COORD coord;
    for (int i = 0; i < 9; i++)
    {
        for (int a = 0; a < width -15; a++)
        {
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << " ";
            x++;
        }
        x = 8;
        y++;
    }
}

void show_player_stadistics(player& player_1){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 10) - 5;
    y = (4);
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << player_1.name << "  Lv: " << player_1.level;
    key_animation.unlock();
    y += 2;
    key_animation.lock();
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "Health: " << player_1.health << " / " << player_1.max_health;
    key_animation.unlock();
    y += 2;
    key_animation.lock();
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "Damage: " << player_1.damage;
    key_animation.unlock();
}

///////////////////////DELETE///////////////////

void delete_show_options_square_top(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 2;
    COORD coord;
    for (int i = 0; i < width - 15; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        x++;
    }
}

void delete_show_option_square_bottom(){
    int width, height, x, y;
    window_size(width, height);
    x = 8;
    y = 12;
    COORD coord;
    for (int i = 0; i < width - 15; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        x++;
    }
}

void delete_show_option_square_left_side(){
    int width, height, x, y;
    window_size(width, height);
    x = 7;
    y = 2;
    COORD coord;
    for (int i = 0; i < 11; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_show_option_square_right_side(){
    int width, height, x, y;
    window_size(width, height);
    x = width - 7;
    y = 2;
    COORD coord;
    for (int i = 0; i < 11; i++){
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << " ";
        key_animation.unlock();
        y++;
    }
}

void delete_square_show_options(){
    delete_show_option_square_bottom();
    delete_show_option_square_left_side();
    delete_show_option_square_right_side();
    delete_show_options_square_top();
}

void delete_show_options_continue(){
    int width, height, x, y;
    std::string continue_;
    continue_ = "         ";
    window_size(width, height);
    x = (width / 4) + 3;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << continue_;
    key_animation.unlock();
}

void delete_show_options_items_(){
    int width, height, x, y;
    std::string show_items;
    show_items = "      ";
    window_size(width, height);
    x = (width / 4) + 43;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << show_items;
    key_animation.unlock();
}

void delete_show_options_save(){
    int width, height, x, y;
    std::string save;
    save = "     ";
    window_size(width, height);
    x = (width / 4) + 83;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << save;
    key_animation.unlock();
}

void delete_show_options_principal_menu(){
    int width, height, x, y;
    std::string principal_menu;
    principal_menu = "               ";
    window_size(width, height);
    x = (width / 4) + 123;
    y = 7;
    COORD coord;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << principal_menu;
    key_animation.unlock();
}

void delete_show_player_stadistics(player& player_1){
    int width, height, x, y;
    window_size(width, height);
    x = (width / 10) - 5;
    y = (4);
    COORD coord;
    for (int i = 0; i < player_1.name.length() + 1; i++)
    {
        key_animation.lock();
        coord.X = x;
        coord.Y = y;
        std::cout << " ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        key_animation.unlock();
        x++;
    }
    coord.X = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "        " ;
    key_animation.unlock();
    y += 2;
    x = (width / 10) - 5;
    key_animation.lock();
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "               ";
    key_animation.unlock();
    y += 2;
    key_animation.lock();
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << "          ";
    key_animation.unlock();
}

void delete_options_(){
    delete_show_options_continue();
    delete_show_options_items_();
    delete_show_options_save();
    delete_show_options_principal_menu();
}

///////////////////////////////////////////

char show_player_options(player& player_1, int& inventory, std::string inventory_items[]){
    int width, height, x, y;
    window_size(width, height);
    x = width / 4;
    y = 7;
    show_options_square_top();
    show_option_square_bottom();
    show_option_square_left_side();
    show_option_square_right_side();
    show_option_square_background();
    show_options_continue();
    show_options_items_();
    show_options_save();
    show_options_principal_menu();
    show_player_stadistics(player_1);
    X_menu_player_option x_player_option(x, y, inventory, inventory_items);
    switch (x_player_option.movement_x())
    {
    case 'a':
        x_player_option.delete_x(x_player_option.x, x_player_option.y);
        delete_show_player_stadistics(player_1);
        delete_options_();
        delete_square_show_options();
        return 'a';
        break;
    case 'b':
        delete_show_player_stadistics(player_1);
        delete_options_();
        delete_square_show_options();
        use_item(item_used, player_1.health, player_1.max_health, player_1.damage);
        return 'b';
        break;
    case 'c':
        return 'c';
        break;
    case 'd':
        return 'd';
        break;
    default:
        break;
    }
    return 'i';
}





#endif