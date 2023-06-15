#pragma once
#include "Entity.h"

class Ghost: public MovingEntity{
protected:
    sf::Color color;
    const float ghost_speed = 90.f;
    float ghost_radius;
public:
    void render(sf::RenderWindow &window) override;
    Ghost(float x, float y, float radius);
};


class Blinky : public Ghost {
public:
    Blinky(float x, float y, float radius);
    //void updatePosition(float elapsedTime) final;
};

class Clyde : public Ghost {
public:
    Clyde(float x, float y, float radius);
    //void updatePosition(float elapsedTime) final;
};

class Inky : public Ghost {
public:
    Inky(float x, float y, float radius);
    //void updatePosition(float elapsedTime) final;
};

class Pinky : public Ghost {
public:
    Pinky(float x, float y, float radius);
    //void updatePosition(float elapsedTime) final;
};