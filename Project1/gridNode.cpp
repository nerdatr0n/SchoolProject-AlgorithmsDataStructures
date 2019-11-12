#include "gridNode.h"

CGridNode::CGridNode(int _iX, int _iY)
{
	m_iX = _iX;
	m_iY = _iY;

}

CGridNode::~CGridNode()
{
}

void CGridNode::SetGCost(int _iGCost)
{
	m_iGCost = _iGCost;
}

void CGridNode::SetHCost(int _iHCost)
{
	m_iHCost = _iHCost;
}

void CGridNode::SetFCost(int _iFCost)
{
	m_iFCost = _iFCost;
}

void CGridNode::SetCameFrom(CGridNode * _pCameFrom)
{
	m_pCameFrom = _pCameFrom;
}

int CGridNode::GetGCost()
{
	return m_iGCost;
}

int CGridNode::GetHCost()
{
	return m_iHCost;
}

int CGridNode::GetFCost()
{
	return m_iFCost;
}

CGridNode * CGridNode::GetCameFrom()
{
	return m_pCameFrom;
}



