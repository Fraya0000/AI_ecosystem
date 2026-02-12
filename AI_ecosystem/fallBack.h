#pragma once
#include <vector>

#include "flowNode.h"

class fallBack : public	flowNode
{
public:
	fallBack();
	fallBack(behaviorTree* tree, flowNode* nodeParent, const std::vector<node*>& nodeChilds);
	virtual ~fallBack() override;

	virtual void onChildEnd(eNodeState childResult);
};