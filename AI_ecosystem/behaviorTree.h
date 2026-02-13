#pragma once
#include <vector>

class rootNode;
class baseNode;

class blackboard
{
public:
	//TODO :  implement all infos for behavior tree into this
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

class clientBlackBoard : public blackboard
{
public:
	int myPosX;
	int myPosY;

	int myDirX;
	int myDirY;

	bool seeMerchand;

	int point1X;
	int point1Y;

	int point2X;
	int point2Y;
};

class merchantBehaviorTree : public behaviorTree
{
public:
	merchantBehaviorTree();
	merchantBehaviorTree(blackboard* bb);
	virtual ~merchantBehaviorTree();

	virtual void buildTree() override;
};

class clientBehaviorTree : public behaviorTree
{
public:
	clientBehaviorTree();
	clientBehaviorTree(blackboard* bb);
	virtual ~clientBehaviorTree();

	virtual void buildTree() override;
};