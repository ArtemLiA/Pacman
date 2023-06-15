#include "Entity.h"
#include <iostream>

//Static Entity
sf::FloatRect StaticEntity::getBounds(){
    return shape.getGlobalBounds();
}

//PacGum
PacGum::PacGum(float x, float y, float s){
    position.x = x;
    position.y = y;
    size = s;
}
void PacGum::render(sf::RenderWindow &window) {
    shape.setFillColor(sf::Color(255, 183, 174));
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(position);
}

//SuperPacGum
SuperPacGum::SuperPacGum(float x, float y, float s) {
    position.x = x;
    position.y = y;
    size = s;
}
void SuperPacGum::render(sf::RenderWindow &window){
    shape.setFillColor(sf::Color(255, 183, 174));
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(position);
}

//Moving Entity
MovingEntity::MovingEntity(float x, float y){
    position = {x, y};
    speedVec = {0.0f , 0.0f};
    direction = Direction::NONE;
}

void MovingEntity::updatePosition(float elapsedTime){}
void MovingEntity::render(sf::RenderWindow &window){}
sf::FloatRect MovingEntity::getBounds(){
    return shape.getGlobalBounds();
}

