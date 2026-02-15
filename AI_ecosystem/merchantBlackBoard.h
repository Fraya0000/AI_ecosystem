#pragma once
#include "merchant.h"
#include "behaviorTree.h"
#include "gameTime.h"
#include "clients.h"
#include <vector>

class merchantBlackBoard : public blackboard
{
private:
    std::vector<merchant*> merchants;
    std::vector<clients*> clientsList;
    gameState currentTimeOfDay;

public:
    merchantBlackBoard() : currentTimeOfDay(gameState::Morning)
    {
        merchants.push_back(new merchant(merchantType::Baker, sf::Vector2f(50, 300.f), "Baker"));
        merchants.push_back(new merchant(merchantType::Butcher, sf::Vector2f(385, 330), "Butcher"));
        merchants.push_back(new merchant(merchantType::Fisherman, sf::Vector2f(930, 300), "Fisherman"));
    }

    ~merchantBlackBoard()
    {
        for (auto m : merchants) delete m;
        for (auto c : clientsList) delete c;
    }

    std::vector<merchant*>& getMerchants() { return merchants; }
    std::vector<clients*>& getClients() { return clientsList; }
    gameState getTimeOfDay() const { return currentTimeOfDay; }

    void setTimeOfDay(gameState state)
    {
        currentTimeOfDay = state;
    }

    void addClient(clients* client)
    {
        clientsList.push_back(client);
    }

    void removeFinishedClients()
    {
        for (auto it = clientsList.begin(); it != clientsList.end(); )
        {
            if ((*it)->hasFinishedPath())
            {
                delete* it;
                it = clientsList.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
};