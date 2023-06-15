#pragma once
#include<SFML/Graphics.hpp>
#include "Pacman.h"
#include "Entity.h"

class GhostState;
class HouseMode;
class ChaseMode;
class ScatterMode;
class EatenMode;
class FrightenedMode;

class Ghost: public MovingEntity{
public:
    Ghost(float x, float y, float radius);
    ~Ghost();
    void render(sf::RenderWindow &window) override;
    void setState(GhostState* newState);

    HouseMode* getHouseMode();
    ChaseMode* getChaseMode();
    ScatterMode* getScatterMode();
    EatenMode* getEatenMode();
    FrightenedMode* getFrightenedMode();
protected:
    GhostState* currentState;
    HouseMode* houseMode;
    ChaseMode* chaseMode;
    ScatterMode* scatterMode;
    EatenMode* eatenMode;
    FrightenedMode* frightenedMode;

    bool is_chasing;
    sf::Color color;
    const float ghost_speed = 90.f;
    float ghost_radius;
};


class Blinky : public Ghost {
public:
    Blinky(float x, float y, float radius);
    void updatePosition(float elapsedTime) override;
};

class Clyde : public Ghost {
public:
    Clyde(float x, float y, float radius);
    void updatePosition(float elapsedTime) override;
};

class Inky : public Ghost {
public:
    Inky(float x, float y, float radius);
    void updatePosition(float elapsedTime) override;
};

class Pinky : public Ghost {
public:
    Pinky(float x, float y, float radius);
    void updatePosition(float elapsedTime) override;
};



class GhostState{
protected:
    Ghost* ghost;
public:
    explicit GhostState(Ghost* pGhost);
    virtual void superPacGumEaten() = 0;
    virtual void timerModeOver() = 0;
    virtual void timerFrightenedMode() = 0;
    virtual void eaten() = 0;
    virtual void outsideHouse() = 0;
    virtual void insideHouse() = 0;
    virtual void computeNextDir() = 0;
    virtual sf::Vector2f getTargetPosition() = 0;
};

class HouseMode: public GhostState{
public:
    explicit HouseMode(Ghost* pGhost);
    void superPacGumEaten() override;
    void timerModeOver() override;
    void timerFrightenedMode() override;
    void eaten() override;
    void outsideHouse() override;
    void insideHouse() override;
    void computeNextDir() override;
    sf::Vector2f getTargetPosition() override;
};

class ChaseMode: public GhostState{
public:
    explicit ChaseMode(Ghost* pGhost);
    void superPacGumEaten() override;
    void timerModeOver() override;
    void timerFrightenedMode() override;
    void eaten() override;
    void outsideHouse() override;
    void insideHouse() override;
    void computeNextDir() override;
    sf::Vector2f getTargetPosition() override;
};

class ScatterMode: public GhostState{
public:
    explicit ScatterMode(Ghost* pGhost);
    void superPacGumEaten() override;
    void timerModeOver() override;
    void timerFrightenedMode() override;
    void eaten() override;
    void outsideHouse() override;
    void insideHouse() override;
    void computeNextDir() override;
    sf::Vector2f getTargetPosition() override;
};

class EatenMode: public GhostState{
public:
    explicit EatenMode(Ghost* pGhost);
    void superPacGumEaten() override;
    void timerModeOver() override;
    void timerFrightenedMode() override;
    void eaten() override;
    void outsideHouse() override;
    void insideHouse() override;
    void computeNextDir() override;
    sf::Vector2f getTargetPosition() override;
};

class FrightenedMode: public GhostState{
public:
    explicit FrightenedMode(Ghost* pGhost);
    void superPacGumEaten() override;
    void timerModeOver() override;
    void timerFrightenedMode() override;
    void eaten() override;
    void outsideHouse() override;
    void insideHouse() override;
    void computeNextDir() override;
    sf::Vector2f getTargetPosition() override;
};