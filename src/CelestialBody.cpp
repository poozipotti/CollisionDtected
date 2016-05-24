#include "CelestialBody.hh"
//constructer
CelestialBody::CelestialBody(sf::Vector2f cords,float _mass,float _size){
    //this puts the origin in the center of the shape, it makes it easier to work with
    setOrigin(sf::Vector2f(_size,_size));
    //sets the internally stored position to the coordinates inputted
    position=cords;
    //sets the actual position in the window to the coordinates inputted
    setPosition(position);
    //sets variables to their input or default value
    size = _size;
    mass = _mass;
    dead = false;
    shape = sf::CircleShape(size);
    color = sf::Color::White;

}
void CelestialBody::update(){
    if(!dead){
    //the loop is calculating and applying gravity
    for(int i=0;i<affectedBy.size();i++){
        //this is not implemented at th moment because i haven't
        //figured out how to calculate orbits that eventually collide
        sf::Vector2f temp = affectedBy[i].position - position;
        if(vecMag(temp) < affectedBy[i].size + size){
            dead = true;
            return;
        }
        acceleration += ((CelestialBody::GRAVITY_FORCE * (mass*affectedBy[i].mass)) / (vecMag(temp)*vecMag(temp)))* (temp/vecMag(temp));

        }

        //this is standard for acceleration based input
        position += velocity;
        setPosition(position);
        velocity += acceleration;
        acceleration *= 0.0f;
    }
}
void CelestialBody::move(sf::Vector2f _move){
    //simply applies a vector to the acceleration
    acceleration += _move;
}
float CelestialBody::vecMag(sf::Vector2f inputVector){
    //returns magnitude of vector probably should be moved
    return(sqrt(pow(inputVector.x,2)+pow(inputVector.y,2)));
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    if(!dead){
        states.transform *= getTransform();
        target.draw(shape, states);
    }
}

void CelestialBody::addBody(CelestialBody x){
    affectedBy.push_back(x);
    cout<<"body added"<<endl;
}

void CelestialBody::changeColor(sf::Color x){
    color=x;
    shape.setFillColor(x);
}
