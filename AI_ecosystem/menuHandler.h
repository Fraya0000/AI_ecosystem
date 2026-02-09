#pragma once

#pragma once
#include <vector>

#include "btn.h"
#include "mainMenu.h"
#include "settingsMenu.h"
#include "textures.h"

class menuHandler
{
public:
	enum class gameState //The differents menu windows to switch between
	{
		menuState,
		playState,
		settingsState,
		escState
	};
	
public:
	menuHandler(sf::RenderWindow& _window); //constructor
	~menuHandler(); //destructor

	gameState getState(); //Allows to display the current gameState

	void render(sf::RenderWindow& window, textures& gameTextures); //Function to render the menu that is in current action

	void reset(); //Set the gameState back to the main menu

	void update();

	void changeState(gameState newState); //Used to change state in the menus child's

	void handleEvent(sf::Event& Event);

private:
	gameState currentState = gameState::menuState; //Sets the gameState to it's main state

	sf::RenderWindow& window; //gives window

private:
	settingsMenu sMenu;

	mainMenu mMenu;

	//To go back to main menu when in other gamerStates
};