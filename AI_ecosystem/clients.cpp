#include "clients.h"

clients::clients(const std::vector<std::string>& assetNames, sf::Vector2f startPosition)
    : visible(true), speed(120.0f), currentTargetIndex(0),
    currentFrame(0), animationTime(0.f), frameHoldTime(0.15f),
    currentDirection(RIGHT) 
{

    
    textures.resize(assetNames.size());
    for (size_t i = 0; i < assetNames.size(); ++i) 
    {
        if (!textures[i].loadFromFile(assetNames[i])) 
        {
            visible = false;
            return;
        }
    }
   

    if (!textures.empty()) 
    {

        sprite = new sf::Sprite(textures[currentFrame]);
        sprite->setPosition(startPosition);
    }
}

void clients::determineDirection(const sf::Vector2f& dir) 
{
    float absX = std::abs(dir.x);
    float absY = std::abs(dir.y);

    if (absX > absY) 
    {
        currentDirection = (dir.x > 0) ? RIGHT : LEFT;
        currentFrame = 0;
        animationTime = 1.0f;
    }
    else 
    {
        currentDirection = (dir.y > 0) ? DOWN : UP;
        currentFrame = 0;
        animationTime = 1.0f;
    }
}

void clients::updateAnimation(float dt) 
{
    animationTime += dt;
    if (animationTime > frameHoldTime)
    {
        animationTime = 0.0f;
        int StartingSpriteIndex = static_cast<int>(currentDirection);
        currentFrame++;
        if (currentFrame >= 4)
        {
            currentFrame = 0;
        }

        sprite->setTexture(textures[StartingSpriteIndex + currentFrame]);
    }
}

void clients::setMovementPath(const std::vector<sf::Vector2f>& newPath) 
{
    path = newPath;
    currentTargetIndex = 0;
}

void clients::update(float dt)
{
}

void clients::draw(sf::RenderWindow& window) const 
{

    window.draw(*sprite);

   /* if (visible) 
    {
    }*/
}

bool clients::hasFinishedPath() const 
{
    return currentTargetIndex >= path.size();
}

sf::Vector2f clients::getPosition() const 
{
    return sprite->getPosition();
}