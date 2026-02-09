#pragma once
#include <vector>
#include <string>

#include "btn.h"
#include "textures.h"

class menu
{
protected:
	int addBtn(int x, int y, const std::string& name); //Allows to set a method for the childs to create their own buttons

	void renderTexture(sf::RenderWindow& window, textures gameTextures, textures::textsIndices index, float x, float y, float w, float h); //Used to render the buttons with there parameters

	std::vector<Btn> btnTable; //Create the table where the menus child's can store their btn

	sf::Texture& backgroundTexture;

public:
	menu() = default; //constructor
	virtual ~menu() = default; //destructor

	virtual void onBtnPressed(int btnId) = 0; //function used by children to determine the effect off buttons when pressed

	inline const std::vector<Btn>& getButtons() const; //function to share the buttons and give them

	virtual void render(sf::RenderWindow& window, textures& gameTextures) = 0; //function so that children are able to render their buttons

	void handleMenuEvent(sf::Event& Event);
};