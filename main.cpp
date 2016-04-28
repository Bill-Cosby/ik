#include "bodyStructure.hpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "IK");
    sf::Event event;

    const double pi = 3.14159;
    std::vector<double> test;
    test.push_back(1);
    test.push_back(0);
    test.push_back(0);


    vector<double> eulervector;
    eulervector.push_back(0);
    eulervector.push_back(1);
    eulervector.push_back(0);

    while (window.isOpen()){
    circ.setPosition(goal.x,goal.y);

        vector<double> newPoint=NewPoint(test,pi/2,eulervector);

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }




        window.clear();
        window.draw(circ);
        me.update(window, goal);
        window.display();

    }
}
