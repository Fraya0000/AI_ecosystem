#include "sequence.h"

sequence::sequence() : sequence(nullptr, nullptr, {})
{
}

sequence::sequence(behaviorTree* tree, flowNode* nodeParent, const std::vector<node*>& nodeChilds) : flowNode(tree, nodeParent, nodeChilds)
{
}

sequence::~sequence()
{
}

void sequence::onChildEnd(eNodeState childResult)
{
	if (childResult == eNodeState::Success)
	{
		flowNode::onChildEnd(childResult);
		if (currentExecuteChild != nullptr)
		{
		}
		else
		{
			if (parent != nullptr)
			{
				parent->onChildEnd(eNodeState::Success);
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