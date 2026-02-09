#pragma once

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "menu.h"

class settingsMenu : public menu
{
public:
	enum class settingsState //menu's states
	{
		Main,
		Music,
		Controls,
		Fullscreen,
		ReturnMenu
	};

public:
	settingsState getCurrentState() const; //get current menu's state

	settingsMenu(); //setting up buttons

	void onBtnPressed(int id) override; //function to change states when btn pressed

	void applyFullscreen(sf::RenderWindow& window, bool& isFullscreen); //fullscreen

	void render(sf::RenderWindow& window, textures& gameTextures) override; //render this->menu

	void stateEffect(sf::RenderWindow& window, bool& isFullscreen); //applies the effects of buttons that not directly related to changing state

private:
	int btnBack;
	int btnMusic;
	int btnFullscreen;
	int btnControls;
	//initialise buttons

private:
	settingsState currentSettingsState = settingsState::Main; //Setting state to main
};