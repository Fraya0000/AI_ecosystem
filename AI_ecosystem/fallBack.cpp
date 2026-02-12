#include "fallBack.h"

fallBack::fallBack() : fallBack(nullptr, nullptr, {})
{
}

fallBack::fallBack(behaviorTree* tree, flowNode* nodeParent, const std::vector<node*>& nodeChilds) : flowNode(tree, nodeParent, nodeChilds)
{
}

fallBack::~fallBack()
{
}

void fallBack::onChildEnd(eNodeState childResult)
{
	if (childResult == eNodeState::Failure)
	{
		flowNode::onChildEnd(childResult);
		if (currentExecuteChild != nullptr)
		{
			currentExecuteChild->startExecute();
		}
		else
		{
			if (parent != nullptr)
			{
				parent->onChildEnd(eNodeState::Succes);
			}
			else
			{
				currentExecuteChild = *childs.begin();
				currentExecuteChild->startExecute();
			}
		}
	}

	else
	{
		if (parent != nullptr)
		{
			parent->onChildEnd(eNodeState::Failure);
		}
		else
		{
			currentExecuteChild = *childs.begin();
			currentExecuteChild->startExecute();
		}
	}
}