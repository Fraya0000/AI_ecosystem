#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "btn.h"
#include "menu.h"

class mainMenu : public menu
{
public:
	enum class mainmenuState //menu's states
	{
		Main,
		Play,
		Settings,
		ReturnMenu
	};

public:
	mainmenuState getCurrentState() const; //get current menu's state

	mainMenu(); //setting up buttons

	void onBtnPressed(int id) override; //function to change states when btn pressed

	void render(sf::RenderWindow& window, textures& gameTextures) override; //render this->menu

private:
	int btnSettings;
	int btnPlay;
	int btnBack;
	//initialise buttons

	mainmenuState currentMainMenuState = mainmenuState::Main; //Setting state to main
private:
	~mainMenu();
};