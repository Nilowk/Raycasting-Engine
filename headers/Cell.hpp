#ifndef RAYCASTING_ENGINE_CELL_HPP
#define RAYCASTING_ENGINE_CELL_HPP

#include <SFML/Graphics.hpp>

class Cell {

private:
    sf::RenderWindow& window;
    sf::Texture texture;
    sf::Vector2i position;
    bool empty;

public:
    Cell(sf::RenderWindow &window, sf::Vector2i &position, sf::Texture texture);
    Cell(sf::RenderWindow &window, sf::Vector2i &position);
    sf::Sprite getSprite();
    void draw();
    bool isEmpty();

};

#endif //RAYCASTING_ENGINE_CELL_HPP
