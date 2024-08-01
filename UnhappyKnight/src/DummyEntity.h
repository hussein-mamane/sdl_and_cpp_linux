//
// Created by Housseini on 16/05/2024.
//
#include <SDL2/SDL.h>
#include <vector>
#include "vec2.h"
#include "MapHandler.h"

#ifndef UNHAPPYKNIGHT_DUMMYENTITY_H
#define UNHAPPYKNIGHT_DUMMYENTITY_H

class DummyEntity{
public:
    SDL_Texture* Texture;

    bool canMoveLeft(const Map&);
    bool canMoveRight(const Map&);
    bool canMoveUp(const Map&);
    bool canMoveDown(const Map&);
    bool moveToTarget();

    SDL_Texture *getTexture() const;

    void setTexture(SDL_Texture *texture);

    const vec2 &getPosition() const;

    void setPosition(const vec2 &position);

    const vec2 &getTarget() const;

    void setTarget(const vec2 &target);

    float getSpeed() const;

    void setSpeed(float speed);

private:
    vec2 Position;
    vec2 Target;
    float speed;


};
#endif //UNHAPPYKNIGHT_DUMMYENTITY_H
