#pragma once
#include <vector>
#include <Matrix3.h>


class Node
{
public:
public:

	Node();
	~Node();

	Matrix3 m_localTransform;
	Matrix3 m_globalTransform;

	void setParent(Node* parent);
	void addChild(Node* child);
	void removeChild(Node* child);
	void UpdateTransforms();

protected:
	Node* m_parent;
	std::vector<Node*> m_children;
};

