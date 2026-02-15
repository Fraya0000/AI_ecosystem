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

    // Charger la texture de la map correctement
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

    clients evoli(evoliImages, { 0.f, 600.f });
    clients voltali(voltaliImages, { 0.f, 650.f });

    std::vector<sf::Vector2f> pathEvoli = 
    {
        {385.f, 570.f},
        {385.f, 330.f},
        {385.f, 570.f},
        {50.f, 570.f},
        {50.f, 330.f},
        {50.f, 570.f},
        {1600.f, 570.f}
    };

    std::vector<sf::Vector2f> pathVoltali = 
    {
        {940.f, 650.f},
        {940.f, 300.f},
        {948.f, 300.f},
        {930.f, 300.f},
        {940.f, 650.f},
        {1600.f, 650.f}
    };

    evoli.setMovementPath(pathEvoli);
    voltali.setMovementPath(pathVoltali);

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

        evoli.sprite->setScale({ 2.2f, 2.2f });
        voltali.sprite->setScale({ 2.0f, 2.0f });

        evoli.update(deltaTime);
        voltali.update(deltaTime);

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

        evoli.draw(window);
        voltali.draw(window);
        window.draw(timerText);
        window.display();
    }

    delete bt;
    bt = nullptr;
    delete blackboard;
    blackboard = nullptr;

    return 0;
}