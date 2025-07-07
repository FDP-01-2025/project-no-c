#ifndef EXPERIENCE_SYSTEM_H
#define EXPERIENCE_SYSTEM_H
#include "../player_/player.h"




void add_experience(int& player_level, int& player_experience, int& enemy_experience, int& player_max_health, int& player_damage){
    player_experience += enemy_experience;
    static bool level_up1 = false;
    static bool level_up2 = false;
    static bool level_up3 = false;
    static bool level_up4 = false;
    static bool level_up5 = false;
    if (player_experience >= 5 && level_up1 == false)
    {
        player_level += 1;
        level_up(player_level, player_max_health, player_damage);
        level_up1 = true;
        return;
    }
    if (player_experience >= 10 && level_up2 == false)
    {
        player_level += 1;
        level_up(player_level, player_max_health, player_damage);
        level_up2 = true;
        return;
    }
    if (player_experience >= 15 && level_up3 == false)
    {
        player_level += 1;
        level_up(player_level, player_max_health, player_damage);
        level_up3 = true;
        return;
    }
    if (player_experience >= 25 && level_up4 == false)
    {
        player_level += 1;
        level_up(player_level, player_max_health, player_damage);
        level_up4 = true;
        return;
    }
    if (player_experience >= 35 && level_up5 == false)
    {
        player_level += 1;
        level_up(player_level, player_max_health, player_damage);
        level_up5 = true;
        return;
    }
    return;
    
}








#endif