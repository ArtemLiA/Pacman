#pragma once
#include "Entity.h"

class Pacman: public MovingEntity{
private:
    const sf::Color pacman_color = sf::Color::Yellow;
    const float pacman_radius = 24.f;
    const float pacman_speed = 2.5f;
public:
	explicit Pacman(float x = 0, float y = 0);
	void updatePacmanDirection();
    void updatePosition(float elapsedTime) override;
    void render(sf::RenderWindow& window) override;
    sf::Vector2f getPacmanPosition();
    Direction getPacmanDirection();
};

