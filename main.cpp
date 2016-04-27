#include "bodyStructure.hpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "IK");
    sf::Event event;

    BODY_STRUCTURE me(coord(300,300));

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        me.update(window);
        window.display();

    }
}
