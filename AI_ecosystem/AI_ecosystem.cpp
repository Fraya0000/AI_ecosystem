#include <SFML/Graphics.hpp>
#include "map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "marchand_map");

    map gameMap(25, 20, 32, "tileSet.png");
    gameMap.createEmptyMap();

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event.has_value() && event->getIf<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        gameMap.draw(window);
        window.display();
    }

    return 0;
}