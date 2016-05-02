#include "bodyStructure.hpp"

using namespace std;

vector<double> screenCord(vector<double> pointCord)
{
    vector<double> screenCord;

    vector<double> center;
    center.push_back(200);
    center.push_back(200);
    center.push_back(000);

    vector<double> viewerPosition;
    viewerPosition.push_back(0);
    viewerPosition.push_back(0);
    viewerPosition.push_back(600);
    double distToCord=sqrt(pow(pointCord[0]-viewerPosition[0],2)+pow(pointCord[1]-viewerPosition[1],2)+pow(pointCord[2]-viewerPosition[2],2))/200;

    screenCord.push_back(center[0]+pointCord[0]/distToCord);
    screenCord.push_back(center[1]+pointCord[1]/distToCord);

    return screenCord;
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800,600), "IK");
    sf::Event event;

    //window.setFramerateLimit(1);

    vector<double> temp;
    vector<vector<double> > cubeVerts;
    cubeVerts.resize(2);
    for(int a=0; a<1; a++)
    {
        cubeVerts[a].resize(2);
        for(int b=0; b<1; b++)
        {
            cubeVerts[b].resize(2);
            for(int c=0; c<1; c++)
            {

            }
        }
    }


    const double pi = 3.14159;
//    std::vector<double> test;
//    test.push_back(400);
//    test.push_back(200);
//    test.push_back(0);


            sf::Font font;
            font.loadFromFile("PressStart2P-Regular.ttf");
            sf::Text text;
            text.setFont(font);
            text.setCharacterSize(10);

    vector<double> eulervector;
    eulervector.push_back(1000000);
    eulervector.push_back(100000);
    eulervector.push_back(9);


    sf::CircleShape circ;
    circ.setFillColor(sf::Color::White);
    circ.setRadius(20);

    float counter = 0;
    bool increasing = true;

    Cube test;

    while (window.isOpen()){
        if (increasing)counter+=.01;
        else counter-=.01;

        if (counter == 2)increasing = 1-increasing;
        else if (counter == 0)increasing = 1-increasing;
        //vector<double> newPoint=NewPoint(test,counter,eulervector);

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        std::cout << (double)((rand()%100)) << std::endl;


        for (Vert &point : test.points){

            std::vector<double> temp;
                temp.push_back(point.pos.x);
                temp.push_back(point.pos.y);
                temp.push_back(point.pos.z);
            std::vector<double> thisIsInefficient = NewPoint(temp,.0001,eulervector);
            point.pos.x = thisIsInefficient[0];
            point.pos.y = thisIsInefficient[1];
            point.pos.z = thisIsInefficient[2];
        }

        window.clear(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(sf::Color(rand()%255,rand()%255,rand()%255,rand()%255)))))))))))))))))))))));


        for (Vert point : test.points){

            for (Vert *Point : point.connectedTo){
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(point.pos.x*100+100, point.pos.y*100+100)),
                    sf::Vertex(sf::Vector2f(Point->pos.x*100+100, Point->pos.y*100+100))
                };

                window.draw(line, 2, sf::Lines);
            }

//            sf::CircleShape circ;
//            circ.setRadius(2);
//            circ.setPosition(point.pos.x*100+100,point.pos.y*100+100);
//
//
//
//            circ.setFillColor(sf::Color::White);
//            window.draw(circ);
        }

        //circ.setRadius(100/distToCircle);




        window.display();

    }
}
