#include "settingsMenu.h"

settingsMenu::settingsState settingsMenu::getCurrentState() const
{
	return currentSettingsState;
}

settingsMenu::settingsMenu()
{
	btnBack = addBtn(0, 100, "RETURN TO MENU");
	btnMusic = addBtn(0, 200, "VOLUME");
	btnFullscreen = addBtn(0, 300, "FULLSCREEN");
	btnControls = addBtn(0, 400, "CONTROLS");
}

void settingsMenu::onBtnPressed(int id)
{
	if (id == btnMusic)
	{
		currentSettingsState = settingsState::Music;
	}
	else if (id == btnFullscreen)
	{
		currentSettingsState = settingsState::Fullscreen;
	}
	else if (id == btnBack)
	{
		currentSettingsState = settingsState::ReturnMenu;
	}
	else if (id == btnControls)
	{
		currentSettingsState = settingsState::Controls;
	}
}

void settingsMenu::applyFullscreen(sf::RenderWindow& window, bool& isFullscreen)
{
	isFullscreen = !isFullscreen;

	if (isFullscreen)
	{
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	}
	else
	{
		SDL_SetWindowFullscreen(window, 0);
	}
}

void settingsMenu::render(sf::RenderWindow& window, textures& gameTextures)
{
	renderTexture(window, gameTextures, textures::textsIndices::MUSIC, 10, 100, 200, 60);

	renderTexture(window, gameTextures, textures::textsIndices::CONTROLS, 10, 200, 200, 60);

	renderTexture(window, gameTextures, textures::textsIndices::FULLSCREEN, 10, 300, 200, 60);

	renderTexture(window, gameTextures, textures::textsIndices::REPLAY, 10, 400, 200, 60);

	renderTexture(window, gameTextures, textures::textsIndices::RETURN_TO_MENU, 10, 500, 200, 60);

	for (int i = 0; i < btnTable.size(); ++i)
	{
		btnTable[i].draw(window);
	}
}

void settingsMenu::stateEffect(sf::RenderWindow& window, bool& isFullscreen)
{
	switch (currentSettingsState)
	{
	case settingsState::Fullscreen:
		applyFullscreen(window, isFullscreen);
		break;
	}
}