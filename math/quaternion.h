#include <math.h>
#include <vector>

struct Quaternion
{
    double a,x,y,z;
};

Quaternion product(Quaternion u,Quaternion v);

Quaternion unitInverse (Quaternion u);

Quaternion p(double theta, Quaternion eulerVector);

std::vector<double> NewPoint(std::vector<double> mypoint, double theta, std::vector<double> eulervector);
