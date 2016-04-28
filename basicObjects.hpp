#ifndef BASICOBJECTS_HPP_INCLUDED
#define BASICOBJECTS_HPP_INCLUDED
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>

class coord
{
public:
    float x = 0, y = 0;

    coord(int tX, int tY){x = tX;y = tY;}
    coord(){x = 0; y = 0;}

    coord setRotatedPos(coord par, float ang, float dist,bool inradians);

    bool operator == (coord t){return t.x == x and t.y == y;}
    bool operator != (coord t){return !(t == *this);}
};

float getDistance(coord p1, coord p2);
float getTheta(coord p1, coord p2);

#endif // BASICOBJECTS_HPP_INCLUDED
