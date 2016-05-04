#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include "math/quaternion.h"

class Node
{

    Node* parent = nullptr;

    float minAngle = 0;
    float maxAngle = 0;
    float distanceFromParent = 0;
public:
    Node* child = nullptr;
    float currentAngle = 0;
    Vector3<float> POS;
    Node(Vector3<float> pos, float mini, float maxi);
    Node(Node* parent, float mini, float maxi, float dist);
    void calculateNewAngle(Vector3<float> target);

    inline void verticalRotation(float theta);
};


#endif // NODE_HPP_INCLUDED
