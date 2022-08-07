#include <cmath>
#include "../headers/Player.hpp"
#include "../headers/Variable.hpp"

Player::Player(sf::RenderWindow &window, Map &map) : window(window), map(map) {

    radius = RADIUS / 5;
    player.setRadius(radius);
    player.setFillColor(PLAYERCOLOR);
    player.setOrigin(sf::Vector2(radius, radius));

    angle = DEFAULTANGLE;
    speed = SPEED;
    mouseSensitivity = MOUSESENSITIVITY;

    position = DEFAULTPOSITION;

    sf::Vector2i center(WIDTHSCREEN / 2, HEIGHTSCREEN / 2);
    mousePosition = center;

    fov = FOV;

    for (unsigned int i(0); i < WIDTHSCREEN; ++i) {

        Ray ray(window, map, RAYLENGTH);
        rays.push_back(ray);

    }

}

void Player::update() {

    sf::Time dt = clock.restart();
    move(dt);
    rotate(dt);
    sf::Mouse::setPosition(mousePosition);
    player.setPosition(position);
    player.setRotation(angle);
    rayCasting();

}

void Player::move(sf::Time dt) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {

        float x = position.x + dCos(angle) * speed * dt.asSeconds();
        float y = position.y + dSin(angle) * speed * dt.asSeconds();

        if (!map.isCollide(x / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))), y / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))))) {

            position.x = x;
            position.y = y;

        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

        float x = position.x - dCos(angle) * speed * dt.asSeconds();
        float y = position.y - dSin(angle) * speed * dt.asSeconds();

        if (!map.isCollide(x / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))), y / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))))) {

            position.x = x;
            position.y = y;

        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

        float x = position.x + dCos(angle + 90) * speed * dt.asSeconds();
        float y = position.y + dSin(angle + 90) * speed * dt.asSeconds();

        if (!map.isCollide(x / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))), y / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))))) {

            position.x = x;
            position.y = y;

        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

        float x = position.x - dCos(angle + 90) * speed * dt.asSeconds();
        float y = position.y - dSin(angle + 90) * speed * dt.asSeconds();

        if (!map.isCollide(x / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))), y / (BLOCKSIZE + (5 - (BLOCKSIZE % 5))))) {

            position.x = x;
            position.y = y;

        }

    }

}

void Player::rotate(sf::Time dt) {

    if (mousePosition.x > sf::Mouse::getPosition().x) {

        angle -= (mousePosition.x - sf::Mouse::getPosition().x) * mouseSensitivity * dt.asSeconds();

    }
    if (mousePosition.x < sf::Mouse::getPosition().x) {

        angle += (sf::Mouse::getPosition().x - mousePosition.x) * mouseSensitivity * dt.asSeconds();

    }

    if (angle > 360) angle = 0;
    if (angle < 0) angle = 360;

}

void Player::rayCasting() {

    for (unsigned int i(0); i < rays.size(); ++i) {

        Ray &ray = rays[i];

        ray.setStartPosition(position);

        float fAngle = (angle + (fov / 2) - i * (fov/WIDTHSCREEN));
        sf::Vector2f direction = {dCos(fAngle), dSin(fAngle)};

        if (ray.isCollide(direction)) ray.setEndPosition(ray.getIntersection());
        else {

            float x = position.x + ray.getLength() * dCos((angle + fov / 2) - i * (fov/WIDTHSCREEN));
            float y = position.y + ray.getLength() * dSin((angle + fov / 2) - i * (fov/WIDTHSCREEN));

            ray.setEndPosition({x, y});

        }

    }

}

void Player::draw() {

    float x = position.x / 5;
    float y = position.y / 5;
    y += MARGE;

    player.setPosition(x, y);
    window.draw(player);

    for (auto& ray : rays) {
        ray.draw();
    }

}

std::vector<Ray> Player::getRays() const {

    return rays;

}

float Player::toRadian(float degree) {

    return (PI / 180) * degree;

}

float Player::dCos(float degree) {

    return cos(toRadian(degree));

}

float Player::dSin(float degree) {

    return sin(toRadian(degree));

}