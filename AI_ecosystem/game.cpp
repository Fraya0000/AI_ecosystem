#include "game.h"

game::game(sf::RenderWindow& _window, int _windowWidth, int _windowHeight)
	:windowWidth(_windowWidth), windowHeight(_windowHeight)
{
}

game::~game()
{
}

//
// inputHandler& game::getInputHandler() { return gameInputHandler; }

void game::update()
{
    if (inMenu)
    {
        gameMenuHandler.update();
    }
    else
    {
        float lastTime = now;
        sf::Clock clock;
        float now = clock.getElapsedTime().asSeconds();
        deltaTime = now - lastTime;
        relativeOrigin = gamePlayer.getRelativeX() - gamePlayer.getAbsoluteX();

        gameInputHandler.update(gamePlayer, deltaTime);
        gamePlayer.update(deltaTime, relativeOrigin);
        level.update(deltaTime, relativeOrigin);
    }
}

void game::render()
{
    if (inMenu)
    {
        gameMenuHandler.render(renderer, gameTextures);
    }
    else
    {
        level.render();
        gamePlayer.render();
    }
}

bool game::getMenuState()
{
	return inMenu;
}
