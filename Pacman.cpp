#include "Pacman.h"

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
    updatePacmanDirection();

    if (direction == Direction::UP){
        position += {0.0f, -pacman_speed};
    }
    if (direction == Direction::DOWN){
        position += {0.0f, pacman_speed};
    }
    if (direction == Direction::LEFT){
        position += {-pacman_speed, 0.0f};
    }
    if (direction == Direction::RIGHT){
        position += {pacman_speed, 0.0f};
    }

}

void Pacman::render(sf::RenderWindow &window){
    shape.setPosition(position);
    window.draw(shape);
}

sf::Vector2f Pacman::getPacmanPosition(){
    return position;
}

Direction Pacman::getPacmanDirection(){
    return direction;
}

