#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "behaviorTree.h"
#include "gameTime.h"

//class Clock {
//public:
//    Clock() = default;
//    Clock(bool StartImmediatly) {
//        if (StartImmediatly) {
//            Start();
//        }
//    }
//
//    void Start() {
//        Restart();
//    }
//    float Restart() {
//        std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
//        std::chrono::duration<float> Duration = Actual - TimeStart;
//
//        TimeStart = Actual;
//        LastCallElpased = Actual;
//
//        return Duration.count();
//    }
//    float GetElapsedTime() {
//        std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
//        std::chrono::duration<float> Duration = Actual - LastCallElpased;
//
//        LastCallElpased = Actual;
//        return Duration.count();
//    }
//    float TimeSinceStart() {
//        std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
//        std::chrono::duration<float> Duration = Actual - TimeStart;
//        return Duration.count();
//    }
//
//private:
//    std::chrono::time_point<std::chrono::steady_clock> TimeStart;
//    std::chrono::time_point<std::chrono::steady_clock> LastCallElpased;
//};



int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "marchand_map");
    sf::RectangleShape rectangle;
    sf::Texture* map = new sf::Texture("assets/marchand_map.png");
    rectangle.setSize({ 800, 600 });
    rectangle.setTexture(map);

    gameTime timer;
	sf::Clock clock;
    sf::Font font("assets/arial.ttf");
    sf::Text timerText(font);
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition({ 20, 20 });
    //Clock BTClock = Clock(true);
    //const float Duration = 20.0f;

    //blackboard* MyBlackBoard = new clientBlackBoard();
    //behaviorTree* MyBt = new clientBehaviorTree(MyBlackBoard);
    //MyBt->buildTree();
    //MyBt->startExecute();

    //while (BTClock.TimeSinceStart() < 10000.0f) {
    //    float DeltaTime = BTClock.GetElapsedTime();
    //    MyBt->Tick(DeltaTime);
    //}
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
		timer.update(deltaTime);

		std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << "Time: " << timer.getTime() << "s | ";
        switch (timer.getState()) {
        case gameState::Morning:
            ss << "Morning";
            break;
        case gameState::Day:
            ss << "Day";
            break;
        case gameState::Evening:
            ss << "Evening";
            break;
        }
		timerText.setString(ss.str());

        while (const auto event = window.pollEvent())
        {
            if (event.has_value() && event->getIf<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.setVerticalSyncEnabled(true);
        window.clear();
        window.draw(rectangle);
        window.draw(timerText);
        window.display();
    }

    delete map;
    return 0;
}