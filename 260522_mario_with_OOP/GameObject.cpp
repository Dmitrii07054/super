#include "GameObject.hpp"
#include <cmath>

GameObject::GameObject() 
    : x(0), y(0), width(0), height(0), vertSpeed(0), 
      horizSpeed(0), IsFly(FALSE), cType(ObjectType::BRICK_NORMAL) {}

GameObject::GameObject(float xPos, float yPos, float w, float h, ObjectType t)
    : x(xPos), y(yPos), width(w), height(h), vertSpeed(0), 
      horizSpeed(0), IsFly(FALSE), cType(t) {}

void GameObject::setPos(float xPos, float yPos) {
    x = xPos;
    y = yPos;
}

BOOL GameObject::isCollision(const GameObject& other) const {
    return (x + width > other.x) && (x < other.x + other.width) &&
           (y + height > other.y) && (y < other.y + other.height);
}
