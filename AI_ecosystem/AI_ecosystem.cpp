#include <SFML/Graphics.hpp>
#include "map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "marchand_map");
    sf::RectangleShape rectangle;
    sf::Texture* map = new sf::Texture("marchand_map.png");
    rectangle.setSize({ 800, 600 });
    rectangle.setTexture(map);
    //map gameMap(800, 800, 400, "marchand_map.png");
    //gameMap.createEmptyMap();

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event.has_value() && event->getIf<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.setVerticalSyncEnabled(true);
        window.clear();
        window.draw(rectangle);
        //gameMap.draw(window);
        window.display();
    }

    return 0;
}