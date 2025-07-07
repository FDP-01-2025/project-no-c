// #include <iostream>
// #include <fstream>
// #include "../src/game_start.h"

// using namespace std;
//     struct Savegame
//     {
//         string name;
//         int x;
//         int y;
//         int health;
//         int damage;
//         int level;
//         string nombre;
//     };

//     const int MAX_SAVES = 3;

//         Savegame savegame[MAX_SAVES];

//         int total = 0;

//     void agregar(std::string player_name)
//     {
//       Savegame e;
//         if (total >= MAX_SAVES)
//         {
//             cout << "All saves slots used! (max. " << MAX_SAVES << " saves)\n"; // en caso de llenarse con maximo, mandar mensaje de error

//             return;
//         }
// <<<<<<< HEAD
//         ofstream archivo(player_name + ".txt", ios::app);
//         archivo.close();
//     }

//     void add_player(std::string player_name, std::string name, int& level, int& health, int& max_health, int& damage, int& player_experience, int& inventory,std::string inventory_item[], int id, int e_experience){
//       ofstream archivo(player_name + ".txt", ios::app);
//       archivo << name << std::endl;
//       archivo << level << std::endl;
//       archivo << health << std::endl;
//       archivo << max_health << std::endl;
//       archivo << damage << std::endl;
//       archivo << player_experience << std::endl;
//       archivo << inventory << std::endl;

//       for (int i = 0; i < inventory; i++) {
//           archivo << inventory_item[i] << std::endl;
//       }

//       archivo << id << std::endl;
//       archivo << e_experience << std::endl;

//       archivo.close();
//     }


// =======
//     }

// <<<<<<< HEAD
//     void add_player_stadistic(std::string player_name, std::string name, int& level, int& health, int& max_health, int& damage, int& player_experience, int& inventory,std::string inventory_item[], int id, int e_experience){
//       ofstream archivo(player_name + ".txt", ios::app);
//       archivo << name << std::endl;
//       archivo << level;
//       archivo.close();
//     }


// =======
// >>>>>>> fc0ffa0cde5701229d8c003d17b9b83bc9052d21
// >>>>>>> be478df7d2d35e3535bcb39445fdc98602ba2733
//     void mostrar()
//     {
//       ifstream archivo("savefile.txt");
//       Savegame e;

//     if (archivo.is_open()) {
//         while (archivo >> e.nombre ) {
//             cout << "game: " << e.nombre << endl;
//         }
//         archivo.close();
//     } else {
//         cout << "error opening savefile.txt\n";
//     }

//     if (total == 0)
//         {
//             cout << "No games saved.\n";
//             return;
//         }
//     }

    
// <<<<<<< HEAD
//     void cargar_player(std::string player_name, std::string name, int& level, int& health, int& max_health, int& damage, int& player_experience, int& inventory,std::string inventory_item[], int id, int e_experience) {
//     ifstream archivo(player_name + ".txt", ios::app); //cambiar por player_name + ".txt"
// =======
//     void cargar() {
//     ifstream archivo("savefile.txt"); //cambiar por player_name + ".txt"
// >>>>>>> be478df7d2d35e3535bcb39445fdc98602ba2733
//     Savegame e;
//     int level;
//     int health;


//     if (!archivo) return;

// <<<<<<< HEAD
//     archivo >> name;
//     archivo >> level;
//     archivo >> health;
//     archivo >> max_health;
//     archivo >> damage;
//     archivo >> player_experience;
//       archivo >> inventory;

//     for (int i = 0; i < inventory; i++) {
//         archivo >> inventory_item[i];
//     }

//       archivo >> id;
//       archivo >> e_experience;

//       archivo.close();
// =======
//     archivo >> total;
//     archivo >> level;
//     archivo >> health; 
// >>>>>>> be478df7d2d35e3535bcb39445fdc98602ba2733
//       //con todo lo demas

//     if (total >= MAX_SAVES) total = MAX_SAVES;

//     for (int i = 0; i < total; ++i) {
//         archivo >> e.nombre;
//     }
//     archivo.close();

//     game_start(); //dentro de game_Start std::string player_name, std::string name, int& level, int& health, int& max_health, int& damage, int& player_experience, int& inventory,std::string inventory_item[], int id, int e_experience
// }

//   void eliminar(){
//     ifstream archivo("savefile.txt");
//     ofstream temp("temp.txt");
//     Savegame e;
//     string buscado;
//     bool eliminado = false;
    
//     cout << "insert name of save to delete: ";
//     cin >> buscado;

//     if (archivo.is_open() && temp.is_open()) {
//         while (archivo >> e.nombre) {
//             if (e.nombre == buscado) {
//                 eliminado = true;               // No se copia: se “borra”
//                 total--;
//               } else {
//                 temp << e.nombre << endl;
//             }
//         }
//       archivo.close();
//       temp.close();
//       remove("savefile.txt");
//       rename("temp.txt", "savefile.txt");

//       if (eliminado)
//             cout << "User deleted.\n";
//         else
//             cout << "User not found.\n";
//     } else {
//         cout << "Error opening saves file.\n";
//     }


//   }
// int save_menu() {

//   cargar();
//   int op;

//   do {
//     cout << "\n1. Save game\n";
//     cout << "2. Show saves\n";
//     cout << "3. Delete game\n";
//     cout << "4.Exit\n";
//     cin >> op;

//     switch (op) {
//       case 1:
//         agregar();
//         break;

//       case 2:
//         mostrar();
//         break;

//       case 3:
//         eliminar();
//         break;

//       case 4:
//         cout << "Leaving...\n";
//         break;

//       default:
//         cout << "Invalid option\n";
//     }

//   } while (op != 4);

//   return 0;
// }