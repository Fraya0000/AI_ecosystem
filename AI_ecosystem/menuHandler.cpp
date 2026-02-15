//#include "menuHandler.h"
//#include "textures.h"
//
//menuHandler::menuHandler(sf::RenderWindow& _window)
//{
//}
//
//menuHandler::~menuHandler()
//{
//}
//
//void menuHandler::update()
//{
//    switch (currentState)
//    {
//    case gameState::menuState:
//        if (mMenu.getCurrentState() == mainMenu::mainmenuState::ReturnMenu)
//        {
//            changeState(gameState::menuState);
//        }
//        break;
//    case gameState::settingsState:
//        if (sMenu.getCurrentState() == settingsMenu::settingsState::ReturnMenu)
//        {
//            changeState(gameState::menuState);
//        }
//        break;
//    }
//}
//
//void menuHandler::changeState(gameState newState)
//{
//    currentState = newState;
//}
//
//void menuHandler::handleEvent(sf::Event& Event)
//{
//    switch (currentState)
//    {
//    case gameState::settingsState:
//        sMenu.handleMenuEvent(Event);
//        break;
//    case gameState::menuState:
//        mMenu.handleMenuEvent(Event);
//        break;
//    }
//}
//
//void menuHandler::render(sf::RenderWindow& window, textures& gameTextures)
//{
//    switch (currentState)
//    {
//    case gameState::settingsState:
//        sMenu.render(window, gameTextures);
//        break;
//    case gameState::menuState:
//        mMenu.render(window, gameTextures);
//        break;
//    }
//}
//
//menuHandler::gameState menuHandler::getState()
//{
//    return currentState;
//}











//void menuHandler::reset()
//{
//    currentState = gameState::menuState;
//}