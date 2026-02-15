#include "clientManager.h"

clientManager::clientManager() 
{
    // Images Evoli
    evoliImages = 
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

    // Images Voltali
    voltaliImages = 
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

    // Create clients
    evoli = new clients(evoliImages, sf::Vector2f(0.f, 600.f));
    voltali = new clients(voltaliImages, sf::Vector2f(0.f, 650.f));
}

clientManager::~clientManager() 
{
    delete evoli;
    evoli = nullptr;
    delete voltali;
	voltali = nullptr;
}

void clientManager::setupPaths() 
{
    std::vector<sf::Vector2f> pathEvoli = 
    {
        {385.f, 570.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f},
        {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f},
        {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f},
        {386.f, 330.f}, {385.f, 330.f}, {386.f, 330.f}, {385.f, 330.f}, {385.f, 570.f}, {50.f, 570.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, 
        {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f},{51.f, 330.f}, {50.f, 330.f}, 
        {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {51.f, 330.f}, {50.f, 330.f}, {50.f, 570.f}, {1600.f, 570.f}
    };

    std::vector<sf::Vector2f> pathVoltali = 
    {
        {940.f, 650.f}, {940.f, 300.f}, {948.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {930.f, 300.f},
        {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {930.f, 300.f}, {931.f, 300.f},
        {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {931.f, 300.f}, {930.f, 300.f}, {940.f, 650.f}, {1600.f, 650.f}
    };

    evoli->setMovementPath(pathEvoli);
    voltali->setMovementPath(pathVoltali);
}

void clientManager::update(float deltaTime) 
{
    evoli->update(deltaTime);
    voltali->update(deltaTime);
}

void clientManager::draw(sf::RenderWindow& window) 
{
    if (evoli->sprite) 
    {
        evoli->sprite->setScale({ 2.2f, 2.2f });
    }
    if (voltali->sprite) 
    {
        voltali->sprite->setScale({ 2.0f, 2.0f });
    }

    evoli->draw(window);
    voltali->draw(window);
}