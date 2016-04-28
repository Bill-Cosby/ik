#include "bodyStructure.hpp"

BODY_STRUCTURE::BODY_STRUCTURE(coord pos)
{
    POS = pos;

    joints.push_back(new node(pos,15,180));
    joints.push_back(new node(joints[0],15,180,10));
    joints.push_back(new node(joints[1],15,180,10));
}

void BODY_STRUCTURE::update(sf::RenderWindow &window, coord goal)
{
    for (int i = joints.size()-1;i>=0;i--){
        if (joints[i]->child!=nullptr)joints[i]->update(window,goal);
        else{
            joints[i]->update(window);
        }
    }
}
