#pragma once
#include <SFML/Graphics.hpp>

class game
{
private:
	int windowWidth, windowHeight;
	bool inMenu = true;
	float now = 0.0f;
	float deltaTime, relativeOrigin;

private:
	//TODO this type --> player gamePlayer = player(renderer, gameTextures, 7900, 372, windowWidth, windowHeight);

public:
	game(sf::RenderWindow& _window, int _windowWidth, int _windowHeight);
	~game();

	void update();
	void render();
	bool getMenuState();
public:
	//TODO this type --> intputHandler& getInputHandler();
};