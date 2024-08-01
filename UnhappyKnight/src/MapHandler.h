//
// Created by Housseini on 16/05/2024.
//

#ifndef UNHAPPYKNIGHT_MAPHANDLER_H
#define UNHAPPYKNIGHT_MAPHANDLER_H

#define NB_ROWS 3
#define NB_COLS 3
#include "MapHandler.h"
#include<array>
#include<SDL2/SDL.h>
class Map{
    std::array<std::array<int,NB_ROWS>,NB_COLS> layout;
    std::array<std::array<SDL_Rect*,NB_ROWS>,NB_COLS> rectangles;
private:
    bool initLayout(const char* filePath);
    void drawMap();

    bool initMap(const char *filePath);
};

#endif //UNHAPPYKNIGHT_MAPHANDLER_H
