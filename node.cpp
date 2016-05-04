#include "node.hpp"

node::node(coord pos, float mini, float maxi)
{
    POS = pos;
    minAngle = mini;
    maxAngle = maxi;
    currentAngle = maxi;
}

node::node(node* par,float mini, float maxi, float dist)
{
    parent = par;
    parent->child = this;
    minAngle = mini;
    maxAngle = maxi;
    currentAngle = maxi;
    POS.setRotatedPos(par->POS,maxi,dist,false);
    distanceFromParent = dist;
}

void node::update(sf::RenderWindow &window, coord goal)
{
    sf::CircleShape circ;
    circ.setRadius(1);
    circ.setPosition(POS.x, POS.y);
    circ.setFillColor(sf::Color::White);

    if (parent)calculateNewAngle(goal);


    window.draw(circ);
}

void node::update(sf::RenderWindow &window)
{
    sf::CircleShape circ;
    circ.setRadius(1);
    circ.setFillColor(sf::Color::White);

    POS.setRotatedPos(parent->POS,parent->currentAngle,distanceFromParent,true);
    circ.setPosition(POS.x, POS.y);

    std::cout << POS.x << "," << POS.y << std::endl;



    window.draw(circ);
}

void node::calculateNewAngle(coord target)
{

    coord temp = POS;
    sf::Vector2f vecA(getDistance(POS,target),getTheta(POS,target));

    sf::Vector2f vecB(distanceFromParent,(currentAngle+90)*(3.14159/180));

    float dotProduct = vecB.x * vecA.x * cos(vecB.y+vecA.y)*.01;

    if (abs(dotProduct) <.01)return;

     POS.setRotatedPos(parent->POS,dotProduct+currentAngle,distanceFromParent,false);

    currentAngle += dotProduct;

}
