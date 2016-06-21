#include "Node.h"



Node::Node()
{
	m_parent = nullptr;
}

Node::~Node()
{
}

void Node::setParent(Node * parent)
{
	if (m_parent != nullptr)
	{
		m_parent->removeChild(this);
	}
	m_parent = parent;
	parent->addChild(this);
}

void Node::addChild(Node * child)
{
	m_children.push_back(child);
}

void Node::removeChild(Node * child)
{
	child->m_parent = nullptr;
	for (int i = 0; i < m_children.size(); i++)
	{
		if (m_children[i] = child)
		{
			m_children.erase(m_children.begin() + i);
		}
	}
}

void Node::UpdateTransforms()
{
	if (m_parent != nullptr)
	{
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	}
	else
	{
		m_globalTransform = m_localTransform;
	}
	for (int i = 0; i < m_children.size(); i++)
	{
		m_children[i]->UpdateTransforms();
	}

}
