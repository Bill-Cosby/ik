#include <math.h>
#include <vector>
#include "../basicObjects.hpp"

struct Quaternion
{
    double a,x,y,z;
};

Quaternion product(Quaternion u,Quaternion v);

Quaternion unitInverse (Quaternion u);

Quaternion p(double theta, Quaternion eulerVector);

Vector3<float> NewPoint(Vector3<float> mypoint, double theta, Vector3<float> eulervector);
