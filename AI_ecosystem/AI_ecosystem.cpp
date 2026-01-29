#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 700, 600 }), "SFML window");

    // Load a sprite to display
    const sf::Texture texture("toji.jpg");
    sf::Sprite sprite(texture);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const auto event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Update the window
        window.display();
    }
}
