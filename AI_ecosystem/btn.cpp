#include "btn.h"

Btn::Btn(int x, int y, std::string text)
{
    struct TTF_Font* font;
    rect.x = x;
    rect.y = y;
    rect.w = 200;
    rect.h = 60;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0;
    hover.r = 0;
    hover.g = 0;
    hover.b = 0;
    hover.a = 0;
    clicked.r = 255;
    clicked.g = 255;
    clicked.b = 255;
    clicked.a = 200;
    isHover = false;
    isBtnClicked = false;
    wasClicked = false;
}

void Btn::draw(sf::RenderWindow& window) const
{
    sf::Color c = color;
    if (isBtnClicked)
    {
        c = clicked;
    }
    else if (isHover)
    {
        c = hover;
    }

    if (c.a > 0)
    {
        //TODO Find how to render like before but now image
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
        SDL_FRect frect;
        frect.x = (float)rect.x;
        frect.y = (float)rect.y;
        frect.w = (float)rect.w;
        frect.h = (float)rect.h;
        SDL_RenderFillRect(renderer, &frect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    }
}

void Btn::handleBtnEvent(sf::Event& Event)
{
    if (Event.isEventSubtype == sf::Event::MouseMoved)
    {
        SDL_Point p = { event.motion.x, event.motion.y };
        isHover = SDL_PointInRect(&p, &rect);
    }
    if (Event.isEventSubtype == sf::Event::MouseButtonPressed && isHover)
    {
        isBtnClicked = true;
    }
    if (Event.isEventSubtype == sf::Event::MouseButtonReleased)
    {
        if (isBtnClicked && isHover)
        {
            wasClicked = true;
        }
        isBtnClicked = false;
    }
}

bool Btn::isClicked()
{
    if (wasClicked)
    {
        wasClicked = 0;
        return true;
    }
    return false;
}