//
// Created by Housseini on 08/05/2024.
//

#ifndef UNHAPPYKNIGHT_ANIMATION_H
#define UNHAPPYKNIGHT_ANIMATION_H

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

class Animation {
public:
    std::string animationName;
    std::vector<SDL_Rect> frameArray;
    SDL_Texture* texture;
    void makeFrameArray(int startRow, int endRow,int startCol,int endCol,int frameWidth, int frameHeight);


};


#endif //UNHAPPYKNIGHT_ANIMATION_H
