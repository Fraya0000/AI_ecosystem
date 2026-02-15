#pragma once
#include "gameTime.h"
#include "taskNode.h"
#include"merchant.h"
#include "merchantBlackBoard.h"
#include <random>
#include <iostream>
#include "clients.h"

// Tasks to check time of day

class CheckMorningTask : public taskNode {
public:
    CheckMorningTask() : taskNode() {}

    virtual ~CheckMorningTask() override {}

    eNodeState evaluate(blackboard* bb) override {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (mbb->getTimeOfDay() == gameState::Morning) {
            return eNodeState::Success;
        }
        return eNodeState::Failure;
    }
};

class CheckDayTask : public taskNode {
public:
    CheckDayTask() : taskNode() {}

    virtual ~CheckDayTask() override {}

    eNodeState evaluate(blackboard* bb) override {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (mbb->getTimeOfDay() == gameState::Day) {
            return eNodeState::Success;
        }
        return eNodeState::Failure;
    }
};

class CheckEveningTask : public taskNode {
public:
    CheckEveningTask() : taskNode() {}

    virtual ~CheckEveningTask() override {}

    eNodeState evaluate(blackboard* bb) override {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (mbb->getTimeOfDay() == gameState::Evening) {
            return eNodeState::Success;
        }
        return eNodeState::Failure;
    }
};

// Morning tasks

class OpenShopsTask : public taskNode {
public:
    OpenShopsTask() : taskNode() {}

    virtual ~OpenShopsTask() override {}

    eNodeState evaluate(blackboard* bb) override {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        for (auto merchant : mbb->getMerchants()) {
            if (!merchant->isOpen) {
                merchant->isOpen = true;
            }
        }

        return eNodeState::Success;
    }
};

// Day tasks

class SpawnClientsTask : public taskNode {
private:
    bool clientsSpawned = false;

public:
    SpawnClientsTask() : taskNode() {}

    virtual ~SpawnClientsTask() override {}

    eNodeState evaluate(blackboard* bb) override {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (clientsSpawned || !mbb->getClients().empty()) {
            return eNodeState::Success;
        }

        std::random_device rd;
        std::mt19937 gen(rd());

        for (int i = 0; i < 2; i++) {
            std::uniform_real_distribution<> yDist(100, 500);
            sf::Vector2f startPos(-50, static_cast<float>(yDist(gen)));

            std::vector<std::string> clientImages;
            if (i == 0) {
                clientImages = {
                    "assets/evoli_look_right.png",
                    "assets/evoli_look_right_move_1.png",
                    "assets/evoli_look_right_move_2.png",
                    "assets/evoli_look_right_move_3.png"
                };
            }
            else {
                clientImages = {
                    "assets/voltali_look_right.png",
                    "assets/voltali_look_right_move_1.png",
                    "assets/voltali_look_right_move_2.png",
                    "assets/voltali_look_right_move_3.png"
                };
            }

            clients* newClient = new clients(clientImages, startPos);

            std::uniform_int_distribution<> merchantDist(0, 2);
            int targetMerchant = merchantDist(gen);

            sf::Vector2f merchantPos = mbb->getMerchants()[targetMerchant]->position;

            std::vector<sf::Vector2f> path = {
                merchantPos,
                sf::Vector2f(850, merchantPos.y)
            };

            newClient->setMovementPath(path);
            mbb->addClient(newClient);

            std::cout << "Client " << i << " spawned, going to "
                << mbb->getMerchants()[targetMerchant]->name << "\n";
        }

        clientsSpawned = true;
        return eNodeState::Success;
    }
};

class UpdateClientsTask : public taskNode {
public:
    UpdateClientsTask() : taskNode() {}

    virtual ~UpdateClientsTask() override {}

    eNodeState evaluate(blackboard* bb) override {
        return eNodeState::Success;
    }
};

class CleanupClientsTask : public taskNode {
public:
    CleanupClientsTask() : taskNode() {}

    virtual ~CleanupClientsTask() override {}

    eNodeState evaluate(blackboard* bb) override {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);
        mbb->removeFinishedClients();
        return eNodeState::Success;
    }
};

// Evening tasks

class CloseShopsTask : public taskNode {
private:
    bool shopsClosed = false;

public:
    CloseShopsTask() : taskNode() {}

    virtual ~CloseShopsTask() override {}

    eNodeState evaluate(blackboard* bb) override {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (!shopsClosed) {
            for (auto merchant : mbb->getMerchants()) {
                merchant->isOpen = false;
            }
            shopsClosed = true;
        }

        return eNodeState::Success;
    }
};