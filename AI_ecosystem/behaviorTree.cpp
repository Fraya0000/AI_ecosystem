#include "behaviorTree.h"

#include "fallBack.h"
#include "node.h"
//#include "seePlayerTask.h"
#include "sequence.h"
#include "taskNode.h"

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

clientBehaviorTree::clientBehaviorTree() : clientBehaviorTree(nullptr)
{
}

clientBehaviorTree::clientBehaviorTree(blackboard* bb) : behaviorTree(bb)
{
}

clientBehaviorTree::~clientBehaviorTree()
{
}

void merchantBehaviorTree::buildTree()
{
	behaviorTree::buildTree();

	fallBack* rootFallback = new fallBack("TimeFallback");
	root->child = rootFallback;
	allSubNodes.push_back(rootFallback);

	fallBack* morningFallback = new fallBack("Morning");
	rootFallback->addChild(morningFallback);
	allSubNodes.push_back(morningFallback);

	sequence* morningSequence = new sequence("MorningSequence");
	morningFallback->addChild(morningSequence);
	allSubNodes.push_back(morningSequence);

	taskNode* createMerchantsTask = new taskNode("Create Merchants");
	morningSequence->addChild(createMerchantsTask);
	allSubNodes.push_back(createMerchantsTask);

	taskNode* createClientsTask = new taskNode("Create Clients");
	morningSequence->addChild(createClientsTask);
	allSubNodes.push_back(createClientsTask);

	fallBack* dayFallback = new fallBack("Day");
	rootFallback->addChild(dayFallback);
	allSubNodes.push_back(dayFallback);

	sequence* merchantSequence = new sequence("Merchant Sequence");
	dayFallback->addChild(merchantSequence);
	allSubNodes.push_back(merchantSequence);

	fallBack* commandReceivedFallback = new fallBack("Command Received ?");
	merchantSequence->addChild(commandReceivedFallback);
	allSubNodes.push_back(commandReceivedFallback);
    taskNode* openShopTask = new taskNode("Open Shop");
    commandReceivedFallback->addChild(openShopTask);
    allSubNodes.push_back(openShopTask);

    taskNode* keepClosedTask = new taskNode("Keep Closed");
    commandReceivedFallback->addChild(keepClosedTask);
    allSubNodes.push_back(keepClosedTask);

    fallBack* deficitFallback = new fallBack("Deficit?");
    merchantSequence->addChild(deficitFallback);
    allSubNodes.push_back(deficitFallback);

    taskNode* increasePriceTask = new taskNode("Increase Price");
    deficitFallback->addChild(increasePriceTask);
    allSubNodes.push_back(increasePriceTask);

    taskNode* samePriceTask = new taskNode("Same Price");
    deficitFallback->addChild(samePriceTask);
    allSubNodes.push_back(samePriceTask);

    fallBack* quantityZeroFallback = new fallBack("Quantity = 0?");
    merchantSequence->addChild(quantityZeroFallback);
    allSubNodes.push_back(quantityZeroFallback);

    taskNode* closeShopTask = new taskNode("Close Shop");
    quantityZeroFallback->addChild(closeShopTask);
    allSubNodes.push_back(closeShopTask);

    taskNode* continueTask = new taskNode("Continue");
    quantityZeroFallback->addChild(continueTask);
    allSubNodes.push_back(continueTask);

    sequence* clientSequence = new sequence("Client Sequence");
    dayFallback->addChild(clientSequence);
    allSubNodes.push_back(clientSequence);

    fallBack* occupiedFallback = new fallBack("Merchant Occupied?");
    clientSequence->addChild(occupiedFallback);
    allSubNodes.push_back(occupiedFallback);

    taskNode* waitTask = new taskNode("Wait");
    occupiedFallback->addChild(waitTask);
    allSubNodes.push_back(waitTask);

    taskNode* processPurchaseTask = new taskNode("Process Purchase");
    occupiedFallback->addChild(processPurchaseTask);
    allSubNodes.push_back(processPurchaseTask);

    fallBack* eveningFallback = new fallBack("Evening");
    rootFallback->addChild(eveningFallback);
    allSubNodes.push_back(eveningFallback);

    fallBack* unsoldFallback = new fallBack("Unsold Count");
    eveningFallback->addChild(unsoldFallback);
    allSubNodes.push_back(unsoldFallback);

    fallBack* bankruptcyFallback = new fallBack("Bankruptcy?");
    unsoldFallback->addChild(bankruptcyFallback);
    allSubNodes.push_back(bankruptcyFallback);

    taskNode* replacementTask = new taskNode("Replacement");
    bankruptcyFallback->addChild(replacementTask);
    allSubNodes.push_back(replacementTask);

    taskNode* continueTask2 = new taskNode("Continue");
    bankruptcyFallback->addChild(continueTask2);
    allSubNodes.push_back(continueTask2);

    fallBack* commandFallback = new fallBack("Command");
    eveningFallback->addChild(commandFallback);
    allSubNodes.push_back(commandFallback);

    fallBack* quantityPositiveFallback = new fallBack("Quantity > 0?");
    commandFallback->addChild(quantityPositiveFallback);
    allSubNodes.push_back(quantityPositiveFallback);

    taskNode* reduceQuantityTask = new taskNode("Reduce Quantity");
    quantityPositiveFallback->addChild(reduceQuantityTask);
    allSubNodes.push_back(reduceQuantityTask);

    fallBack* quantityZeroFallback2 = new fallBack("Quantity = 0?");
    commandFallback->addChild(quantityZeroFallback2);
    allSubNodes.push_back(quantityZeroFallback2);

    taskNode* increaseQuantityTask = new taskNode("Increase Quantity");
    quantityZeroFallback2->addChild(increaseQuantityTask);
    allSubNodes.push_back(increaseQuantityTask);

}

void clientBehaviorTree::buildTree()
{
	behaviorTree::buildTree();

	fallBack* fallback1 = new fallBack(this, nullptr, {});
	root->child = fallback1;

	sequence* sequence1 = new sequence(this, fallback1, {});
	fallback1->addChild(sequence1);

	//seePlayerTask* task1 = new seePlayerTask(this, sequence);
	//sequence1->addChild(task1);

	//allSubNodes.push_back(task1);
	allSubNodes.push_back(sequence1);
	allSubNodes.push_back(fallback1);
}