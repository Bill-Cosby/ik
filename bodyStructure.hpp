#ifndef BODYSTRUCTURE_HPP_INCLUDED
#define BODYSTRUCTURE_HPP_INCLUDED
#include "node.hpp"

class BODY_STRUCTURE
{
private:
    std::vector<node*> joints;
    coord POS;
public:
    BODY_STRUCTURE(coord pos);

    void update(sf::RenderWindow &window,coord goal);
};

#endif // BODYSTRUCTURE_HPP_INCLUDED
