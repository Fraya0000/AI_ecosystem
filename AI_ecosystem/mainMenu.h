#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "btn.h"
#include "menu.h"

class mainMenu : public menu
{

private:

    int btnSettings;
    int btnPlay;
    int btnBack;
    //initialise buttons

public:

    enum class mainmenuState //menu's states
    {
        Main,
        Play,
        Settings,
        ReturnMenu
    };

    mainMenu() //setting up buttons
    {
        btnPlay = addBtn(0, 100, "PLAY");
        btnSettings = addBtn(0, 200, "SETTINGS");
    }

    void onBtnPressed(int id) override //function to change states when btn pressed
    {
        if (id == btnSettings)
        {
            currentMainMenuState = mainmenuState::Settings;
        }
        else if (id == btnPlay)
        {
            currentMainMenuState = mainmenuState::Play;
        }
    }

private:

    mainmenuState currentMainMenuState = mainmenuState::Main; //Setting state to main

public:

    mainmenuState getCurrentState() const //get current menu's state
    {
        return currentMainMenuState;
    }

    void render(sf::RenderWindow& window, textures& gameTextures) override; //render this->menu
};