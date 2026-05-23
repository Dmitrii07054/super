#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <windows.h>

enum class ObjectType {
    MARIO = '@',
    BRICK_NORMAL = '#',
    BRICK_QUESTION = '?',
    BRICK_EMPTY = '-',
    BRICK_FINISH = '+',
    ENEMY = 'o',
    COIN = '$'
};

class GameObject {
public:
    float x, y;
    float width, height;
    float vertSpeed;
    float horizSpeed;
    BOOL IsFly;
    ObjectType cType;
    
    GameObject();
    GameObject(float xPos, float yPos, float w, float h, ObjectType t);
    virtual ~GameObject() = default;

    void setPos(float xPos, float yPos);
    BOOL isCollision(const GameObject& other) const;
	
	virtual void update() {}
};

#endif
