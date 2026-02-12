#pragma once
class behaviorTree;
class blackboard;
class flowNode;

enum class eNodeState
{
	Unknow = 0,
	Failure = 1,
	Succes = 2,
};

class baseNode
{
public:
	baseNode();
	baseNode(behaviorTree* tree);
	virtual ~baseNode();

	virtual void startExecute();
	virtual void Tick(float deltaTime);
	virtual void endExecute();

	blackboard* getBlackBoard();
	behaviorTree* getBehaviorTree();
protected:
	behaviorTree* ownerTree;
};

class node : public baseNode
{
public:
	node();
	node(behaviorTree* tree, flowNode* nodeParent);
	virtual ~node() override;

protected:
	flowNode* parent;
};

class rootNode : public baseNode
{
public:
	rootNode();
	rootNode(behaviorTree* tree, baseNode* nodeChild);
	virtual ~rootNode() override;

	void startExecute() override;
	void Tick(float deltaTime) override;

	baseNode* child;
};