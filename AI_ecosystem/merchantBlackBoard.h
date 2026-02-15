#pragma once
#include "merchant.h"
#include "behaviorTree.h"
#include "gameTime.h"
#include "clients.h"
#include "clientManager.h"
#include <vector>

class merchantBlackBoard : public blackboard
{
private:
    std::vector<merchant*> merchants;
    std::vector<clients*> clientsList;
    std::vector<clients*> spawnedClients;
    clientManager* cclientManager;
    gameState currentTimeOfDay;

public:
    merchantBlackBoard() : currentTimeOfDay(gameState::Morning)
    {
        // Create 3 merchants
        merchants.push_back(new merchant(merchantType::Baker, sf::Vector2f(50, 300.f), "Baker"));
        merchants.push_back(new merchant(merchantType::Butcher, sf::Vector2f(385, 330), "Butcher"));
        merchants.push_back(new merchant(merchantType::Fisherman, sf::Vector2f(930, 300), "Fisherman"));

		// Create client manager
        cclientManager = new clientManager();
        cclientManager->setupPaths();
    }

    ~merchantBlackBoard()
    {
        for (auto m : merchants) delete m;
        for (auto c : clientsList) delete c;
    }

    std::vector<merchant*>& getMerchants() { return merchants; }
    std::vector<clients*>& getClients() { return clientsList; }
    gameState getTimeOfDay() const { return currentTimeOfDay; }
    clientManager* getClientManager() { return cclientManager; }

    void setTimeOfDay(gameState state)
    {
        currentTimeOfDay = state;
    }

    void addClient(clients* client)
    {
        clientsList.push_back(client);
    }

    std::vector<clients*>& getSpawnedClients() {
        return spawnedClients;
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