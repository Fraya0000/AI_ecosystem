#pragma once
#include "clients.h"
#include <SFML/Graphics.hpp>
#include <vector>

class clientManager 
{
private:
    clients* evoli;
    clients* voltali;
    std::vector<std::string> evoliImages;
    std::vector<std::string> voltaliImages;

public:
    clientManager();
    ~clientManager();

    void setupPaths();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    clients* getEvoli() { return evoli; }
    clients* getVoltali() { return voltali; }
};