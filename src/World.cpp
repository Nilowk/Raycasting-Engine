#include "../headers/World.hpp"
#include "../headers/Variable.hpp"
#include <cmath>

World::World(sf::RenderWindow &window, Player &player) : window(window), player(player) {}

void World::draw() {

    std::vector<Ray> rays = player.getRays();

    for (int i = 0; i < rays.size(); ++i) {

        Ray ray = rays[i];
        float distance = std::sqrt(std::pow(ray.getStartPosition().x - ray.getEndPosition().x, 2) + std::pow(ray.getStartPosition().y - ray.getEndPosition().y, 2));
        float vecSize = HEIGHTSCREEN / (distance / BLOCKSIZE);

        sf::VertexArray wall(sf::Lines, 2);
        wall[0].color = BLOCKCOLOR;
        wall[0].position = sf::Vector2f(WIDTHSCREEN - i, (HEIGHTSCREEN - vecSize) / 2 + MARGE);
        wall[1].color = BLOCKCOLOR;
        wall[1].position = sf::Vector2f(WIDTHSCREEN - i, HEIGHTSCREEN - ((HEIGHTSCREEN - vecSize) / 2) + MARGE);

        sf::VertexArray floor(sf::Lines, 2);
        floor[0].color = FLOORCOLOR;
        floor[0].position = sf::Vector2f(WIDTHSCREEN - i, HEIGHTSCREEN - ((HEIGHTSCREEN - vecSize) / 2) + MARGE);
        floor[1].color = FLOORCOLOR;
        floor[1].position = sf::Vector2f(WIDTHSCREEN - i, HEIGHTSCREEN + MARGE);

        sf::VertexArray roof(sf::Lines, 2);
        roof[0].color = ROOFCOLOR;
        roof[0].position = sf::Vector2f(WIDTHSCREEN - i, MARGE);
        roof[1].color = ROOFCOLOR;
        roof[1].position = sf::Vector2f(WIDTHSCREEN - i, (HEIGHTSCREEN - vecSize) / 2 + MARGE);

        window.draw(wall);
        window.draw(floor);
        window.draw(roof);

    }

}