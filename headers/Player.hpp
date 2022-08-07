#ifndef RAYCASTING_ENGINE_PLAYER_HPP
#define RAYCASTING_ENGINE_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "Ray.hpp"

class Player {

private:
    Map& map;
    sf::RenderWindow& window;
    sf::CircleShape player;
    sf::Vector2f position;
    sf::Clock clock;
    sf::Vector2i mousePosition;
    std::vector<Ray> rays;
    float angle, fov;
    float radius;
    float speed, mouseSensitivity;

public:
    Player(sf::RenderWindow &window, Map &map);
    void update();
    void move(sf::Time dt);
    void rotate(sf::Time dt);
    void rayCasting();
    void draw();
    std::vector<Ray> getRays() const;
    float toRadian(float degree);
    float dCos(float degree);
    inline float dSin(float degree);

};

#endif //RAYCASTING_ENGINE_PLAYER_HPP
