#include "Game.h"
#include <iostream>
#include "AbstractGhostFactory.h"


Game::Game() {
    auto pinkyFactory = new PinkyFactory();
    auto inkyFactory = new InkyFactory();
    auto clydeFactory = new ClydeFactory();
    auto blinkyFactor = new BlinkyFactory();
    // create factory AbstractGhostFactory* ghostFactory;
    // read the text file with maze and positions of entities
    //if x - create wall and add into walls
    //if P - create pacman, add into objects
    //if b/p/i/c - create factories
    //create ghosts and add them into objects and ghosts
    //if . - create PacGum into objects
    //if o - create SuperPacGum
    //if - - create GhostHouse 
}

std::vector<Entity*> Game::getEntities() {
    return objects;
}

std::vector<Cell*> Game::getCells() {
    return cells;
}

Pacman Game::getPacman() {
    return *pacman;
}

void Game::updateGame(float elapsedTime) {
    for (auto ghost: ghosts){
        ghost->updatePosition(elapsedTime);
    }
    pacman->updatePosition(elapsedTime);
}
void Game::render(sf::RenderWindow& window) const {
    for (auto object: objects){
        object->render(window);
    }
    for (auto ghost: ghosts){
        ghost->render(window);
    }
    for (auto cell: cells){
        cell->render(window);
    }
    pacman->render(window);
}

Game::~Game() {
    for (auto object: objects){
        delete object;
    }
    for (auto ghost: ghosts){
        delete ghost;
    }
    for (auto cell: cells){
        delete cell;
    }
    delete pacman;
}


	

