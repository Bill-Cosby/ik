#include <node.hpp>

Node::Node(Vector3<float> pos, float mini, float maxi)
{
    POS = pos;
    minAngle = mini;
    maxAngle = maxi;
    currentAngle = maxi;
}

Node::Node(Node* par,float mini, float maxi, float dist)
{
    parent = par;
    parent->child = this;
    minAngle = mini;
    maxAngle = maxi;
    currentAngle = maxi;
    distanceFromParent = dist;
}

inline void Node::verticalRotation(float theta)
{
    POS = NewPoint(POS, theta, Vector3<float>(0,1,0));
}

void Node::calculateNewAngle(Vector3<float> target)
{

    Vector3<float> temp = POS;
//
//    sf::Vector2f vecA(getDistance(POS,target),getTheta(POS,target));

    sf::Vector2f vecB(distanceFromParent,(currentAngle+90)*(3.14159/180));

//    float dotProduct = vecB.x * vecA.x * cos(vecB.y+vecA.y)*.01;

//    if (abs(dotProduct) <.01)return;

//     POS.setRotatedPos(parent->POS,dotProduct+currentAngle,distanceFromParent,false);

//    currentAngle += dotProduct;

}
