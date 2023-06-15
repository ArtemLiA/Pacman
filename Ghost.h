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
    void setPacman(Pacman* pPacman);
    bool isChasing() const;
    void setChasingStatus(bool isChasing);
    void setDangerousStatus(bool isDangerous);
    sf::Vector2f get_position();

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

    Pacman* pacman;

    bool is_dangerous;
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
    virtual void superPacGumEaten();
    virtual void timerModeOver();
    virtual void timerFrightenedMode();
    virtual void eaten();
    virtual void outsideHouse();
    virtual void insideHouse();
    virtual void computeNextDir();
    virtual sf::Vector2f getTargetPosition();
    virtual void setDangerousStatus();
};

class HouseMode: public GhostState{
public:
    explicit HouseMode(Ghost* pGhost);
    void outsideHouse() override;
    sf::Vector2f getTargetPosition() override;
    void setDangerousStatus() override;
};

class ChaseMode: public GhostState{
public:
    explicit ChaseMode(Ghost* pGhost);
    void superPacGumEaten() override;
    void timerModeOver() override;
    sf::Vector2f getTargetPosition() override;
    void setDangerousStatus() override;
};

class ScatterMode: public GhostState{
public:
    explicit ScatterMode(Ghost* pGhost);
    void superPacGumEaten() override;
    void timerModeOver() override;
    sf::Vector2f getTargetPosition() override;
    void setDangerousStatus() override;
};

class EatenMode: public GhostState{
public:
    explicit EatenMode(Ghost* pGhost);
    void insideHouse() override;
    sf::Vector2f getTargetPosition() override;
    void setDangerousStatus() override;
};

class FrightenedMode: public GhostState{
public:
    explicit FrightenedMode(Ghost* pGhost);
    void timerFrightenedMode() override;
    void eaten() override;
    sf::Vector2f getTargetPosition() override;
    void setDangerousStatus() override;
};