#ifndef SAVE_SYSTEM_H
#define SAVE_SYSTEM_H
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
    };

    const int MAX_SAVES = 5;

        Savegame savegame[MAX_SAVES];

        int total = 0;

    void agregar()
    {
        if (total >= MAX_SAVES)
        {
            cout << "All saves slots used! (max. " << MAX_SAVES << " saves)\n"; // en caso de llenarse con maximo, mandar mensaje de error

            return;
        }
        cout << "Insert name of save file: ";
        cin.ignore();
        getline(cin, savegame[total].name);
        ++total;
        cout << "File saved! \n";
    }

    void mostrar()
    {
        cout << "\nSAVES\n";

        if (total == 0)
        {
            cout << "No games saved.\n";

            return;
        }

        for (int i = 0; i < total; ++i)
        {
            cout << savegame[i].name << " -\n";
        }
    }

    void guardar() {
    ofstream archivo("savefile.txt");

    if (!archivo) {
        cerr << "error opening savefile.txt\n";

        return;
    }

    archivo << total << '\n';

    for (int i = 0; i < total; ++i) {
        archivo << savegame[i].name << " - ";
    }

    archivo.close();//siempre cerrarlo para evitar erroress

    cout << "Data saved\n";
    }
    void cargar() {
    ifstream archivo("savefile.txt");

    if (!archivo) return;

    archivo >> total;

    if (total > MAX_SAVES) total = MAX_SAVES;

    for (int i = 0; i < total; ++i) {
        archivo >> savegame[i].name;
    }
    archivo.close();

}
int main() {
  cargar();
  int op;

  do {
    cout << "\n1. Save game  2. Show saves  3.Save and exit\n ";

    cin >> op;

    switch (op) {
      case 1:
        agregar();
        break;

      case 2:
        mostrar();
        break;

      case 3:
        guardar();
        cout << "Leaving...\n";
        break;

      default:
        cout << "Invalid option\n";
    }

  } while (op != 3);

  return 0;
}
#endif
