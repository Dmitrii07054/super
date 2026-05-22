#include "Brick.hpp"

Brick::Brick() : GameObject() {}

Brick::Brick(float xPos, float yPos, float w, float h, ObjectType t)
    : GameObject(xPos, yPos, w, h, t) {}

void Brick::update() {}
