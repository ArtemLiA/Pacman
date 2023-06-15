#include "Pacman.h"
#include <iostream>

Pacman::Pacman(float x, float y): MovingEntity(x, y){
    shape.setRadius(pacman_radius);
    shape.setFillColor(pacman_color);
    shape.setPosition(position);
}

void Pacman::updatePacmanDirection() {
    direction = Direction::NONE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        direction = Direction::UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
             || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        direction = Direction::DOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        direction = Direction::LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
             || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        direction = Direction::RIGHT;
    }
}

void Pacman::updatePosition(float elapsedTime) {
    sf::Vector2f move = {0.0f, 0.0f};
    updatePacmanDirection();

    if (direction == Direction::UP){
        move = {0.0f, -pacman_speed};
    }
    if (direction == Direction::DOWN){
        move = {0.0f, pacman_speed};
    }
    if (direction == Direction::LEFT){
        move = {-pacman_speed, 0.0f};
    }
    if (direction == Direction::RIGHT){
        move = {pacman_speed, 0.0f};
    }

    const sf::FloatRect pacmanBounds = shape.getGlobalBounds();
    //  if (checkFieldWallsCollision(field, pacmanBounds, movement))
    // {
    // Останавливаем пакмана при столкновении
    //      direction = Direction::NONE;
    // }
    shape.move(move);
}

void Pacman::render(sf::RenderWindow &window){
    window.draw(shape);
}

