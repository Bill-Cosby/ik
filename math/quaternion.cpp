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

vector<double> NewPoint(vector<double> mypoint, double theta, vector<double> eulervector)
{
    Quaternion eulerVector;
    eulerVector.a=0;
    eulerVector.x=eulervector[0];
    eulerVector.y=eulervector[1];
    eulerVector.z=eulervector[2];
    double eulerLength=pow(pow(eulerVector.x,2)+pow(eulerVector.y,2)+pow(eulerVector.z,2),0.5);

    euler.x=euler.x/eulerLength;
    euler.y=euler.y/eulerLength;
    euler.z=euler.z/eulerLength;

    Quaternion myPoint;
    myPoint.a=0;
    myPoint.x=mypoint[0];
    myPoint.y=mypoint[1];
    myPoint.z=mypoint[2];


    Quaternion q=p(theta, eulerVector);
    Quaternion newPoint;
    newPoint=product(q,product(myPoint,unitInverse(q)));
    vector<double> newpoint;
    newpoint.push_back(newPoint.x);
    newpoint.push_back(newPoint.y);
    newpoint.push_back(newPoint.z);
    return newpoint;



}


