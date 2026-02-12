#include "node.h"
#include "behaviorTree.h"

baseNode::baseNode() : baseNode(nullptr)
{
}

baseNode::baseNode(behaviorTree* tree) : ownerTree(tree)
{
}

baseNode::~baseNode()
{
}

void baseNode::startExecute()
{
}

void baseNode::Tick(float deltaTime)
{
}

void baseNode::endExecute()
{
}

blackboard* baseNode::getBlackBoard()
{
	return getBehaviorTree()->getBlackBoard();
}

behaviorTree* baseNode::getBehaviorTree()
{
	return ownerTree;
}

node::node() : node(nullptr, nullptr)
{
}

node::node(behaviorTree* tree, flowNode* nodeParent) : baseNode(tree), parent(nodeParent)
{
}

node::~node()
{
}

rootNode::rootNode() : rootNode(nullptr, nullptr)
{
}

rootNode::rootNode(behaviorTree* tree, baseNode* nodeChild) : baseNode(tree), child(nodeChild)
{
}

rootNode::~rootNode()
{
}

void rootNode::startExecute()
{
	child->startExecute();
}

void rootNode::Tick(float deltaTime)
{
	child->Tick(deltaTime);
}
