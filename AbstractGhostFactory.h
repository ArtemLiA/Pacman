#pragma once
#include "Ghost.h"

class AbstractGhostFactory{
public:
    virtual Ghost* createGhost(float x, float y, float size) = 0;
};

class PinkyFactory: public AbstractGhostFactory{
public:
    Pinky* createGhost(float x, float y, float radius) override;
};

class InkyFactory: public AbstractGhostFactory{
public:
    Inky* createGhost(float x, float y, float radius) override;
};

class ClydeFactory: public AbstractGhostFactory{
public:
    Clyde* createGhost(float x, float y, float radius) override;
};

class BlinkyFactory: public AbstractGhostFactory{
public:
    Blinky* createGhost(float x, float y, float radius) override;
};

Pinky* PinkyFactory::createGhost(float x, float y, float radius){
    return new Pinky(x, y, radius);
}

Inky* InkyFactory::createGhost(float x, float y, float radius){
    return new Inky(x, y, radius);
}

Clyde* ClydeFactory::createGhost(float x, float y, float radius){
    return new Clyde(x, y, radius);
}

Blinky* BlinkyFactory::createGhost(float x, float y, float radius){
    return new Blinky(x, y, radius);
}
