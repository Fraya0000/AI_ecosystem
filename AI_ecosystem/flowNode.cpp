#include "flowNode.h"

flowNode::flowNode() : flowNode(nullptr, nullptr, {})
{
}

flowNode::flowNode(behaviorTree* tree, flowNode* nodeParent, const std::vector<node*>& nodeChilds) : node(tree, nodeParent), childs(nodeChilds)
{
}

flowNode::~flowNode()
{
}

void flowNode::onChildEnd(eNodeState childResult)
{
	auto It = std::find(childs.begin(), childs.end(), currentExecuteChild);
	if (It != childs.end())
	{
		int Index = std::distance(childs.begin(), It) + 1;
		if (Index < childs.size())
		{
			currentExecuteChild = childs[Index];
		}
		else
		{
			currentExecuteChild = nullptr;
		}
	}
}

void flowNode::startExecute()
{
	currentExecuteChild = *childs.begin();
	if (currentExecuteChild != nullptr)
	{
		currentExecuteChild->startExecute();
	}
}

void flowNode::Tick(float deltaTime)
{
	currentExecuteChild->Tick(deltaTime);
	node::Tick(deltaTime);
}

void flowNode::addChild(node* child)
{
	childs.push_back(child);
}