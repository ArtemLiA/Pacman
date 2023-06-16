#pragma once

#include "Field.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Entity.h"
#include "Cell.h"
#include "Ghost.h"
#include "AbstractGhostFactory.h"


class Game{
protected:
    Field game_field;

	std::vector<Entity*> objects;
	std::vector<Ghost*> ghosts;
	std::vector<Cell*> cells;
	Pacman *pacman;

public:
	Game();
	std::vector<Entity*> getEntities();
	std::vector<Cell*> getCells();
	Pacman getPacman();
	void updateGame(float elapsedTime); // изменения координат объектов
	void render(sf::RenderWindow& window) const; // отрисовка
	virtual ~Game();
};


