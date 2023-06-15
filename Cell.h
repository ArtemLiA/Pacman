#pragma once
#include "Entity.h"

enum struct CellCategory{
    WALL, ROAD
};

class Cell: public StaticEntity{
protected:
    CellCategory category;
public:
	Cell(float x, float y, float s, CellCategory _category);
	void render(sf::RenderWindow& window) override;
};

Cell::Cell(float x, float y, float s, CellCategory _category) {
    size = s;
    position = {x, y};
    category = _category;

    shape.setSize(sf::Vector2f(s, s));
    shape.setPosition(position);
}

void Cell::render(sf::RenderWindow &window){
    shape.setFillColor(sf::Color(52, 93, 199));
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(position);
    window.draw(shape);
}