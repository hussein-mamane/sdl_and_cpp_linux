//
// Created by Housseini on 16/05/2024.
//

#include "DummyEntity.h"

bool DummyEntity::canMoveUp(const Map& map) {
    return false;
}
bool DummyEntity::canMoveDown(const Map& map) {
    return false;
}

bool DummyEntity::canMoveLeft(const Map& map) {
    return false;
}
bool DummyEntity::canMoveRight(const Map& map) {
    return false;
}

SDL_Texture *DummyEntity::getTexture() const {
    return Texture;
}

void DummyEntity::setTexture(SDL_Texture *texture) {
    Texture = texture;
}

const vec2 &DummyEntity::getPosition() const {
    return Position;
}

void DummyEntity::setPosition(const vec2 &position) {
    Position = position;
}

const vec2 &DummyEntity::getTarget() const {
    return Target;
}

void DummyEntity::setTarget(const vec2 &target) {
    Target = target;
}

float DummyEntity::getSpeed() const {
    return speed;
}

void DummyEntity::setSpeed(float speed) {
    DummyEntity::speed = speed;
}
