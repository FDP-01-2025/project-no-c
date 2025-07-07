#include <iostream>
#include <fstream>
#include <vector>
#include "../src/game_start.h"

using namespace std;

struct PlayerData {
    string name;
    int level;
    int health;
    int max_health;
    int damage;
    int player_experience;
    vector<string> inventory_items;
    int current_enemy_id;
    int enemy_experience;
};

const int MAX_SAVES = 3;

        Savegame savegame[MAX_SAVES];

        int total = 0;

void use_save1(const string& saveName, const PlayerData& player)
{
    ofstream saveFile(saveName + ".sav");

    if (!saveFile.is_open()) {
        cerr << "Error al crear el archivo de guardado!" << endl;
        return;
    }

    // Guardar datos básicos
    saveFile << player.name << endl;
    saveFile << player.level << endl;
    saveFile << player.health << endl;
    saveFile << player.max_health << endl;
    saveFile << player.damage << endl;
    saveFile << player.player_experience << endl;
    
    // Guardar inventario
    saveFile << player.inventory_items.size() << endl;
    for (const auto& item : player.inventory_items) {
        saveFile << item << endl;
    }
    
    // Guardar datos de enemigo
    saveFile << player.current_enemy_id << endl;
    saveFile << player.enemy_experience << endl;
    
    saveFile.close();
    
    // Actualizar lista de guardados
    ofstream saveList("saves.list", ios::app);
    saveList << saveName << endl;
    saveList.close();
    total++;

    if (total > MAX_SAVES) {
        cerr << "Se ha alcanzado el número máximo de partidas guardadas!" << endl;
        return;
    }
    
    cout << "Partida guardada correctamente como: " << saveName << endl;
}

void use_save2(const string& saveName, const PlayerData& player)
{
    ofstream saveFile(saveName + ".sav");
    
    if (!saveFile.is_open()) {
        cerr << "Error al crear el archivo de guardado!" << endl;
        return;
    }

    // Guardar datos básicos
    saveFile << player.name << endl;
    saveFile << player.level << endl;
    saveFile << player.health << endl;
    saveFile << player.max_health << endl;
    saveFile << player.damage << endl;
    saveFile << player.player_experience << endl;
    
    // Guardar inventario
    saveFile << player.inventory_items.size() << endl;
    for (const auto& item : player.inventory_items) {
        saveFile << item << endl;
    }
    
    // Guardar datos de enemigo
    saveFile << player.current_enemy_id << endl;
    saveFile << player.enemy_experience << endl;
    
    saveFile.close();
    
    // Actualizar lista de guardados
    ofstream saveList("saves.list", ios::app);
    saveList << saveName << endl;
    saveList.close();
    total++;

    if (total > MAX_SAVES) {
        cerr << "Se ha alcanzado el número máximo de partidas guardadas!" << endl;
        return;
    }
    
    cout << "Partida guardada correctamente como: " << saveName << endl;
}

void use_save3(const string& saveName, const PlayerData& player)
{
    ofstream saveFile(saveName + ".sav");
    
    if (!saveFile.is_open()) {
        cerr << "Error al crear el archivo de guardado!" << endl;
        return;
    }

    // Guardar datos básicos
    saveFile << player.name << endl;
    saveFile << player.level << endl;
    saveFile << player.health << endl;
    saveFile << player.max_health << endl;
    saveFile << player.damage << endl;
    saveFile << player.player_experience << endl;
    
    // Guardar inventario
    saveFile << player.inventory_items.size() << endl;
    for (const auto& item : player.inventory_items) {
        saveFile << item << endl;
    }
    
    // Guardar datos de enemigo
    saveFile << player.current_enemy_id << endl;
    saveFile << player.enemy_experience << endl;
    
    saveFile.close();
    
    // Actualizar lista de guardados
    ofstream saveList("saves.list", ios::app);
    saveList << saveName << endl;
    saveList.close();
    total++;

    if (total > MAX_SAVES) {
        cerr << "Se ha alcanzado el número máximo de partidas guardadas!" << endl;
        return;
    }
    
    cout << "Partida guardada correctamente como: " << saveName << endl;
}


bool loadGame(const string& saveName, PlayerData& player) {
    ifstream saveFile(saveName + ".sav");
    
    if (!saveFile.is_open()) {
        cerr << "No se encontró el archivo de guardado!" << endl;
        return false;
    }

    // Cargar datos básicos
    saveFile >> player.name;
    saveFile >> player.level;
    saveFile >> player.health;
    saveFile >> player.max_health;
    saveFile >> player.damage;
    saveFile >> player.player_experience;
    
    // Cargar inventario
    int inventory_size;
    saveFile >> inventory_size;
    player.inventory_items.resize(inventory_size);
    for (int i = 0; i < inventory_size; ++i) {
        saveFile >> player.inventory_items[i];
    }
    
    // Cargar datos de enemigo
    saveFile >> player.current_enemy_id;
    saveFile >> player.enemy_experience;
    
    saveFile.close();
    return true;
}
vector<string> 
listSavedGames() {
    vector<string> saves;
    ifstream saveList("saves.list");
    
    if (saveList.is_open()) {
        string saveName;
        while (getline(saveList, saveName)) {
            saves.push_back(saveName);
        }
        saveList.close();
    }
    
    return saves;
}

bool deleteSave(const string& saveName) {
    // Eliminar el archivo de guardado
    if (remove((saveName + ".sav").c_str()) != 0) {
        perror("Error al eliminar el archivo de guardado");
        return false;
    }
    
    // Actualizar la lista de guardados
    vector<string> saves = listSavedGames();
    ofstream newSaveList("saves.list");
    
    for (const auto& save : saves) {
        if (save != saveName) {
            newSaveList << save << endl;
        }
    }
    
    newSaveList.close();
    return true;
}
