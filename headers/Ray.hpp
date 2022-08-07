#ifndef RAYCASTING_ENGINE_RAY_HPP
#define RAYCASTING_ENGINE_RAY_HPP

#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Ray {

private:
    sf::RenderWindow& window;
    Map& map;
    sf::VertexArray ray;
    float rayLength;
    sf::Vector2f intersection;

public:
    Ray(sf::RenderWindow &window, Map &map, float rayLength);
    void draw();
    void setStartPosition(sf::Vector2f pos);
    void setEndPosition(sf::Vector2f pos);
    void setColor(sf::Color color);
    bool isCollide(sf::Vector2f direction);
    float getLength();
    sf::Vector2f getIntersection();
    sf::Vector2f getStartPosition();
    sf::Vector2f getEndPosition();

};

#endif //RAYCASTING_ENGINE_RAY_HPP
