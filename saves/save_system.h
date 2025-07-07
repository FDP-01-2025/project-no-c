#include <iostream>
#include <fstream>
#include "../src/game_start.h"

using namespace std;
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

    const int MAX_SAVES = 3;

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
    }

<<<<<<< HEAD
    void add_player_stadistic(std::string player_name, std::string name, int& level, int& health, int& max_health, int& damage, int& player_experience, int& inventory,std::string inventory_item[], int id, int e_experience){
      ofstream archivo(player_name + ".txt", ios::app);
      archivo << name << std::endl;
      archivo << level;
      archivo.close();
    }


=======
>>>>>>> fc0ffa0cde5701229d8c003d17b9b83bc9052d21
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
    ifstream archivo("savefile.txt"); //cambiar por player_name + ".txt"
    Savegame e;
    int level;
    int health;


    if (!archivo) return;

    archivo >> total;
    archivo >> level;
    archivo >> health; 
      //con todo lo demas

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
                eliminado = true;                       // No se copia: se “borra”
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
int save_menu() {

  cargar();
  int op;

  do {
    cout << "\n1. Save game\n";
    cout << "2. Show saves\n";
    cout << "3. Delete game\n";
    cout << "4.Exit\n";
    cin >> op;

    switch (op) {
      case 1:
        agregar();
        break;

      case 2:
        mostrar();
        break;

      case 3:
        eliminar();
        break;

      case 4:
        cout << "Leaving...\n";
        break;

      default:
        cout << "Invalid option\n";
    }

  } while (op != 4);

  return 0;
}

