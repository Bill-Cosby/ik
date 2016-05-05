#include <bodyStructure.hpp>

BODY_STRUCTURE::BODY_STRUCTURE(Vector3<float> pos)
{
    POS = pos;

    joints.push_back(new Node(pos,15,180));
    joints.push_back(new Node(joints[0],15,180,10));
    joints.push_back(new Node(joints[1],15,180,10));
}

void BODY_STRUCTURE::update(sf::RenderWindow &window, Vector3<float> goal)
{

}

Leg::Leg(Node* Parent) : Limb(POS)
{
    PARENT = Parent;
    joints.push_back(Node(PARENT,-40,50,10));
    joints.push_back(Node(&joints[0],80,0,10));
}
