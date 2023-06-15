#pragma once
#include "Entity.h"
#include<iostream>

class Cell: public StaticEntity
{
public:
		
	Cell(float x, float y, float s) {
		position = {x, y};
		size = s;
	}
	void render(sf::RenderWindow& window) final{
		shape.setFillColor(sf::Color(52, 93, 199));
		shape.setSize(sf::Vector2f(size, size));
		shape.setPosition(position);
		window.draw(shape);
	}
};

