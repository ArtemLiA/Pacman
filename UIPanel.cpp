#include "UIPanel.h"

UIPanel::UIPanel(float x, float y, float s) {
    score = 0;

    font.loadFromFile("C:/Users/lyaho/CS_Projects/C++/Games/Pacman/Times-New-Roman.ttf");

    background.setFillColor(sf::Color::Black);
    background.setSize(sf::Vector2f(s, s));
    background.setPosition(x, y);

    text.setPosition({x + 10, y + 5});
    text.setFillColor(sf::Color(150, 255, 97));
    text.setString(std::to_string(score));
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setCharacterSize(20);
}

void UIPanel::increaseScore(size_t points){
    score += points;
}

void UIPanel::resetScore(){
    score = 0;
}

void UIPanel::render(sf::RenderWindow &window) const {
    window.draw(background);
    window.draw(text);
}

size_t UIPanel::getScore() const {
    return score;
}