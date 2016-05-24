#ifndef _CELESTIALBODY_H_
#define _CELESTIALBODY_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
using namespace std;

class CelestialBody: public sf::Drawable, public sf::Transformable {
    public:
        //mass is mostly for if gravity is reimplemented, size is redius
        CelestialBody(sf::Vector2f cords,float _mass,float _size);
        //this is the coordinateds of the planet
        sf::Vector2f position;
        //this is the velocity of the planet
        sf::Vector2f velocity;
        //this simply applies a vector to the acceleration
        void move(sf::Vector2f);
        //update is called based on a timer, and updates the speed etc of the planet
        virtual void update();
        //gives the magnitude of a vector, this should probably be moved
        float vecMag(sf::Vector2f);
        const static int GRAVITY_FORCE = 1; /*how strong gravity is in this universe*/
        //addBody adds a body whose Gravity will affect the Celestial Body, this is no longer implemented
        void addBody(CelestialBody);
        //if the planet is out of bounds, has collided etc.
        bool dead;
        //changes the planet Color
        virtual void changeColor(sf::Color);
        //this is the color of the Planet
        sf::Color color;
        //this is the circle that is the planet
        sf::CircleShape shape;
        //represents the size of the planet
        float size;
    protected:
        //vector of all the bodies whose gravity affect this one
        vector<CelestialBody> affectedBy;
        //the acceleration of the body
        sf::Vector2f acceleration;
        //Draws the planet in the window
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        //this is the mass of the planet
        float mass;
};
#endif

