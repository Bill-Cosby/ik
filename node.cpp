#include "node.hpp"

node::node(coord pos, float mini, float maxi)
{
    POS = pos;
    minAngle = mini;
    maxAngle = maxi;
}

node::node(node* par,float mini, float maxi, float dist)
{
    parent = par;
    parent->child = this;
    minAngle = mini;
    maxAngle = maxi;
    POS.setRotatedPos(par->POS,maxi,dist);
}

void node::update(sf::RenderWindow &window)
{
    sf::CircleShape circ;
    circ.setRadius(1);
    circ.setPosition(POS.x, POS.y);
    circ.setFillColor(sf::Color::White);
    window.draw(circ);
}

void node::calculateNewAngle(coord target)
{
    sf::Vector2f(getDistance(POS,target),)
}
