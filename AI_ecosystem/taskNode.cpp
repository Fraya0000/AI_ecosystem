#include "taskNode.h"

taskNode::taskNode() : taskNode(nullptr, nullptr)
{
}

taskNode::taskNode(behaviorTree* tree, flowNode* nodeParent) : node(tree, nodeParent)
{
}

taskNode::~taskNode()
{
}