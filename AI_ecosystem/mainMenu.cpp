#include "mainMenu.h"

mainMenu::mainMenu()
{
	btnPlay = addBtn(0, 100, "PLAY");
	btnSettings = addBtn(0, 200, "SETTINGS");
}

mainMenu::~mainMenu()
{
}

mainMenu::mainmenuState mainMenu::getCurrentState() const
{
	return currentMainMenuState;
}

void mainMenu::onBtnPressed(int id)
{
	if (id == btnSettings)
	{
		currentMainMenuState = mainmenuState::Settings;
	}
	else if (id == btnPlay)
	{
		currentMainMenuState = mainmenuState::Play;
	}
}

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


