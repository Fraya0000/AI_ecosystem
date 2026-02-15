#pragma once
#include "gameTime.h"
#include "taskNode.h"
#include"merchant.h"
#include "merchantBlackBoard.h"
#include <random>
#include <iostream>
#include "clients.h"

// Tasks to check time of day

class checkMorningTask : public taskNode 
{
public:
    checkMorningTask() : taskNode() {}

    virtual ~checkMorningTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (mbb->getTimeOfDay() == gameState::Morning) 
        {
            return eNodeState::Success;
        }
        return eNodeState::Failure;
    }
};

class checkDayTask : public taskNode
{
public:
    checkDayTask() : taskNode() {}

    virtual ~checkDayTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (mbb->getTimeOfDay() == gameState::Day) 
        {
            return eNodeState::Success;
        }
        return eNodeState::Failure;
    }
};

class checkEveningTask : public taskNode 
{
public:
    checkEveningTask() : taskNode() {}

    virtual ~checkEveningTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (mbb->getTimeOfDay() == gameState::Evening) 
        {
            return eNodeState::Success;
        }
        return eNodeState::Failure;
    }
};

// Morning tasks

class openShopsTask : public taskNode 
{
private:
    static bool hasOpenedOnce;

public:
    openShopsTask() : taskNode() {}

    virtual ~openShopsTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

		// Only open shops once in the morning
        if (!hasOpenedOnce) 
        {
            for (auto merchant : mbb->getMerchants()) 
            {
                merchant->isOpen = true;
            }
            hasOpenedOnce = true;
        }

        return eNodeState::Success;
    }

    static void reset() { hasOpenedOnce = false; }
};

// Day tasks

class spawnClientsTask : public taskNode 
{
private:
    static bool clientsSpawned;

public:
    spawnClientsTask() : taskNode() {}

    virtual ~spawnClientsTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

		// Only spawn clients once during the day phase
        if (clientsSpawned) 
        {
            return eNodeState::Success;
        }

        std::random_device rd;
        std::mt19937 gen(rd());

        for (int i = 0; i < 2; i++) 
        {
            std::uniform_real_distribution<> yDist(300, 700);
            sf::Vector2f startPos(-50, static_cast<float>(yDist(gen)));

            std::vector<std::string> clientImages;
            if (i == 0) 
            {
                clientImages = 
                {
                    "assets/evoli_look_right.png",
                    "assets/evoli_look_right_move_1.png",
                    "assets/evoli_look_right_move_2.png",
                    "assets/evoli_look_right_move_3.png",
                    "assets/evoli_look_left.png",
                    "assets/evoli_look_left_move_1.png",
                    "assets/evoli_look_left_move_2.png",
                    "assets/evoli_look_left_move_3.png",
                    "assets/evoli_look_up.png",
                    "assets/evoli_look_up_move_1.png",
                    "assets/evoli_look_up_move_2.png",
                    "assets/evoli_look_up_move_3.png",
                    "assets/evoli_look_down.png",
                    "assets/evoli_look_down_move_1.png",
                    "assets/evoli_look_down_move_2.png",
                    "assets/evoli_look_down_move_3.png"
                };
            }
            else 
            {
                clientImages = 
                {
                    "assets/voltatli_look_right.png",
                    "assets/voltatli_look_right_move_1.png",
                    "assets/voltatli_look_right_move_2.png",
                    "assets/voltatli_look_right_move_3.png",
                    "assets/voltatli_look_left.png",
                    "assets/voltatli_look_left_move_1.png",
                    "assets/voltatli_look_left_move_2.png",
                    "assets/voltatli_look_left_move_3.png",
                    "assets/voltatli_look_up.png",
                    "assets/voltatli_look_up_move_1.png",
                    "assets/voltatli_look_up_move_2.png",
                    "assets/voltatli_look_up_move_3.png",
                    "assets/voltatli_look_down.png",
                    "assets/voltatli_look_down_move_1.png",
                    "assets/voltatli_look_down_move_2.png",
                    "assets/voltatli_look_down_move_3.png"
                };
            }

            clients* newClient = new clients(clientImages, startPos);

            std::uniform_int_distribution<> merchantDist(0, 2);
            int targetMerchant = merchantDist(gen);

            sf::Vector2f merchantPos = mbb->getMerchants()[targetMerchant]->position;

            std::vector<sf::Vector2f> path = 
            {
                merchantPos,
                sf::Vector2f(1500, merchantPos.y)
            };

            newClient->setMovementPath(path);
            mbb->addClient(newClient);
        }

        clientsSpawned = true;
        return eNodeState::Success;
    }

    static void reset() { clientsSpawned = false; }
};

class updatePredefinedClientsTask : public taskNode 
{
public:
    updatePredefinedClientsTask() : taskNode() {}

    virtual ~updatePredefinedClientsTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);
		// clients uptaed in the main loop, so we just return success here
        return eNodeState::Success;
    }
};

class updateClientsTask : public taskNode 
{
public:
    updateClientsTask() : taskNode() {}

    virtual ~updateClientsTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        return eNodeState::Success;
    }
};

class cleanupClientsTask : public taskNode 
{
public:
    cleanupClientsTask() : taskNode() {}

    virtual ~cleanupClientsTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);
        mbb->removeFinishedClients();
        return eNodeState::Success;
    }
};

// Evening tasks

class closeShopsTask : public taskNode 
{
private:
    static bool shopsClosed;

public:
    closeShopsTask() : taskNode() {}

    virtual ~closeShopsTask() override {}

    eNodeState evaluate(blackboard* bb) override 
    {
        merchantBlackBoard* mbb = static_cast<merchantBlackBoard*>(bb);

        if (!shopsClosed) 
        {
            for (auto merchant : mbb->getMerchants()) 
            {
                merchant->isOpen = false;
            }
            shopsClosed = true;

            // Reset for the next cycle
            openShopsTask::reset();
            spawnClientsTask::reset();
        }

        return eNodeState::Success;
    }

    static void reset() { shopsClosed = false; }
};