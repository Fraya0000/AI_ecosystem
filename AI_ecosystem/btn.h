#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Btn
{
private:
	sf::FloatRect rectClicked; //TODO need to do the mouse detection system where when image is clicked rectangle behind is the one being clicked and activates the btn

private:
	bool isBtnClicked;
	bool wasClicked;

public:
	Btn(int x, int y, std::string text);

public:
	void draw(sf::RenderWindow& window) const;
	void handleBtnEvent(sf::Event& Event);
	bool isClicked();
};