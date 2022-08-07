#ifndef RAYCASTING_ENGINE_VARIABLE_HPP
#define RAYCASTING_ENGINE_VARIABLE_HPP

const float PI = 3.141592f;
const unsigned int xCase = 30, yCase = 16;
const unsigned int BLOCKSIZE = 64;
const unsigned int WIDTHSCREEN = xCase * BLOCKSIZE, HEIGHTSCREEN = yCase * BLOCKSIZE;
const unsigned int MARGE = 28;
const unsigned int FPS = 144;
const unsigned int RADIUS = 10;
const float DEFAULTANGLE = 270.0f;
const float SPEED = 200.0f;
const float MOUSESENSITIVITY = 5.0f;
const float FOV = 60;
const float RAYLENGTH = 2000;
const std::vector<sf::Color> RAYCOLOR = {sf::Color::Green, sf::Color::Green};
const sf::Vector2f DEFAULTPOSITION(600, 800);
const sf::Color PLAYERCOLOR(sf::Color::Red);
const sf::Color BLOCKCOLOR(0, 125, 255);
const sf::Color ROOFCOLOR(0, 19, 106);
const sf::Color FLOORCOLOR(120, 120, 120);

#endif //RAYCASTING_ENGINE_VARIABLE_HPP
