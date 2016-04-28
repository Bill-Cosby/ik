#include "bodyStructure.hpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "IK");
    sf::Event event;

    window.setFramerateLimit(60);

    const double pi = 3.14159;
    std::vector<double> test;
    test.push_back(20);
    test.push_back(20);
    test.push_back(20);


    vector<double> eulervector;
    eulervector.push_back(.5);
    eulervector.push_back(1);
    eulervector.push_back(0);

    sf::CircleShape circ;
    circ.setFillColor(sf::Color::White);

    float counter = 0;
    bool increasing = true;

    while (window.isOpen()){
        if (increasing)counter+=.01;
        else counter-=.01;

        if (counter == 2)increasing = 1-increasing;
        else if (counter == 0)increasing = 1-increasing;
        vector<double> newPoint=NewPoint(test,counter,eulervector);

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        std::cout << newPoint[2] << std::endl;
        circ.setRadius(test[2]+newPoint[2]);
        circ.setPosition(newPoint[0]+1,newPoint[1]+1);


        window.clear();
        window.draw(circ);
        window.display();

    }
}
