#include "map.h"
#include <iostream>

map::map(int width, int height, int tileSize, const std::string& tilesetPath)
    : width(width), height(height), tileSize(tileSize) 
{
    tiles.resize(height);
    for (int i = 0; i < height; i++) {
        tiles[i].resize(width, 0);
    }
    if (!loadTileSet(tilesetPath)) {
        std::cerr << "error loading tileSet" << std::endl;
    }
    tileSprite.setTexture(tileSet);
    vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    vertices.resize(width * height * 6);
}

map::~map() 
{
}

bool map::loadTileSet(const std::string& path) 
{
    if (!tileSet.loadFromFile(path)) {
        return false;
    }
    return true;
}

void map::createEmptyMap() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Bordures = wall (type 1), interior = ground (type 0)
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
                tiles[y][x] = 1;
            }
            else {
                tiles[y][x] = 0;
            }
        }
    }
}

void map::setTile(int x, int y, int tileType) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        tiles[y][x] = tileType;
    }
}

int map::getTile(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return tiles[y][x];
    }
    return -1; // off limits
}

void map::draw(sf::RenderWindow& window)
{
    sf::Sprite tileSprite(tileSet);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int tileType = tiles[y][x];
            int tu = tileType * tileSize;
            int tv = 0;

            tileSprite.setTextureRect(sf::IntRect({ tu, tv }, { tileSize, tileSize }));
            tileSprite.setPosition(sf::Vector2f(x * tileSize, y * tileSize));
        	window.draw(tileSprite);
        }
    }
}

bool map::isWalkable(int x, int y) const 
{
    if (x < 0 || x >= width || y < 0 || y >= height) 
    {
        return false;
    }
    int tile = tiles[y][x];
    return tile == 0;
}

sf::Vector2i map::pixelToTile(int pixelX, int pixelY) const 
{
    return sf::Vector2i(pixelX / tileSize, pixelY / tileSize);
}

sf::Vector2f map::tileToPixel(int tileX, int tileY) const 
{
    return sf::Vector2f
	(
        tileX * tileSize + tileSize / 2.0f,
        tileY * tileSize + tileSize / 2.0f
    );
}