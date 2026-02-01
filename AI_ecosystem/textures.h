#pragma once
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Color.hpp>

class textures
{
public:

	enum class texturesIndices
	{
		butcher,
		butcherShop,
		baker,
		bakerShop,
		black_smith,
		black_smithShop,
		fishmonger,
		fishmongerShop,
		clothingseller,
		clothingsellerShop,

		clients,

		background,
		backgroundMenu,
		timeClock,
		//to do, add the houses here plus all buildings and also other decorations

	};

	enum class fontsIndices
	{
		ui,
		btn,
		menuTitle,
		//to do add the other btn
	};

	enum class textsIndices
	{
		music,
		play,
		settings,
		return_menu,
		controls,
		//to do add the other btn
	};

public:
	textures();

	~textures();

	sf::Texture getTexture(texturesIndices index);
	sf::Texture getImgFont(fontsIndices index);
	sf::Texture getTexture(textsIndices index);

private:
	std::vector <sf::Texture> tabTextures;
	std::vector <sf::Texture> tabFonts;
	std::vector <sf::Texture> tabTexts;
private:
	void loadTexture(texturesIndices _index, const char* filename);
	void loadImgFont(fontsIndices _index, const char* filename);
	void createTexts(textsIndices _index, const char* filename);
};