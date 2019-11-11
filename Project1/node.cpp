#include "node.h"

CNode::CNode(string _strName)
{
	m_strName = _strName;
}

CNode::~CNode()
{

}

string CNode::GetNodeName()
{
	return m_strName;
}
