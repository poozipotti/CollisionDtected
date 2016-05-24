#ifndef _PLAYERPLANET_H_
#define _PLAYERPLANET_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <iostream>
#include "CelestialBody.hh"
#include "Building.hh"

class PlayerPlanet: public CelestialBody{
    public:
    PlayerPlanet(sf::Vector2f cords, float _mass, float _size);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void createGUIPlanet(sf::Vector2f pos,float _size);
    sf::CircleShape GUIPlanet;
    sf::RectangleShape buildRect1;
    sf::RectangleShape buildRect2;
    virtual void changeColor(sf::Color);
    void changeSlot(int);
    void changeSlotAngle(float);
    float GUIPlanetSize;
    bool buildingGUIActivated; /*if the mouse is close enough to show the build menu*/
    void activateBuildGUI();
    void deactivateBuildGUI();
    int addBuilding();
    int activeSlot;
    bool viewScreen;

    protected:
    bool planetCreated;
    static const int buildingSlots = 10;
    bool slots[buildingSlots];
    float buildingLineRotations[buildingSlots*2]; /*first half is first build rect, second half is second build rect*/
    vector<Building *> Buildings;
};
#endif
