#pragma once
#include "node.h"

class taskNode : public node
{
public:
	taskNode();
	taskNode(behaviorTree* tree, flowNode* nodeParent);
	virtual ~taskNode() override;
};