#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include "CelestialBody.hh"
#include "Universe.hh"
/*to convert to string from int*/
template <typename T>
string toString(T val)
{
         stringstream stream;
             stream << val;
                 return stream.str();

}

//not implemented yet
void makeBuildMenu(sf::Vector2f cords,PlayerPlanet * target){

}


int main()
{
    ////////////////////INITILIZING THE WINDOW//////////////////////////////////////
    int WINDOW_WIDTH = 1800;
    int WINDOW_HEIGHT = 1000;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(60);
    ///////////////////////INITILIZING THE UNIVERSE//////////////////////////////////
    bool planetAdded = false;
    CelestialBody * sun = new CelestialBody(sf::Vector2f(0,0),100,100);
    PlayerPlanet * protagPlanet = new PlayerPlanet(sf::Vector2f(0,0),10,10);
    Universe theUniverse = Universe(sun,protagPlanet, sf::Vector2f(500,500));
    int timeToCollision = 400000;
    theUniverse.generate(2,timeToCollision);
    /////////////////////////INITLIZING THE CLOCK & FONT & FPS COUNT///////////////////////////////
    sf::Font font;
    sf::Clock clock;
    int timePassed;
    bool buildingSelected = false;
    bool paused = false;
    if(!font.loadFromFile("../Font/RobotoCondensed-Bold.ttf")){
        cout<< "could not load font" <<endl;
    }
    sf::Text countdownClock;
    sf::Text fpsCounter;
    countdownClock.setFont(font);
    countdownClock.setCharacterSize(30); /*pixels not not points*/
    countdownClock.setColor(sf::Color::White);
    countdownClock.setPosition(700,50);
    fpsCounter.setFont(font);
    fpsCounter.setCharacterSize(30); /*pixels not not points*/
    fpsCounter.setColor(sf::Color::White);
    fpsCounter.setPosition(0,50);
    /////////////////////////////////DIVIDERS AND GUI ELEMENTS////////////////////////
    sf::RectangleShape verticleDivider = sf::RectangleShape(sf::Vector2f(6,970));
    verticleDivider.setPosition(900,15);
    //main loop
    while (window.isOpen())
    {
        //time passed is the time in between frames
        timePassed = clock.restart().asMilliseconds();
        fpsCounter.setString(toString(floor((1.0/((timePassed>0) ? timePassed : (timePassed+1)))*1000)));
        //event loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::LostFocus){
                window.close();
            }
            //Mouse Moved Event, Changes the Active building slot on the GUI Planet``
            if(event.type == sf::Event::MouseMoved){
                sf::Vector2f mousePosition = sf::Vector2f(event.mouseMove.x,event.mouseMove.y);
                mousePosition-= theUniverse.characterPlanet->GUIPlanet.getPosition();
                theUniverse.characterPlanet->deactivateBuildGUI();
                if(sun->vecMag(mousePosition)<350){
                    float theAngle = (180/3.14159) * atan2(mousePosition.y,mousePosition.x);
                    theAngle +=90;
                    theUniverse.characterPlanet->changeSlotAngle(theAngle);
                    theUniverse.characterPlanet->activateBuildGUI();
                }

            }
            if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePosition = sf::Mouse::getPosition();
                if(theUniverse.characterPlanet->buildingGUIActivated){
                    if(theUniverse.characterPlanet->addBuilding() ==  -1){
                        buildingSelected = true;
                    }
                    }else if(mousePosition.x > verticleDivider.getPosition().x){
                       buildingSelected = false;
                    }
            }
        }
        //update loop occurs mutiple times per freame
        for(int i =0; i <= timePassed; i++){
            if(timeToCollision>0){
                theUniverse.update();
                timeToCollision --;
                countdownClock.setString(((timeToCollision<600000)? "0" : "") +toString(timeToCollision/60000)+ ":"
                        + (((timeToCollision%60000)<10000) ? "0" : "") + toString((timeToCollision%60000)/1000) + ":"
                        + (((timeToCollision%1000)<100) ? "0" : "") + toString((timeToCollision%1000)/10));
                if(buildingSelected){
                     theUniverse.viewScreen = false;
                }else{
                     theUniverse.viewScreen = true;
                }
            }
            window.clear();
            window.draw(theUniverse);
            window.draw(countdownClock);
            window.draw(fpsCounter);
            window.draw(verticleDivider);
        }
           //display, only occurs once per frame
            window.display();
    }


    return 0;
}
