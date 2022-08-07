#ifndef RAYCASTING_ENGINE_MAP_HPP
#define RAYCASTING_ENGINE_MAP_HPP

#include "Cell.hpp"

class Map {

private:
    sf::RenderWindow& window;
    std::vector<std::vector<Cell>> cells;

public:
    Map(sf::RenderWindow &window);
    void generateMap();
    void draw();
    bool isCollide(unsigned int x, unsigned int y);

};

#endif //RAYCASTING_ENGINE_MAP_HPP
