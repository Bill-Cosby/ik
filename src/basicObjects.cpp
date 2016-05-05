#include <basicObjects.hpp>

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

Vector3<float> crossProduct(Vector3<float> parent, Vector3<float> child)
{
    Vector3<float> newVec;
    newVec.x = (child.y * parent.z - child.z * parent.y);
    newVec.y = (child.z * parent.x - child.x * parent.z);
    newVec.z = (child.x * parent.y - child.y * parent.x);
    return newVec;
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

Cube::Cube(int x, int y, int z)
{
    points.push_back(Vert(x+0,y+0,z+0));
    points[0].id = "0";
    points.push_back(Vert(x+1,y+0,z+0));
    points[1].id = "1";
    points.push_back(Vert(x+1,y+0,z+1));
    points[2].id = "2";
    points.push_back(Vert(x+0,y+0,z+1));
    points[3].id = "3";
    points.push_back(Vert(x+0,y+1,z+0));
    points[4].id = "4";
    points.push_back(Vert(x+1,y+1,z+0));
    points[5].id = "5";
    points.push_back(Vert(x+1,y+1,z+1));
    points[6].id = "6";
    points.push_back(Vert(x+0,y+1,z+1));
    points[7].id = "7";

    points[0].connectedTo.push_back(&points[1]);
    points[0].connectedTo.push_back(&points[3]);
    points[0].connectedTo.push_back(&points[4]);

    points[1].connectedTo.push_back(&points[0]);
    points[1].connectedTo.push_back(&points[2]);
    points[1].connectedTo.push_back(&points[5]);

    points[2].connectedTo.push_back(&points[1]);
    points[2].connectedTo.push_back(&points[3]);
    points[2].connectedTo.push_back(&points[6]);

    points[3].connectedTo.push_back(&points[2]);
    points[3].connectedTo.push_back(&points[0]);
    points[3].connectedTo.push_back(&points[7]);

    points[4].connectedTo.push_back(&points[0]);
    points[4].connectedTo.push_back(&points[5]);
    points[4].connectedTo.push_back(&points[7]);

    points[5].connectedTo.push_back(&points[1]);
    points[5].connectedTo.push_back(&points[4]);
    points[5].connectedTo.push_back(&points[6]);

    points[6].connectedTo.push_back(&points[5]);
    points[6].connectedTo.push_back(&points[7]);
    points[6].connectedTo.push_back(&points[2]);

    points[7].connectedTo.push_back(&points[6]);
    points[7].connectedTo.push_back(&points[4]);
    points[7].connectedTo.push_back(&points[3]);
}
