#include <iostream>
#include "quaternion.h"

using namespace std;

Quaternion product(Quaternion u,Quaternion v)
{
    Quaternion w;
    w.a=u.a*v.a-u.x*v.x-u.y*v.y-u.z*v.z;
    w.x=u.a*v.x+u.x*v.a+u.y*v.z-u.z*v.y;
    w.y=u.a*v.y-u.x*v.z+u.y*v.a+u.z*v.x;
    w.z=u.a*v.z+u.x*v.y-u.y*v.x+u.z*v.a;
    return w;
}

Quaternion unitInverse (Quaternion u)
{
Quaternion w;
w.a=u.a;
w.x=-u.x;
w.y=-u.y;
w.z=-u.z;
return w;
}

Quaternion p(double theta, Quaternion eulerVector)
{
    Quaternion q;
    q.a=cos(theta/2);
    q.x=sin(theta/2)*eulerVector.x;
    q.y=sin(theta/2)*eulerVector.y;
    q.z=sin(theta/2)*eulerVector.z;
    return q;
}

Vector3 NewPoint(Vector3 mypoint, double theta, Vector3 eulervector)
{

    Quaternion eulerVector;
    eulerVector.a=0;
    eulerVector.x=eulervector.x;
    eulerVector.y=eulervector.y;
    eulerVector.z=eulervector.z;
    double eulerLength=pow(pow(eulerVector.x,2)+pow(eulerVector.y,2)+pow(eulerVector.z,2),0.5);

    eulerVector.x=eulerVector.x/eulerLength;
    eulerVector.y=eulerVector.y/eulerLength;
    eulerVector.z=eulerVector.z/eulerLength;

    Quaternion myPoint;
    myPoint.a=0;
    myPoint.x=mypoint.x;
    myPoint.y=mypoint.y;
    myPoint.z=mypoint.z;


    Quaternion q=p(theta, eulerVector);
    Quaternion newPoint;
    newPoint=product(q,product(myPoint,unitInverse(q)));
    Vector3 newpoint;
    newpoint.x = newPoint.x;
    newpoint.y = newPoint.y;
    newpoint.z = newPoint.z;
    return newpoint;

}


