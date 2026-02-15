#pragma once
#include <vector>

class rootNode;
class baseNode;

class blackboard
{
public:

};

class behaviorTree
{
public:
	behaviorTree();
	behaviorTree(blackboard* bb);
	virtual ~behaviorTree();

	void startExecute();
	void Tick(float deltaTime);

	virtual void buildTree();
	void cleanTree();

public:
	blackboard* getBlackBoard();

protected:
	blackboard* internBlackBoard;
	rootNode* root;
	std::vector<baseNode*> allSubNodes;
};

class merchantBehaviorTree : public behaviorTree
{
public:
	merchantBehaviorTree();
	merchantBehaviorTree(blackboard* bb);
	virtual ~merchantBehaviorTree();

	virtual void buildTree() override;
};