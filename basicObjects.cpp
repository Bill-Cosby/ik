#include "basicObjects.hpp"

coord coord::setRotatedPos(coord par, float ang, float dist, bool inradians)
{
    y = dist;
    int _x = x, _y = y;

    if (!inradians)ang = ang*(3.14159/180);

    float sinTheta = sin(ang), cosTheta = cos(ang);

    _x = x * cosTheta - y * sinTheta;
    _y = x * sinTheta + y * cosTheta;

    _x += par.x;
    _y += par.y;

    x = _x;
    y = _y;
}

float getDistance(coord p1, coord p2)
{
    float temp = sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
    return temp;
}

float getTheta(coord p1, coord p2)
{
    return atan2((p1.y-p2.y),(p1.x-p2.x));
}
