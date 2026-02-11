#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class map
{
private:
	std::vector < std::vector<int>> tiles;
	int width;
	int height;
	int tileSize;
	sf::Texture* tileSet;
	sf::Sprite* tileSprite;
	sf::VertexArray vertices;

public:
	map(int width, int height, int tileSize, const std::string& tileSetPath);
	~map();
	bool loadTileSet(const std::string& path);
	bool loadFromFile(const std::string& mapFile);
	void createEmptyMap();
	void setTile(int x, int y, int tileType);
	int getTile(int x, int y) const;
	void draw(sf::RenderWindow& window) const; // const or not const?
	void buildVertexArray();
	bool isWalkable(int x, int y) const;
	sf::Vector2i pixelToTile(int pixelX, int pixelY) const;
	sf::Vector2f tileToPixel(int tileX, int tileY) const;
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	int getTileSize() const { return tileSize; }

};

