#include "gameTime.h"
#include <sstream>

gameTime::gameTime() : time(0.0f), state(gameState::Morning)
{
}

gameTime::~gameTime()
{
}

void gameTime::update(float deltaTime)
{
    time += deltaTime;
    if (time >= 20.0f) {
        time = 0.0f;
        switch (state) {
        case gameState::Morning:
            state = gameState::Day;
            break;
        case gameState::Day:
            state = gameState::Evening;
            break;
        case gameState::Evening:
            state = gameState::Morning;
            break;
        }
    }
}

