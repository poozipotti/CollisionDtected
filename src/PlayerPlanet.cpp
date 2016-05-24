#include "PlayerPlanet.hh"
PlayerPlanet::PlayerPlanet(sf::Vector2f cords, float _mass, float _size)
:  CelestialBody(cords,_mass,_size){
    planetCreated = false;
    deactivateBuildGUI();
    int j=-((360/buildingSlots)/2),h=(360/buildingSlots)/2;

    for(int i = 0; i< buildingSlots; i++){
        slots[i] = false;
        buildingLineRotations[i]=j;
        buildingLineRotations[i+buildingSlots]=h;
        j+= 360/buildingSlots;
        h+= 360/buildingSlots;
    }
}
void PlayerPlanet::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    if(viewScreen)
    CelestialBody::draw(target,states);
    if(buildingGUIActivated){
        target.draw(buildRect1);
        target.draw(buildRect2);
    }
    if(Buildings.size()>0){
        for(int i = 0;i<Buildings.size();i++){
            target.draw(*(Buildings[i]));
        }
    }
    target.draw(GUIPlanet);
}
void PlayerPlanet::activateBuildGUI(){
        buildingGUIActivated = true;
}
void PlayerPlanet::deactivateBuildGUI(){
        buildingGUIActivated = false;
}

void PlayerPlanet::createGUIPlanet(sf::Vector2f pos,float _size){
    GUIPlanetSize = _size;
    cout<<GUIPlanetSize<<endl;
    GUIPlanet = sf::CircleShape(GUIPlanetSize);
    GUIPlanet.setOrigin(GUIPlanetSize,GUIPlanetSize);
    GUIPlanet.setFillColor(color);
    GUIPlanet.setPosition(pos);
    buildRect1 = sf::RectangleShape(sf::Vector2f(10,GUIPlanetSize*1.5));
    buildRect1.setOrigin(5,0);
    buildRect2 = sf::RectangleShape(sf::Vector2f(10,GUIPlanetSize*1.5));
    buildRect2.setOrigin(5,0);
    buildingGUIActivated = false;
    buildRect1.setPosition(pos.x,pos.y);
    buildRect2.setPosition(pos.x,pos.y);
    changeSlot(0);
}
int PlayerPlanet::addBuilding(){
    //returns -1 if a building is not added
    if(slots[activeSlot] == false){
        int temp = Buildings.size();
        Buildings.push_back(new Building(GUIPlanet.getPosition(),sf::Vector2f(360/buildingSlots*GUIPlanetSize*.8*(3.14/180),GUIPlanetSize*1.2),360/buildingSlots*activeSlot)); /*eventually this will be an  actual Building object*/
        slots[activeSlot] = true;
        return activeSlot;
    }
    return -1;
}
void PlayerPlanet::changeColor(sf::Color x){
    CelestialBody::changeColor(x);
    GUIPlanet.setFillColor(x);
}
void PlayerPlanet::changeSlot(int x){
    x%=buildingSlots;
    buildRect1.setRotation(buildingLineRotations[x]+180);
    buildRect2.setRotation(buildingLineRotations[x+buildingSlots]+180);
    activeSlot = x;
}
void PlayerPlanet::changeSlotAngle(float x){
    /*changes the acctive build slot according to the angle with 0 being straight up.*/
    x=round(x);
    if(x<0){
         x+=360;
    }
    if(x>360){
    cout << "something is very wrong" << endl;
    }
    x /= (360/buildingSlots);
    changeSlot(round(x));
}

