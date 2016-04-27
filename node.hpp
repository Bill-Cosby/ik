#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include "basicObjects.hpp"

class node
{

    node* parent = nullptr;
    node* child = nullptr;

    float minAngle = 0;
    float maxAngle = 0;
public:
    coord POS;
    node(coord pos, float mini, float maxi);
    node(node* parent, float mini, float maxi, float dist);
    void update(sf::RenderWindow &window);
    void calculateNewAngle(coord target)
};


#endif // NODE_HPP_INCLUDED
