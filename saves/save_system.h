#include <iostream>
#include <fstream>
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
int main() {
  cargar();
  int op;

  do {
    cout << "\n1. Save game 2. Show saves 3. Delete game 4.Exit\n ";
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

