//#pragma once
//
//#pragma once
//#include <vector>
//#include <SFML/Graphics.hpp>
//
//#include "menu.h"
//
//class settingsMenu : public menu
//{
//private:
//    int btnBack;
//    int btnMusic;
//    int btnFullscreen;
//    int btnControls;
//    //initialise buttons
//
//public:
//
//    enum class settingsState //menu's states
//    {
//        Main,
//        Music,
//        Controls,
//        Fullscreen,
//        ReturnMenu
//    };
//
//    settingsMenu() //setting up buttons
//    {
//        btnBack = addBtn(0, 100, "RETURN TO MENU");
//        btnMusic = addBtn(0, 200, "VOLUME");
//        btnFullscreen = addBtn(0, 300, "FULLSCREEN");
//        btnControls = addBtn(0, 400, "CONTROLS");
//    }
//
//    void onBtnPressed(int id) override //function to change states when btn pressed
//    {
//        if (id == btnMusic)
//        {
//            currentSettingsState = settingsState::Music;
//        }
//        else if (id == btnFullscreen)
//        {
//            currentSettingsState = settingsState::Fullscreen;
//        }
//        else if (id == btnBack)
//        {
//            currentSettingsState = settingsState::ReturnMenu;
//        }
//        else if (id == btnControls)
//        {
//            currentSettingsState = settingsState::Controls;
//        }
//    }
//
//private:
//
//    settingsState currentSettingsState = settingsState::Main; //Setting state to main
//
//public:
//
//    settingsState getCurrentState() const //get current menu's state
//    {
//        return currentSettingsState;
//    }
//
//    void applyFullscreen(sf::RenderWindow& window, bool& isFullscreen); //fullscreen
//
//    void render(sf::RenderWindow& window, textures& gameTextures) override; //render this->menu
//
//    void stateEffect(sf::RenderWindow& window, bool& isFullscreen); //applies the effects of buttons that not directly related to changing state
//};