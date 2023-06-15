#include "Ghost.h"
#include <iostream>

Ghost::Ghost(float x, float y, float radius): MovingEntity(x, y){
    is_chasing = false;
    ghost_radius = radius;

    houseMode = new HouseMode(this);
    chaseMode = new ChaseMode(this);
    scatterMode = new ScatterMode(this);
    eatenMode = new EatenMode(this);
    frightenedMode = new FrightenedMode(this);

    currentState = houseMode;
    is_chasing = false;
}

Ghost::~Ghost(){
    delete houseMode;
    delete chaseMode;
    delete scatterMode;
    delete eatenMode;
    delete frightenedMode;
}

void Ghost::render(sf::RenderWindow &window){
    shape.setPosition(position);
    shape.setRadius(ghost_radius);
    shape.setFillColor(color);

    window.draw(shape);
}

void Ghost::setState(GhostState *newState){
    currentState = newState;
}

HouseMode* Ghost::getHouseMode(){
    return houseMode;
}

ChaseMode* Ghost::getChaseMode(){
    return chaseMode;
}

ScatterMode* Ghost::getScatterMode(){
    return scatterMode;
}

EatenMode* Ghost::getEatenMode(){
    return eatenMode;
}

FrightenedMode* Ghost::getFrightenedMode(){
    return frightenedMode;
}



Blinky::Blinky(float x, float y, float radius): Ghost(x, y, radius){
    color = sf::Color::Red;
    shape.setFillColor(color);
}
void Blinky::updatePosition(float elapsedTime){
    position += sf::Vector2f(0.1f, 0.3f);
}


Clyde::Clyde(float x, float y, float radius): Ghost(x, y, radius){
    color = sf::Color(40, 87, 158);
    shape.setFillColor(color);
}
void Clyde::updatePosition(float elapsedTime){
    position += sf::Vector2f(0.1f, 0.2f);
}


Inky::Inky(float x, float y, float radius): Ghost(x, y, radius){
    color = sf::Color::Blue;
    shape.setFillColor(color);
}
void Inky::updatePosition(float elapsedTime){
    position += sf::Vector2f(0.2f, 0.2f);
}


Pinky::Pinky(float x, float y, float radius): Ghost(x, y, radius){
    color = sf::Color::Magenta;
    shape.setFillColor(color);
}
void Pinky::updatePosition(float elapsedTime){
    position += sf::Vector2f(0.3f, 0.3f);
}



//GHOST STATE
GhostState::GhostState(Ghost* pGhost) {
    ghost = pGhost;
}

//HOUSE MODE
HouseMode::HouseMode(Ghost* pGhost): GhostState(pGhost){}
void HouseMode::superPacGumEaten(){}
void HouseMode::timerModeOver(){}
void HouseMode::timerFrightenedMode(){}
void HouseMode::eaten(){}
void HouseMode::outsideHouse(){}
void HouseMode::insideHouse(){}
void HouseMode::computeNextDir(){}
sf::Vector2f HouseMode::getTargetPosition(){
    return {0.0f, 0.0f};
};


//CHASE MODE
ChaseMode::ChaseMode(Ghost* pGhost): GhostState(pGhost){}
void ChaseMode::superPacGumEaten(){}
void ChaseMode::timerModeOver(){}
void ChaseMode::timerFrightenedMode(){}
void ChaseMode::eaten(){}
void ChaseMode::outsideHouse(){}
void ChaseMode::insideHouse(){}
void ChaseMode::computeNextDir(){}
sf::Vector2f ChaseMode::getTargetPosition(){
    return {0.0f, 0.0f};
};


//SCATTER MODE
ScatterMode::ScatterMode(Ghost* pGhost): GhostState(pGhost){}
void ScatterMode::superPacGumEaten(){}
void ScatterMode::timerModeOver(){}
void ScatterMode::timerFrightenedMode(){}
void ScatterMode::eaten(){}
void ScatterMode::outsideHouse(){}
void ScatterMode::insideHouse(){}
void ScatterMode::computeNextDir(){}
sf::Vector2f ScatterMode::getTargetPosition(){
    return {0.0f, 0.0f};
};


//EATEN MODE
EatenMode::EatenMode(Ghost* pGhost): GhostState(pGhost){}
void EatenMode::superPacGumEaten(){}
void EatenMode::timerModeOver(){}
void EatenMode::timerFrightenedMode(){}
void EatenMode::eaten(){}
void EatenMode::outsideHouse(){}
void EatenMode::insideHouse(){}
void EatenMode::computeNextDir(){}
sf::Vector2f EatenMode::getTargetPosition(){
    return {0.0f, 0.0f};
}


//FRIGHTENED MODE
FrightenedMode::FrightenedMode(Ghost* pGhost): GhostState(pGhost){};
void FrightenedMode::superPacGumEaten(){}
void FrightenedMode::timerModeOver(){}
void FrightenedMode::timerFrightenedMode(){}
void FrightenedMode::eaten(){}
void FrightenedMode::outsideHouse(){}
void FrightenedMode::insideHouse(){}
void FrightenedMode::computeNextDir(){}
sf::Vector2f FrightenedMode::getTargetPosition(){
    return {0.0f, 0.0f};
}
