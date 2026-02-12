#pragma once
#include <vector>

#include "node.h"

class flowNode : public node
{
public:
	flowNode();
	flowNode(behaviorTree* tree, flowNode* nodeParent, const std::vector<node*>& nodeChilds);
	virtual ~flowNode() override;

	virtual void onChildEnd(eNodeState childResult);

	virtual void startExecute() override;
	virtual void Tick(float deltaTime) override;

	void addChild(node* child);

protected:
	std::vector<node*> childs;
	node* currentExecuteChild;
};

