#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Entity.h"
#include "Ghost.h"
#include "Cell.h"

//Поле будет состоять из 23x14 клеток
//Размер каждой клетки - 35 на 35 пикселей

struct Field{
    static const size_t block_size = 35;
    static const size_t width = 23;
    static const size_t height = 14;

    std::string maze[height] = {
            "##### ############ ####",
            "#                     #",
            "#  # ###### ###### #  #",
            "   # #           # #   ",
            "#  # #           # #  #",
            "#  # # ######### # #  #",
            "#  #   #       #   #  #",
            "#  #   #  # #  #   #  #",
            "#  # # #### #### # #  #",
            "#  # #           # #  #",
            "   # #           # #   ",
            "#  # ###### ###### #  #",
            "#                     #",
            "#### ############# ####"
    };
};

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


