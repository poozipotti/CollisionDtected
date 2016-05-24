#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include "CelestialBody.hh"
#include "PlayerPlanet.hh"
using namespace std;
class Universe: public sf::Drawable, public sf::Transformable {
    public:
        Universe(CelestialBody * _primaryBody,PlayerPlanet * _characterPlanet,sf::Vector2f pos);
        void generate(int numberOfBodies, int timeToCollision);
        /* NOT YET IMPLEMENTED WILL BE FIXED LATER
         * MAKE SURE TO FIX HOW THE ORBITS WORK IN COLLISION
         * SO THAT EVERYTHING WILL INTERACT CORRECTLY
         * void addElepticalOrbit(CelestialBody *);
        *void addCircularOrbit(CelestialBody *);
        */
        int calulatePosition(CelestialBody * body,float time);
        void update();
        sf::Vector2f GUIPlanetPos;
        float orbitRadius;
        void addBody(CelestialBody * secondaryBody);
        float * rotationalSpeeds;
        bool viewScreen;
        sf::Vector2f Upos;
        PlayerPlanet * characterPlanet;

    protected:
        vector<CelestialBody *> secondaryBodies;
        CelestialBody * primaryBody;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        float planetSize;

};

#endif

