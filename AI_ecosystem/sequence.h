#pragma once
#include <vector>

#include "flowNode.h"

class sequence : public flowNode
{
public:
	sequence();
	sequence(behaviorTree* tree, flowNode* nodeParent, const std::vector<node*>& nodeChilds);
	virtual ~sequence() override;

	virtual void onChildEnd(eNodeState childResult) override;
};

