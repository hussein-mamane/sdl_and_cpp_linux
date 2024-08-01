//
// Created by Housseini on 08/05/2024.
//

#include "Animation.h"
void Animation::makeFrameArray(int startRow, int endRow,int startCol,int endCol,int frameWidth, int frameHeight) {
    SDL_Rect rect;
    for (int i = startRow; i < endRow; ++i) {
        for (int j = startCol; j < endCol; ++j) {
            rect.w=frameWidth;
            rect.h=frameHeight;
            rect.x=j*frameWidth;
            rect.y=i*frameHeight;
        frameArray.push_back(rect);//abstract rect that tell where to cut the texture during animation
        }
    }
}