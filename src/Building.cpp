#include "Building.hh"
Building::Building(sf::Vector2f cords,sf::Vector2f size,float rotation){
        shape = sf::RectangleShape(size);
        shape.setFillColor(sf::Color::White);
        shape.setPosition(cords);
        shape.setRotation(rotation);
        shape.setOrigin(shape.getSize().x/2,shape.getSize().y);
}
sf::Vector2f Building::getSize(){

}
sf::Vector2f Building::getPosition(){

}
void Building::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(shape);
}

