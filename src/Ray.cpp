#include "../headers/Ray.hpp"
#include "../headers/Variable.hpp"

Ray::Ray(sf::RenderWindow &window, Map &map, float rayLength) : window(window), map(map), rayLength(rayLength) {

    sf::VertexArray vertexArray(sf::Lines, 2);
    ray = vertexArray;
    setColor(sf::Color::Green);

}

void Ray::draw() {

    sf::VertexArray vertexArray = ray;
    vertexArray[0].position = ray[0].position / 5.0f;
    vertexArray[0].position.y += MARGE;
    vertexArray[1].position = ray[1].position / 5.0f;
    vertexArray[1].position.y += MARGE;

    window.draw(vertexArray);

}

void Ray::setStartPosition(sf::Vector2f pos) {

    ray[0].position = pos;

}

void Ray::setEndPosition(sf::Vector2f pos) {

    ray[1].position = pos;

}

void Ray::setColor(sf::Color color) {

    ray[0].color = color;
    ray[1].color = color;

}

bool Ray::isCollide(sf::Vector2f direction) {

    for (unsigned int i(0); i < rayLength; ++i) {

        int x = getStartPosition().x + i * direction.x;
        int y = getStartPosition().y + i * direction.y;

        if (map.isCollide(x / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))), y / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))))) {

            intersection.x = x;
            intersection.y = y;
            return true;

        }

    }

    return false;

}

float Ray::getLength() {

    return rayLength;

}

sf::Vector2f Ray::getIntersection() {

    return intersection;

}

sf::Vector2f Ray::getStartPosition() {

    return ray[0].position;

}

sf::Vector2f Ray::getEndPosition() {

    return ray[1].position;

}