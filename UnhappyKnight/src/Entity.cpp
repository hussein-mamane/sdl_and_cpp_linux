//
// Created by Housseini on 08/05/2024.
//
#include "vec2.h"
#include "Entity.h"

SDL_Rect Entity::getCurrentframe() {
    return animations[currentState].frameArray[currentframeIndex];
}

SDL_Texture *Entity::getTexture(const std::string& animationName) {
    return animations[animationName].texture;
//    return animations[currentState].texture;// to get rid of the parameter if needed
}

const vec2 &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const vec2 &pos) {
    Entity::position = pos;
}

const char* Entity::getCurrentState() const {
    return currentState;
}

void Entity::setCurrentState( char* State) {
    Entity::currentState = State;
}

int Entity::getCurrentframeIndex() const {
    return currentframeIndex;
}

void Entity::setCurrentframeIndex(int Index) {
    Entity::currentframeIndex = Index;
}

void Entity::addTexture(SDL_Texture *texture, const char *animationName) {
    animations[animationName].texture = texture;
}

Entity::Entity(vec2 position,char* startState) : position(position) {
    currentframeIndex = 0;
    currentState = startState;
//    position = vec2(100,100);
}

void Entity::updateFrameIndex() /*const */{
    if(getCurrentframeIndex()<7)
        setCurrentframeIndex(getCurrentframeIndex()+1) ;
    else
        setCurrentframeIndex(0);
}





