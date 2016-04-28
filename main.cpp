#include "bodyStructure.hpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "IK");
    sf::Event event;

    BODY_STRUCTURE me(coord(300,300));

    coord goal;

    sf::CircleShape circ;
    circ.setFillColor(sf::Color::Red);
    circ.setRadius(10);

    while (window.isOpen()){
    circ.setPosition(goal.x,goal.y);
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))goal.y-=.1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))goal.y+=.1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))goal.x-=.1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))goal.x+=.1;



        window.clear();
        window.draw(circ);
        me.update(window, goal);
        window.display();

    }
}
