#include "mainMenu.h"

void mainMenu::render(sf::RenderWindow& window, textures& gameTextures)
{
    SDL_RenderFillRect(window, nullptr);
    backgroundTexture = gameTextures.getTexture(textures::texturesIndices::backgroundMenu);
    SDL_FRect backgroundRect;
    backgroundRect.x = 960 - ((backgroundTexture->w * 540) / backgroundTexture->h);
    backgroundRect.y = 0;
    backgroundRect.w = (backgroundTexture->w * 540) / backgroundTexture->h;
    backgroundRect.h = 540;
    SDL_RenderTexture(window, backgroundTexture, nullptr, &backgroundRect);

    for (int i = 0; i < btnTable.size(); ++i)
    {
        btnTable[i].draw(window);
    }

    renderTexture(window, gameTextures, textures::textsIndices::PLAY, 10, 100, 100, 60);

    renderTexture(window, gameTextures, textures::textsIndices::SETTINGS, 10, 200, 220, 60);
}