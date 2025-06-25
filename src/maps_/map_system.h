#ifndef MAP_SYSTEM_H
#define MAP_SYSTEM_H
#include <windows.h>
#include <iostream>
#include "../inf_window.h"

struct map{
    int min_x;
    int min_y;
    int max_x;
    int max_y;
    map(int min_x, int min_y, int max_x, int max_y):
        min_x(min_x), min_y(min_y), max_x(max_x), max_y(max_y) {}



};



#endif