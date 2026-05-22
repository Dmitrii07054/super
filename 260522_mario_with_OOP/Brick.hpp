#ifndef BRICK_HPP
#define BRICK_HPP

#include "GameObject.hpp"

class Brick : public GameObject {
public:
    Brick();
    Brick(float xPos, float yPos, float w, float h, ObjectType t);
    virtual ~Brick() = default;
	
	virtual void update() override;
};

#endif
