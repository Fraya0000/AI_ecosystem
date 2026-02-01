#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>

#include "game.cpp"

namespace App
{
    constexpr const char* Name = "SDL Test";
    constexpr const char* Version = "1.0";
    constexpr const char* Id = "games.anakata.test-sfml";
}

int main()
{
    sf::RenderWindow window;

    std::cout << App::Name;
    std::cout << App::Version;
    std::cout << App::Id;

    sf::RenderWindow window(
        sf::VideoMode(windowWidth, windowHeight),
        "Nebulus like",
        sf::Style::Default
    );

    window.setVerticalSyncEnabled(true);

    sf::View view(sf::FloatRect(0.f, 0.f, windowWidth, windowHeight));
    window.setView(view);

    game currentGame(window, windowWidth, windowHeight);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (currentGame.getMenuState())
            {
                currentGame.getMenuHandler().handleEvent(event);
            }
            else
            {
                currentGame.getInputHandler().handler(event);
            }
        }

        currentGame.update();

        window.clear();
        currentGame.render(window);
        window.display();
    }
}
