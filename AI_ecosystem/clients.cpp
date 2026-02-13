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
        sprite.setTexture(textures[0]);
        sprite.setPosition(startPosition);
    }
}

void clients::determineDirection(const sf::Vector2f& dir) 
{
    float absX = std::abs(dir.x);
    float absY = std::abs(dir.y);

    if (absX > absY) 
    {
        currentDirection = (dir.x > 0) ? RIGHT : LEFT;
    }
    else 
    {
        currentDirection = (dir.y > 0) ? DOWN : UP;
    }
}

void clients::updateAnimation(float dt) 
{
    animationTime += dt;
    if (animationTime >= frameHoldTime) 
    {
        animationTime = 0.0f;
        currentFrame = (currentFrame + 1) % 4;
    }

    int baseIndex = static_cast<int>(currentDirection) * 4;
    if (baseIndex + currentFrame < static_cast<int>(textures.size())) 
    {
        sprite.setTexture(textures[baseIndex + currentFrame]);
    }
}

void clients::setMovementPath(const std::vector<sf::Vector2f>& newPath) 
{
    path = newPath;
    currentTargetIndex = 0;
}

void clients::update(float dt) 
{
    if (!visible || path.empty() || currentTargetIndex >= path.size()) return;

    sf::Vector2f target = path[currentTargetIndex];
    sf::Vector2f pos = sprite.getPosition();
    sf::Vector2f dir = target - pos;
    float len2 = dir.x * dir.x + dir.y * dir.y;

    if (len2 < 1.0f) 
    {
        currentTargetIndex++;
        return;
    }

    float len = std::sqrt(len2);
    dir /= len;

    determineDirection(dir);
    updateAnimation(dt);

    float maxStep = speed * dt;
    if (len <= maxStep) 
    {
        sprite.setPosition(target);
        currentTargetIndex++;
    }
    else 
    {
        sprite.move(dir * maxStep);
    }
}

void clients::draw(sf::RenderWindow& window) const 
{
    if (visible) 
    {
        window.draw(sprite);
    }
}

bool clients::hasFinishedPath() const 
{
    return currentTargetIndex >= path.size();
}

sf::Vector2f clients::getPosition() const 
{
    return sprite.getPosition();
}