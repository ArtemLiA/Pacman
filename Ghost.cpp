#include "Ghost.h"
#include <iostream>

Ghost::Ghost(float x, float y, float radius): MovingEntity(x, y) {
    ghost_radius = radius;
}

void Ghost::render(sf::RenderWindow &window){
    shape.setPosition(position);
    shape.setRadius(ghost_radius);
    shape.setFillColor(color);

    window.draw(shape);
}

Blinky::Blinky(float x, float y, float radius): Ghost(x, y, radius){
    color = sf::Color::Red;
}

Clyde::Clyde(float x, float y, float radius): Ghost(x, y, radius){
    color = sf::Color(40, 87, 158);
}

Inky::Inky(float x, float y, float radius): Ghost(x, y, radius){
    color = sf::Color::Blue;
}

Pinky::Pinky(float x, float y, float radius):
Ghost(x, y, radius){
    color = sf::Color::Magenta;
}
