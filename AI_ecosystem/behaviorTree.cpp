#include "behaviorTree.h"

#include "fallBack.h"
#include "node.h"
//#include "seePlayerTask.h"
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

clientBehaviorTree::clientBehaviorTree() : clientBehaviorTree(nullptr)
{
}

clientBehaviorTree::clientBehaviorTree(blackboard* bb) : behaviorTree(bb)
{
}

clientBehaviorTree::~clientBehaviorTree()
{
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