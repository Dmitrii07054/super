#include "MovingObject.hpp"

const float MovingObject::GRAVITY = 0.12f;

MovingObject::MovingObject() : Brick() {}

MovingObject::MovingObject(float xPos, float yPos, float w, float h, ObjectType t)
    : Brick(xPos, yPos, w, h, t) {
    if (t == ObjectType::ENEMY) {
        horizSpeed = 0.2f;
    }
}

void MovingObject::applyGravity() {
    IsFly = TRUE;
    vertSpeed += GRAVITY;
}

void MovingObject::update() {
    applyGravity();
    y += vertSpeed;
}
