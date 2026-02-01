#include "textures.h"

textures::textures()
{
	loadTexture(texturesIndices::background, "assets/.png");
	loadTexture(texturesIndices::backgroundMenu, "assets/.png");
	loadTexture(texturesIndices::baker, "assets/.png");
	loadTexture(texturesIndices::bakerShop, "assets/.png");
	loadTexture(texturesIndices::black_smith, "assets/.png");
	loadTexture(texturesIndices::black_smithShop, "assets/.png");
	loadTexture(texturesIndices::butcher, "assets/.png");
	loadTexture(texturesIndices::butcherShop, "assets/.png");
	loadTexture(texturesIndices::clients, "assets/.png");
	loadTexture(texturesIndices::clothingseller, "assets/.png");

	loadImgFont(fontsIndices::menuTitle, "assets/.png");

	createTexts(textsIndices::controls, "assets/.png");
	createTexts(textsIndices::music, "assets/.png");
	createTexts(textsIndices::play, "assets/.png");
	createTexts(textsIndices::return_menu, "assets/.png");
	createTexts(textsIndices::settings, "assets/.png");
}

textures::~textures()
{
	//find what to put here
}

sf::Texture textures::getTexture(texturesIndices index)
{
	return tabTextures[(int)index];
}

sf::Texture textures::getImgFont(fontsIndices index)
{
	return tabFonts[(int)index];
}

sf::Texture textures::getTexture(textsIndices index)
{
	return tabTexts[(int)index];
}

void textures::loadTexture(texturesIndices _index, const char* filename)
{

	auto index = (int)_index;

	if (index >= tabTextures.size())
	{
		tabTextures.resize(index + 1);
	}

	if (!tabTextures[index].loadFromFile(filename))
	{
		sf::err() << "couldn't load image" << std::endl;
		sf::RenderWindow window; //TODO Error needs to be done again i think i declare window but locally not taking the window delared in main so not gonna work
		window.close();
	}
}

void textures::loadImgFont(fontsIndices _index, const char* filename)
{
	auto index = (int)_index;

	if (index >= tabFonts.size())
	{
		tabFonts.resize(index + 1);
	}

	if (!tabFonts[index].loadFromFile(filename))
	{
		sf::err() << "couldn't load image" << std::endl;
		sf::RenderWindow window; //TODO Error needs to be done again i think i declare window but locally not taking the window delared in main so not gonna work
		window.close();
	}
}
	
void textures::createTexts(textsIndices _index, const char* filename)
{
	sprite.setTexture(getTexture(textures::texturesIndices::background))

	auto index = (int)_index;

	if (index >= tabTexts.size())
	{
		tabTexts.resize(index + 1);
	}
	tabTexts[index] = texture;
}
