#include "../headers/Cell.hpp"
#include "../headers/Variable.hpp"

Cell::Cell(sf::RenderWindow &window, sf::Vector2i &position, sf::Texture texture) : window(window), position(position), texture(texture) {

    empty = false;

}

Cell::Cell(sf::RenderWindow &window, sf::Vector2i &position) : window(window), position(position) {

    texture.loadFromFile("../textures/empty.png");
    empty = true;

}

sf::Sprite Cell::getSprite() {

    sf::Sprite sprite;
    sf::IntRect rect(0, 0, ((BLOCKSIZE + (5 - (BLOCKSIZE % 5))) / 5), ((BLOCKSIZE + (5 - (BLOCKSIZE % 5))) / 5));
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setPosition(position.x * ((BLOCKSIZE + (5 - (BLOCKSIZE % 5))) / 5), position.y * ((BLOCKSIZE + (5 - (BLOCKSIZE % 5))) / 5) + MARGE);
    return sprite;

}

void Cell::draw() {

    window.draw(getSprite());

}

bool Cell::isEmpty() {

    return empty;

}

