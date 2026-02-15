#pragma once
#include <SFML/Graphics.hpp>
#include <string>

enum class merchantType 
{
    Baker,
    Butcher,
    Fisherman
};

struct merchant 
{
public:
    merchantType type;
    sf::Vector2f position;
    bool isOpen;
    std::string name;

    merchant(merchantType t, sf::Vector2f pos, const std::string& n) : type(t), position(pos), isOpen(false), name(n) 
    {
    }
};