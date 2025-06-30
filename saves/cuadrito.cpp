#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "inf_window.h"
#include "mutex_key.h"
#include "game_start.h"
#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>
using namespace std;

extern bool verify_music;

struct X_menu
{
    int x;
    int y;
    X_menu(int x, int y):
    x(x), y(y) {}

    char movement_x(){
        show_x();
        int width, height;
        window_size(width, height);
        char move;
        move = getch();
        move =std::tolower(move);
        switch (move)
        {
        case   'w':
            y -= 3;
            break;
        case 's':
            y += 3;
            break;
        default:
            break;
        }
        if (move == '\r' && y == ((height / 2) - 4))
        {
            return 'a';
        }
        else if (move == '\r' && y == ((height / 2) -1))
        {
            return 'b';
        }
        else if (move == '\r' && y == ((height / 2) + 2)){
            return 'c';
        }
        else if (move == '\r' && y == ((height / 2) + 5)){
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

        if (y > ((height / 2) + 5))
        {
            y -= 3;
        }
        if(y < ((height / 2) - 4)){
            y += 3;
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
};

//---------------------------------------
    struct Savegame
    {
        string name;
        int x;
        int y;
        int health;
        int damage;
        int level;
        string nombre;
    };

    const int MAX_SAVES = 5;

        Savegame savegame[MAX_SAVES];

        int total = 0;

    void agregar()
    {
      Savegame e;
        if (total >= MAX_SAVES)
        {
            cout << "All saves slots used! (max. " << MAX_SAVES << " saves)\n"; // en caso de llenarse con maximo, mandar mensaje de error

            return;
        }
        cout << "Insert name of save file: ";
        cin.ignore();
        getline(cin, e.nombre);
        total++;
        ofstream archivo("savefile.txt", ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << endl;
        archivo.close();
    } else {
        cout << "error opening savefile.txt.\n";
    }
        cout << "File saved! \n";
    }

    void mostrar()
    {
      ifstream archivo("savefile.txt");
      Savegame e;

    if (archivo.is_open()) {
        while (archivo >> e.nombre ) {
            cout << "game: " << e.nombre << endl;
        }
        archivo.close();
    } else {
        cout << "error opening savefile.txt\n";
    }

    if (total == 0)
        {
            cout << "No games saved.\n";

            return;
        }
    }

    
    void cargar() {
    ifstream archivo("savefile.txt");
    Savegame e;

    if (!archivo) return;

    archivo >> total;

    if (total >= MAX_SAVES) total = MAX_SAVES;

    for (int i = 0; i < total; ++i) {
        archivo >> e.nombre;
    }
    archivo.close();

}
  void eliminar(){
    ifstream archivo("savefile.txt");
    ofstream temp("temp.txt");
    Savegame e;
    string buscado;
    bool eliminado = false;
    
    cout << "insert name of save to delete: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) {
        while (archivo >> e.nombre) {
            if (e.nombre == buscado) {
                eliminado = true;               // No se copia: se “borra”
                total--;
              } else {
                temp << e.nombre << endl;
            }
        }
      archivo.close();
      temp.close();
      remove("savefile.txt");
      rename("temp.txt", "savefile.txt");

      if (eliminado)
            cout << "User deleted.\n";
        else
            cout << "User not found.\n";
    } else {
        cout << "Error opening saves file.\n";
    }


  }

//------------------------------------------------

int show_menu(){
    verify_raining = true;
    PlaySound(TEXT("assets//music//Undertale-OST-063-It_s-Raining-Somewhere-Else-Misaki-pruebasonido.wav"),NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    int width, height;
    window_size(width, height);
    int y_center = (height) / 2;
    std::thread thread_rain1(rain_main);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread thread_rain2(rain_main2);
    Sleep(2000);
    center_text("SAVES", y_center - 7);
    std::thread thread_rain3(rain_main);
    Sleep(2000);
    center_text("Save game & continue", y_center - 4);
    std::thread thread_rain4(rain_main2);
    Sleep(1000);
    center_text("Save game & exit", y_center - 1);
    Sleep(1000);
    center_text("Exit", y_center + 5);
    std::thread thread_rain6(rain_main2);
    int x = (width / 2) - 7;
    int y = (height / 2) - 4;
    X_menu x1(x, y);
    switch (x1.movement_x())
    {
    case 'a':
    agregar();
    system("cls");
    // crear save
        break;
    case 'b':
        mostrar();
        system("cls");       
        // ver saves
        break;
    case 'c':
        eliminar();
        system("cls");
        // borrar saves
        break;
    case 'd':
    
    system("cls");
    exit(0);
    break;
    default:
        break;
    }
    // x1.movement_x();
    // thread_rain1.join();
    // thread_rain2.join();
    // thread_rain3.join();
    // thread_rain4.join();
    return 0;
}

#endif