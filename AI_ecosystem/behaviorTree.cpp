#include "behaviorTree.h"

#include "merchant.h"
#include "merchantTaskNodes.h"
#include "taskNode.h"
#include "fallBack.h"
#include "node.h"
#include "sequence.h"

behaviorTree::behaviorTree() : behaviorTree(nullptr)
{
}

behaviorTree::behaviorTree(blackboard* bb) : internBlackBoard(bb)
{
}

behaviorTree::~behaviorTree()	
{
}

void behaviorTree::startExecute()
{
	root->startExecute();
}

void behaviorTree::Tick(float deltaTime)
{
	root->Tick(deltaTime);
}

void behaviorTree::buildTree()
{
	root = new rootNode();
	allSubNodes.push_back(root);
}

void behaviorTree::cleanTree()
{
	for (auto node : allSubNodes)
	{
		delete node;
		node = nullptr;
	}
	allSubNodes.clear();
}

blackboard* behaviorTree::getBlackBoard()
{
	return internBlackBoard;
}

merchantBehaviorTree::merchantBehaviorTree() : merchantBehaviorTree(nullptr)
{
}

merchantBehaviorTree::merchantBehaviorTree(blackboard* bb) : behaviorTree(bb)
{
}

merchantBehaviorTree::~merchantBehaviorTree()
{
}

//void clientBehaviorTree::buildTree()
//{
//	behaviorTree::buildTree();
//
//	fallBack* fallback1 = new fallBack(this, nullptr, {});
//	root->child = fallback1;
//
//	sequence* sequence1 = new sequence(this, fallback1, {});
//	fallback1->addChild(sequence1);
//
//	//seePlayerTask* task1 = new seePlayerTask(this, sequence);
//	//sequence1->addChild(task1);
//
//	//allSubNodes.push_back(task1);
//	allSubNodes.push_back(sequence1);
//	allSubNodes.push_back(fallback1);
//}

void merchantBehaviorTree::buildTree()
{
    behaviorTree::buildTree();

    fallBack* timeRoot = new fallBack();
    root->child = timeRoot;
    allSubNodes.push_back(timeRoot);

    // Morning branch
    sequence* morningSeq = new sequence();
    timeRoot->addChild(morningSeq);
    allSubNodes.push_back(morningSeq);

	// check if it's morning
    checkMorningTask* checkMorning = new checkMorningTask();
    morningSeq->addChild(checkMorning);
    allSubNodes.push_back(checkMorning);

    // open shops
    openShopsTask* openShops = new openShopsTask();
    morningSeq->addChild(openShops);
    allSubNodes.push_back(openShops);

    // Day branch
    sequence* daySeq = new sequence();
    timeRoot->addChild(daySeq);
    allSubNodes.push_back(daySeq);

	// check if it's day
    checkDayTask* checkDay = new checkDayTask();
    daySeq->addChild(checkDay);
    allSubNodes.push_back(checkDay);

    // Spawn clients
    spawnClientsTask* spawnClients = new spawnClientsTask();
    daySeq->addChild(spawnClients);
    allSubNodes.push_back(spawnClients);

    // Update clients
    updateClientsTask* updateClients = new updateClientsTask();
    daySeq->addChild(updateClients);
    allSubNodes.push_back(updateClients);

	// Delete clients that finished their path
    cleanupClientsTask* cleanupClients = new cleanupClientsTask();
    daySeq->addChild(cleanupClients);
    allSubNodes.push_back(cleanupClients);

	// Evening branch
    sequence* eveningSeq = new sequence();
    timeRoot->addChild(eveningSeq);
    allSubNodes.push_back(eveningSeq);

	// Check if it's evening
    checkEveningTask* checkEvening = new checkEveningTask();
    eveningSeq->addChild(checkEvening);
    allSubNodes.push_back(checkEvening);

    // Close shops
    closeShopsTask* closeShops = new closeShopsTask();
    eveningSeq->addChild(closeShops);
    allSubNodes.push_back(closeShops);
}