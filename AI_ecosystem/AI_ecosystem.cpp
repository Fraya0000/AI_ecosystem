#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "clients.h"

int main() 
{

    sf::RenderWindow window(sf::VideoMode({ 1440, 1080 }), "marchand_map");
    window.setFramerateLimit(60);

    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("assets/marchand_map.png")) 
    {
        return -1;
    }
    sf::Sprite mapSprite(mapTexture);

    std::vector<std::string> evoliImages = 
    {
        "assets/evoli_look_right.png",
        "assets/evoli_look_right_move_1.png",
        "assets/evoli_look_right_move_2.png",
        "assets/evoli_look_right_move_3.png",

        "assets/evoli_look_left.png",
        "assets/evoli_look_left_move_1.png",
        "assets/evoli_look_left_move_2.png",
        "assets/evoli_look_left_move_3.png",

        "assets/evoli_look_up.png",
        "assets/evoli_look_up_move_1.png",
        "assets/evoli_look_up_move_2.png",
        "assets/evoli_look_up_move_3.png",

        "assets/evoli_look_down.png",
        "assets/evoli_look_down_move_1.png",
        "assets/evoli_look_down_move_2.png",
        "assets/evoli_look_down_move_3.png"
    };

    std::vector<std::string> voltaliImages = 
    {
        "assets/voltatli_look_right.png",
        "assets/voltatli_look_right_move_1.png",
        "assets/voltatli_look_right_move_2.png",
        "assets/voltatli_look_right_move_3.png",

        "assets/voltatli_look_left.png",
        "assets/voltatli_look_left_move_1.png",
        "assets/voltatli_look_left_move_2.png",
        "assets/voltatli_look_left_move_3.png",

        "assets/voltatli_look_up.png",
        "assets/voltatli_look_up_move_1.png",
        "assets/voltatli_look_up_move_2.png",
        "assets/voltatli_look_up_move_3.png",

        "assets/voltatli_look_down.png",
        "assets/voltatli_look_down_move_1.png",
        "assets/voltatli_look_down_move_2.png",
        "assets/voltatli_look_down_move_3.png"
    };

    clients evoli(evoliImages, { 100.f, 550.f });
    clients voltali(voltaliImages, { 100.f, 650.f });

    std::vector<sf::Vector2f> pathEvoli = 
    {
        {100.f, 550.f},
        {350.f, 400.f},
        {900.f, 100.f},
        {1340.f, 540.f}
    };

    std::vector<sf::Vector2f> pathVoltali = 
    {
        {100.f, 650.f},
        {400.f, 500.f},
        {850.f, 200.f},
        {1340.f, 640.f}
    };

    evoli.setMovementPath(pathEvoli);
    voltali.setMovementPath(pathVoltali);

    sf::Clock clock;

    while (window.isOpen()) 
    {
        float dt = clock.restart().asSeconds();

        while (const auto event = window.pollEvent()) 
        {
            if (event.has_value() && event->getIf<sf::Event::Closed>()) 
            {
                window.close();
            }
        }

        evoli.update(dt);
        voltali.update(dt);

        window.clear();
        window.draw(mapSprite);
        evoli.draw(window);
        voltali.draw(window);
        window.display();
    }
    return 0;
}