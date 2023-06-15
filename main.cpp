#include <iostream>
#include<SFML/Graphics.hpp>
#include "Pacman.h"
#include "Ghost.h"

void renderWindow(){
    sf::Clock clock;

    float radius = 50;
    sf::Vector2i window_s = {1000, 800};

    sf::RenderWindow window(sf::VideoMode(window_s.x, window_s.y), "SFML works!", sf::Style::Default);
    window.setFramerateLimit(100);
    Pinky pinky(0, 0, 25);
    Clyde clyde(40, 40, 25);
    Blinky blinky(120, 120, 25);
    Inky inky(200, 200, 30);

    sf::RectangleShape rectangleShape(sf::Vector2f(40, 40));
    rectangleShape.setFillColor(sf::Color(207, 74, 45));
    rectangleShape.setPosition(500, 500);

    Pacman pacman(15, 15);

    while(window.isOpen()) {
        clock.restart();
        clock.restart();
        sf::Event event{};
        sf::Vector2f move;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        inky.updatePosition(clock.getElapsedTime().asSeconds());
        clyde.updatePosition(clock.getElapsedTime().asSeconds());
        blinky.updatePosition(clock.getElapsedTime().asSeconds());
        pinky.updatePosition(clock.getElapsedTime().asSeconds());
        pacman.updatePosition(clock.getElapsedTime().asSeconds());

        window.clear();

        window.draw(rectangleShape);
        inky.render(window);
        clyde.render(window);
        blinky.render(window);
        pinky.render(window);
        pacman.render(window);
        window.display();
    }
}

int main() {
    renderWindow();
    return 0;
}
