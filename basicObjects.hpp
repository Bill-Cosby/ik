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

    std::vector<double> convertTostdVec(){std::vector<double> temp;temp.push_back(x);temp.push_back(y);temp.push_back(z);return temp;}
    void convertstdVecToVec3(std::vector<double> temp){x = temp[0];y = temp[1];z = temp[2];}

    bool operator == (Vector3 t){return t.x == x and t.y == y and t.z == z;}
    bool operator != (Vector3 t){return !(t == *this);}
    void operator -= (Vector3 t){x-=t.x;y-=t.y;z-=t.z;}
    void operator += (Vector3 t){x+=t.x;y+=t.y;z+=t.z;}
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
    Cube(int x, int y, int z);
};

Vector3 crossProduct(Vector3 parent, Vector3 child);

std::vector<Vector3> cube();

float getDistance(coord p1, coord p2);
float getTheta(coord p1, coord p2);

#endif // BASICOBJECTS_HPP_INCLUDED
