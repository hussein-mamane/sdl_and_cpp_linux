//
// Created by Housseini on 08/05/2024.
//
#include <vector>
#include <map>
#include <iostream>
#include <SDL2/SDL.h>
#include "vec2.h"
#include "Animation.h"
#ifndef UNHAPPYKNIGHT_ENTITY_H
#define UNHAPPYKNIGHT_ENTITY_H


class Entity {
private:
    char* currentState;
    int currentframeIndex;
public:
    const vec2 &getPosition() const;
    vec2 position;

    void setPosition(const vec2 &pos);

    const char* getCurrentState() const;

    void setCurrentState( char* currentState);

    int getCurrentframeIndex() const;


    void setCurrentframeIndex(int currentframeIndex);
    std::map<std::string,Animation> animations;
    short direction;
    short lastDirection;
    SDL_Rect getCurrentframe();
    SDL_Texture* getTexture(const std::string& textureName);
    void addTexture(SDL_Texture* texture,const char* animationName);
    explicit Entity(vec2 position, char* startState);
    bool flip = false;

    void updateFrameIndex() ;//const;
};


#endif //UNHAPPYKNIGHT_ENTITY_H
