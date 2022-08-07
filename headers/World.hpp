#ifndef RAYCASTING_ENGINE_WORLD_HPP
#define RAYCASTING_ENGINE_WORLD_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"

class World {

private:
    sf::RenderWindow& window;
    Player& player;

public:
    World(sf::RenderWindow &window, Player &player);
    void draw();

};

#endif //RAYCASTING_ENGINE_WORLD_HPP
