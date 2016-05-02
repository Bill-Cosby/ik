#ifndef BASICOBJECTS_HPP_INCLUDED
#define BASICOBJECTS_HPP_INCLUDED
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "math/quaternion.h"


class coord
{
public:
    float x = 0, y = 0;

    coord(int tX, int tY){x = tX;y = tY;}
    coord(){}

    coord setRotatedPos(coord par, float ang, float dist,bool inradians);

    bool operator == (coord t){return t.x == x and t.y == y;}
    bool operator != (coord t){return !(t == *this);}
};

class Vector3
{
public:
    float x = 0, y = 0, z = 0;
    Vector3(float tX, float tY, float tZ){x=tX;y=tY;z=tZ;}
    Vector3(){}

    bool operator == (Vector3 t){return t.x == x and t.y == y and t.z == z;}
    bool operator != (Vector3 t){return !(t == *this);}
};

class Vert
{
public:
    std::string id;
    Vector3 pos;
    std::vector<Vert*> connectedTo;

    Vert(float tX, float tY, float tZ){pos = Vector3(tX,tY,tZ);}
};

class Cube
{
public:
    std::vector<Vert> points;
    Cube();
};

std::vector<Vector3> cube();

float getDistance(coord p1, coord p2);
float getTheta(coord p1, coord p2);

#endif // BASICOBJECTS_HPP_INCLUDED
