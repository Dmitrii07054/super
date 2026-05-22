#ifndef MOVINGOBJECT_HPP
#define MOVINGOBJECT_HPP

#include "Brick.hpp"

class MovingObject : public Brick {
public:
    static const float GRAVITY;
    
    MovingObject();
    MovingObject(float xPos, float yPos, float w, float h, ObjectType t);
    virtual ~MovingObject() = default;
    
    virtual void update() override;
    void applyGravity();
};

#endif
