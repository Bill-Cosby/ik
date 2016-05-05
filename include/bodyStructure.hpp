#ifndef BODYSTRUCTURE_HPP_INCLUDED
#define BODYSTRUCTURE_HPP_INCLUDED
#include <node.hpp>

class Limb
{
public:
    std::vector<Node> joints;
    Vector3<float> POS;
    Limb(Vector3<float> tPOS){POS = tPOS;}
};

class Leg : public Limb
{
    Node* PARENT;
public:
    Leg(Node* Parent);
};

class BODY_STRUCTURE
{
private:
    std::vector<Node*> joints;
    Vector3<float> POS;
public:
    BODY_STRUCTURE(Vector3<float> pos);

    void update(sf::RenderWindow &window,Vector3<float> goal);
};

#endif // BODYSTRUCTURE_HPP_INCLUDED
