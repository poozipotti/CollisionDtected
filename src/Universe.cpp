#include "Universe.hh"
Universe::Universe(CelestialBody * _primaryBody,PlayerPlanet * _characterPlanet,sf::Vector2f pos){
    Upos = pos;
    primaryBody = _primaryBody;
    characterPlanet = _characterPlanet;
    planetSize = characterPlanet->size;
    primaryBody->changeColor(sf::Color::Yellow);
    primaryBody->setPosition(Upos);
    GUIPlanetPos =sf::Vector2f(900+(900/2),700);
    ((PlayerPlanet *)characterPlanet)->createGUIPlanet(GUIPlanetPos,200);
    characterPlanet->setPosition(Upos);
    addBody(characterPlanet);
    viewScreen = true;
}
void Universe::addBody(CelestialBody * secondaryBody){
    secondaryBody->changeColor(*(new sf::Color(rand()%255,rand()%255,rand()%255)));
    secondaryBodies.push_back(secondaryBody);
}
void Universe::generate(int numberOfBodies, int timeToCollision){
    numberOfBodies = 2; /*just for now, we only want two more planets*/
    orbitRadius = 250;
    rotationalSpeeds = new float[numberOfBodies];
    float baseRotateSpeed = .05; /*how fast the slower of the two bodies moves*/
    rotationalSpeeds[0] = baseRotateSpeed;
    for(int i = 0; i<numberOfBodies; i++){
        if(i!=0){
            addBody(new CelestialBody(sf::Vector2f(Upos.x, Upos.y) ,10,10));
        }
        secondaryBodies[i]->setOrigin(sf::Vector2f(-orbitRadius,secondaryBodies[secondaryBodies.size() -1]->size));
        secondaryBodies[i]->changeColor(*(new sf::Color(rand()%255,rand()%255,rand()%255)));
    }
    /*will only work for two bodies*/
    if(numberOfBodies = 2){
        float secondRotate = -90;
        secondaryBodies[1]->rotate(secondRotate); //second planet, first will always be player planet
        rotationalSpeeds[1] = baseRotateSpeed + ((-1*secondRotate)/(timeToCollision*1.05));

    }

}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(*characterPlanet);
    if(!viewScreen){
        characterPlanet->viewScreen = false;
    }else{
        characterPlanet->viewScreen = true;
    }
    if(viewScreen){
        target.draw(* primaryBody);
        for(int i =1; i < secondaryBodies.size(); i++){
            target.draw(*secondaryBodies[i]);
        }
    }

}
void Universe::update(){
    for(int i =0; i < secondaryBodies.size(); i++){
        secondaryBodies[i]->rotate(rotationalSpeeds[i]);
    }
}
