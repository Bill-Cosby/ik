#include <bodyStructure.hpp>

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

    vector<double> eulervector;
    eulervector.push_back(1);
    eulervector.push_back(2);
    eulervector.push_back(0);


    sf::CircleShape circ;
    circ.setFillColor(sf::Color::White);
    circ.setRadius(20);

    float counter = 0;
    bool increasing = true;

    std::vector<Cube> cubes;
    cubes.push_back(Cube(0,0,0));

    Vector3<float> parent(1,1,0);
    Vector3<float> child(1,2,0);
    Vector3<float> endEffector(1,3,0);

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
/////////////////////ROTATE CUBES///////////////////////////////////
//        for (Cube &test : cubes){
//            for (Vert &point : test.points){
//
//                std::vector<double> temp;
//                    temp.push_back(point.pos.x);
//                    temp.push_back(point.pos.y);
//                    temp.push_back(point.pos.z);
//                std::vector<double> thisIsInefficient = NewPoint(temp,.0001,eulervector);
//                point.pos.x = thisIsInefficient[0];
//                point.pos.y = thisIsInefficient[1];
//                point.pos.z = thisIsInefficient[2];
//
//            }
//        }
////////////////////////////////////////////////////////////////////

        //endEffector.convertstdVecToVec3(NewPoint(endEffector.convertTostdVec(),1,crossProduct(parent,child).convertTostdVec()));

//                std::vector<double> temp;
//                    temp.push_back(endEffector.x);
//                    temp.push_back(endEffector.y);
//                    temp.push_back(endEffector.z);
//
//        std::vector<double> newestPoint = NewPoint(temp,.0001,eulervector);
//
//        endEffector.x = newestPoint[0];
//        endEffector.y = newestPoint[1];
//        endEffector.z = newestPoint[2];

        Vector3<float> crossProductToUse = crossProduct(parent,child);

        parent = NewPoint(parent,.001,Vector3<float>(0,1,0));
        child = NewPoint(child,.001,Vector3<float>(0,1,0));
        endEffector = NewPoint(endEffector,.001,Vector3<float>(0,1,0));
        std::cout << crossProductToUse.x << "," << crossProductToUse.y << "," << crossProductToUse.z << std::endl;

        endEffector -= child;

        endEffector = NewPoint(endEffector,.001,crossProductToUse);

        endEffector += child;


        window.clear();

        sf::Vertex line[] = {

            sf::Vertex(sf::Vector2f(parent.x*100+200,parent.y*100+200)),
            sf::Vertex(sf::Vector2f(child.x*100+200,child.y*100+200))

        };


        window.draw(line,2, sf::Lines);

        sf::Vertex line2[] = {

            sf::Vertex(sf::Vector2f(child.x*100+200,child.y*100+200)),
            sf::Vertex(sf::Vector2f(endEffector.x*100+200,endEffector.y*100+200))

        };

        window.draw(line2,2, sf::Lines);

///////////////DRAW CUBES///////////////////////////////////////////
//        for (Cube test : cubes){
//            for (Vert point : test.points){
//
//                for (Vert *Point : point.connectedTo){
//                    sf::Vertex line[] =
//                    {
//                        sf::Vertex(sf::Vector2f(point.pos.x*100+100, point.pos.y*100+100)),
//                        sf::Vertex(sf::Vector2f(Point->pos.x*100+100, Point->pos.y*100+100))
//                    };
//
//                    window.draw(line, 2, sf::Lines);
//                }
//            }
//        }
////////////////////////////////////////////////////////////////////

        window.display();

    }
}
