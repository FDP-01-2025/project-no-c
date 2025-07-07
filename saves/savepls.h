#ifndef SAVE_SYSTEM_H
#define SAVE_SYSTEM_H
#include <iostream>
#include <fstream>
#include "../src/game_start.h"
#include "../src/player_/player.h"

void game_start(
    bool new_game, int x, int y, int health, int max_health, int damage, int level,
    std::string creator_name, std::string player_name, std::string* inventory_item,
    int inventory, int experience, int cow_health, int cat_health, int hachi_health,
    int iguana_health, int thief_health, int snail_health, int horse_health,
    int sheep_health, int pig_health
);


using namespace std;

    int total = 0;

struct PlayerData {
    bool new_game;
    int x;
    int y;
    int health;
    int max_health;
    int damage;
    int level;
    int inventory;
    int experience;
    std::string creator_name;
    std::string name;
    std::string inventory_item[6];
};

const int MAX_SAVES = 3;

        PlayerData savegame[MAX_SAVES];

void use_save(player& player_1, int& cow_health, int& cat_health, int& hachi_health, int& iguana_health, int& horse_health, int& thief_health, int& pig_health, int& snail_health, int& sheep_health)
{
    ofstream saveFile(player_1.creator_name + ".txt");

    if (!saveFile.is_open()) {
        cerr << "Error al crear el archivo de guardado!" << endl;
        return;
    }

    // Guardar datos básicos
    saveFile << player_1.new_game << endl;
    saveFile <<player_1.x << endl;
    saveFile << player_1.y << endl; 
    saveFile << player_1.name << endl;
    saveFile << player_1.creator_name << endl;
    saveFile << player_1.level << endl;
    saveFile << player_1.health << endl;
    saveFile << player_1.max_health << endl;
    saveFile << player_1.damage << endl;
    saveFile << player_1.experience << endl;
    saveFile <<player_1.inventory << endl;
    // Guardar inventario
    for (int i = 0; i < player_1.inventory + 1; i++) {
        saveFile << player_1.inventory_item[i] << endl;
    }
    
    // Guardar datos de enemigo
    saveFile << cow_health << endl;
    saveFile << cat_health << endl;
    saveFile << hachi_health << endl;
    saveFile << sheep_health << endl;
    saveFile << snail_health << endl;
    saveFile << pig_health << endl;
    saveFile << iguana_health << endl;
    saveFile << horse_health << endl;
    saveFile << thief_health << endl;

    saveFile.close();
    // Actualizar lista de guardados
    // ofstream saveList("saves.list", ios::app);
    // saveList << saveName << endl;
    // saveList.close();
    // total++;
}


bool loadGame(const string& saveName) {
int cow_health, cat_health, hachi_health, iguana_health, horse_health, thief_health, pig_health, snail_health, sheep_health;

    PlayerData player;
    ifstream saveFile(saveName + ".txt");
    
    if (!saveFile.is_open()) {
        cerr << "No se encontró el archivo de guardado!" << endl;
        return false;
    }

    std::string line;

    // Cargar datos básicos,  e ignorar cualquier texto antes del = 
    saveFile >> player.new_game;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> player.x;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer
    
    saveFile >> player.y;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    std::getline(saveFile, player.name);
    std::getline(saveFile, player.creator_name);


    saveFile >> player.level;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> player.health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> player.max_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> player.damage;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> player.experience;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> player.inventory;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    for (int i = 0; i <= player.inventory; i++)
    {
        std::getline(saveFile, player.inventory_item[i]);
    }
    
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> cow_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> cat_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> hachi_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer
    
    saveFile >> sheep_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer
    
    saveFile >> snail_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> pig_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> iguana_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> horse_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile >> thief_health;
    saveFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Limpiar debuffer

    saveFile.close();
    
    game_start(player.new_game, player.x, player.y, player.health, player.max_health, player.damage, player.level, player.creator_name, player.name, player.inventory_item,player.inventory,player.experience,cow_health,cat_health,hachi_health,iguana_health,thief_health, snail_health, horse_health, sheep_health, pig_health);

    return true;
}
// vector<string> 
// listSavedGames() {
//     vector<string> saves;
//     ifstream saveList("saves.list");
    
//     if (saveList.is_open()) {
//         string saveName;
//         while (getline(saveList, saveName)) {
//             saves.push_back(saveName);
//         }
//         saveList.close();
//     }
    
//     return saves;
// }

// bool deleteSave(const string& saveName) {
//     // Eliminar el archivo de guardado
//     if (remove((saveName + ".sav").c_str()) != 0) {
//         perror("Error al eliminar el archivo de guardado");
//         return false;
//     }
    
//     // Actualizar la lista de guardados
//     // vector<string> saves = listSavedGames();
//     // ofstream newSaveList("saves.list");
    
//     // for (const auto& save : saves) {
//     //     if (save != saveName) {
//     //         newSaveList << save << endl;
//     //     }
//     // }
    
//     newSaveList.close();
//     return true;
// }

#endif