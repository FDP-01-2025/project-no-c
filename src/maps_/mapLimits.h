#ifndef LIMIT_MAP_H
#define LIMIT_MAP_H


void restrictMapBorders(int &player_x, int &player_y, int screen_width, int screen_height, int previous_x, int previous_y) {
    
    int left_limit   = 4;                     
    int right_limit  = screen_width - 5;      
    int top_limit    = 2;                     
    int bottom_limit = screen_height - 3;     

    
    if (player_x < left_limit || player_x > right_limit || player_y < top_limit || player_y > bottom_limit) {
        player_x = previous_x;
        player_y = previous_y;
    }
}

#endif




