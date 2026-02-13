    #include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "clients.h"
#include "gameTime.h"

int main() 
{

    sf::RenderWindow window(sf::VideoMode({ 1440, 1080 }), "marchand_map");
    sf::RectangleShape rectangle;
    window.setFramerateLimit(60);

    sf::Texture* map = new sf::Texture("assets/marchand_map.png");
    rectangle.setSize({ 1440, 1080 });
    rectangle.setTexture(map);

    sf::Texture mapTexture;
    gameTime timer;
    sf::Clock clock;
    sf::Font font("assets/arial.ttf");
    sf::Text timerText(font);
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition({ 20, 20 });

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

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        timer.update(deltaTime);

        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << "Time: " << timer.getTime() << "s | ";
        switch (timer.getState()) {
        case gameState::Morning:
            ss << "Morning";
            break;
        case gameState::Day:
            ss << "Day";
            break;
        case gameState::Evening:
            ss << "Evening";
            break;
        }
        timerText.setString(ss.str());

        while (const auto event = window.pollEvent())
        {
            if (event.has_value() && event->getIf<sf::Event::Closed>())
            {
                window.close();
            }
        }

        evoli.update(deltaTime);
        voltali.update(deltaTime);

        window.clear();
        window.draw(rectangle);
        evoli.draw(window);
        voltali.draw(window);
        window.setVerticalSyncEnabled(true);
        window.draw(rectangle);
        window.draw(timerText);
        window.display();
    }
    delete map;
    return 0;
}