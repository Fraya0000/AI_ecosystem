#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "clients.h"
#include "gameTime.h"
#include "merchant.h"
#include "merchantBlackBoard.h"
#include "merchantTaskNodes.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode({ 1440, 1080 }), "marchand_map");
    window.setFramerateLimit(60);

    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("assets/marchand_map.png"))
    {
        return -1;
    }

    sf::RectangleShape rectangle;
    rectangle.setSize({ 1440, 1080 });
    rectangle.setTexture(&mapTexture);

    gameTime timer;
    sf::Clock clock;
    sf::Font font("assets/arial.ttf");
    
    sf::Text timerText(font);
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition({ 20, 35 });

    merchantBlackBoard* blackboard = new merchantBlackBoard();
    merchantBehaviorTree* bt = new merchantBehaviorTree(blackboard);
    bt->buildTree();
    bt->startExecute();

    sf::Text shopStatus(font);
    shopStatus.setCharacterSize(18);
    shopStatus.setFillColor(sf::Color::Yellow);

    gameState previousState = gameState::Morning;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        timer.update(deltaTime);
        gameState currentState = timer.getState();
        blackboard->setTimeOfDay(currentState);
        
        if (currentState != previousState) {
            bt->startExecute();
            previousState = currentState;
        }

        for (auto client : blackboard->getClients()) {
            client->update(deltaTime);
        }
        blackboard->getClientManager()->update(deltaTime);
        blackboard->removeFinishedClients();

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

        window.clear();
        window.draw(rectangle);

        for (size_t i = 0; i < blackboard->getMerchants().size(); i++) {
            auto merchant = blackboard->getMerchants()[i];
            shopStatus.setPosition(sf::Vector2f(merchant->position.x - 30, merchant->position.y - 50));

            if (merchant->isOpen) {
                shopStatus.setString(merchant->name + "\nOPEN");
                shopStatus.setFillColor(sf::Color::Green);
            }
            else {
                shopStatus.setString(merchant->name + "\nCLOSED");
                shopStatus.setFillColor(sf::Color::Red);
            }

            window.draw(shopStatus);
        }

        blackboard->getClientManager()->draw(window);

        for (auto client : blackboard->getSpawnedClients()) 
        {
            if (client->sprite) {
                client->sprite->setScale({ 2.0f, 2.0f });
            }
            client->update(deltaTime);
            client->draw(window);
        }

        window.draw(timerText);
        window.display();
    }

    delete bt;
    bt = nullptr;
    delete blackboard;
    blackboard = nullptr;

    return 0;
}