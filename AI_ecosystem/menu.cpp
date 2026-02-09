#include "menu.h"
#include "textures.h"
#include "btn.h"

int menu::addBtn(int x, int y, const std::string& name)
{
    btnTable.emplace_back(x, y, name);
    return static_cast<int>(btnTable.size() - 1);
}

void menu::renderTexture(sf::RenderWindow& window, textures gameTextures, textures::textsIndices index, float x, float y, float w, float h)
{
    auto texture = gameTextures.getTextTexture(index);

    sf::IntRect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    sf::Texture(window, texture, nullptr, &rectangle);
}

inline const std::vector<Btn>& menu::getButtons() const
{
    return btnTable;
}

void menu::handleMenuEvent(sf::Event& Event)
{
    for (int i = 0; i < btnTable.size(); ++i)
    {
        btnTable[i].handleBtnEvent(Event);
    }
}
