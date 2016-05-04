#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include "math/quaternion.h"

class node
{

    node* parent = nullptr;

    float minAngle = 0;
    float maxAngle = 0;
    float distanceFromParent = 0;
public:
    node* child = nullptr;
    float currentAngle = 0;
    coord POS;
    node(coord pos, float mini, float maxi);
    node(node* parent, float mini, float maxi, float dist);
    void update(sf::RenderWindow &window,coord goal);
    void update(sf::RenderWindow &window);
    void calculateNewAngle(coord target);
};


#endif // NODE_HPP_INCLUDED
