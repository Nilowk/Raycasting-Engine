#include <SFML/Graphics.hpp>
#include "headers/Variable.hpp"
#include "headers/Map.hpp"
#include "headers/Player.hpp"
#include "headers/World.hpp"

using namespace sf;

int main() {

    RenderWindow window(VideoMode(WIDTHSCREEN, HEIGHTSCREEN), "FPS", Style::Fullscreen);
    window.setFramerateLimit(FPS);
    window.setMouseCursorVisible(false);

    Map map(window);
    Player player(window, map);
    World world(window, player);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {

                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyReleased:
                    if (event.key.code == Keyboard::Escape) window.close();
                    break;

            }

        }

        player.update();
        window.clear();

        world.draw();
        map.draw();
        player.draw();
        window.display();

    }

    return 0;

}
