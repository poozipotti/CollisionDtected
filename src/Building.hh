#ifndef _BUILDING_H_
#define _BUILDING_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include "CelestialBody.hh"

class Building: public sf::Drawable, public sf::Transformable {
    public:
    Building(sf::Vector2f cords,sf::Vector2f size,float rotation);
    sf::RectangleShape shape;
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:


};
#endif
