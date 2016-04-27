#include "bodyStructure.hpp"

BODY_STRUCTURE::BODY_STRUCTURE(coord pos)
{
    POS = pos;

    joints.push_back(new node(pos,15,180));
    joints.push_back(new node(joints[0],15,180,10));
    joints.push_back(new node(joints[1],15,180,10));
}
