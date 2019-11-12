#include "grid.h"

PathFinding::PathFinding(int _iStartX, int _iStartY, int _iEndX, int _iEndY)
{
	m_pOpenList = new vector <CGridNode*>(); // { startNode };
	m_pClosedList = new vector <CGridNode*>();

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			m_pGrid[x][y] = new CGridNode(x, y);
			m_pGrid[x][y]->SetGCost(INT_MAX);
			m_pGrid[x][y]->SetCameFrom(nullptr);
			m_pGrid[x][y]->GetFCost();

		}
	}

	startNode = m_pGrid[_iStartX][_iStartY];
	endNode = m_pGrid[_iEndX][_iEndY];

	startNode->SetDisplayType('S');
	endNode->SetDisplayType('E');

	m_pOpenList->push_back(m_pGrid[_iStartX][_iStartY]);

	startNode->SetGCost(0);
	startNode->SetHCost(CalculateHDistanceCost(startNode, endNode));
	startNode->GetFCost();

	// This is an iterator - DONT DELETE
	//vector<CGridNode*>::iterator it = m_pOpenList->begin();
	//
	//while (it != m_pOpenList->end()) {
	//	CGridNode* myNodePointer = *it;
	//	myNodePointer->GetFCost();
	//}

}

PathFinding::~PathFinding()
{
	delete m_pOpenList;
	delete m_pClosedList;
}



bool PathFinding::FindPath()
{
	while (m_pOpenList->size() != 0)
	{
		CGridNode* currentNode = GetLowestFCostNode(m_pOpenList);
		if (currentNode == endNode)
		{
			endNode = currentNode;
			CalculatePath();
			return true;
		}


		// Removes node from open list
		vector<CGridNode*>::iterator itOpenList = m_pOpenList->begin();
		while (itOpenList != m_pOpenList->end()) 
		{
			CGridNode* myNodePointer = *itOpenList;
			if (myNodePointer == currentNode)
			{
				m_pOpenList->erase(itOpenList);
				break;
			}
			itOpenList++;
		}

		// Adds it to the closed list
		m_pClosedList->push_back(currentNode);


		vector<CGridNode*>* NeighbourList = GetNeighbourList(currentNode);
		

		// itirates through the NeighbourList 
		bool bIsOnClosedList;
		int tempGCost;
		vector<CGridNode*>::iterator itNeighbour = NeighbourList->begin();
		while (itNeighbour != NeighbourList->end())
		{
			bIsOnClosedList = false;

			CGridNode* NeighbourNodePointer = *itNeighbour;

			// Checks that its on the closed list
			vector<CGridNode*>::iterator itClosedList = m_pClosedList->begin();
			while (itClosedList != m_pClosedList->end())
			{
				CGridNode* ClosedListNodePointer = *itClosedList;
				if (ClosedListNodePointer == NeighbourNodePointer)
				{
					bIsOnClosedList = true;
					break;
				}
				itClosedList++;
			}

			if (!bIsOnClosedList)
			{
				tempGCost = currentNode->GetGCost() + CalculateGDistanceCost(currentNode, NeighbourNodePointer);
				if (tempGCost < NeighbourNodePointer->GetGCost()) 
				{
					NeighbourNodePointer->SetCameFrom(currentNode);
					NeighbourNodePointer->SetGCost(tempGCost);
					NeighbourNodePointer->SetHCost(CalculateHDistanceCost(NeighbourNodePointer, endNode));
					NeighbourNodePointer->GetFCost();

					// If not in open list, add to open list
					vector<CGridNode*>::iterator itOpenListAdd = m_pOpenList->begin();

					if (m_pOpenList->size() == 0) {
						m_pOpenList->push_back(NeighbourNodePointer);
					}
					else {
						while (itOpenListAdd != m_pOpenList->end())
						{
							CGridNode* myNodePointer = *itOpenListAdd;
							if (myNodePointer == NeighbourNodePointer)
							{
								m_pOpenList->push_back(myNodePointer);
								break;
							}
							itOpenListAdd++;
						}
					}
					

				}

			}


		itNeighbour++;
		}

		//delete NeighbourList;
	}


	return false;
}

vector<CGridNode*>* PathFinding::GetNeighbourList(CGridNode* _pCurrentNode)
{
	vector<CGridNode*>* pNeighbourList = new vector<CGridNode*>();
	bool bCanDoTopRight = true;
	bool bCanDoTopleft = true;
	bool bCanDoBottomRight = true;
	bool bCanDoBottomleft = true;

	int c_iX = _pCurrentNode->GetX();
	int c_iY = _pCurrentNode->GetY();

	CGridNode* pTempPointer;

	// Left
	if (c_iX - 1 >= 0)
	{
		pTempPointer = m_pGrid[c_iX - 1][c_iY];
		if (pTempPointer->GetDisplayType() == 'X')
		{
			bool bCanDoTopleft = false;
			bool bCanDoBottomleft = false;
		}
		else
		{
			pNeighbourList->push_back(pTempPointer);
		}

	}
	// Right
	if (c_iX + 1 <= 10)
	{
		if (m_pGrid[c_iX + 1][c_iY]->GetDisplayType() == 'X')
		{
			bool bCanDoTopRight = false;
			bool bCanDoBottomRight = false;
		}
		else
		{
			pNeighbourList->push_back(m_pGrid[c_iX + 1][c_iY]);
		}

	}
	// Top
	if (c_iY - 1 >= 0)
	{
		if (m_pGrid[c_iX][c_iY - 1]->GetDisplayType() == 'X')
		{
			bool bCanDoTopRight = false;
			bool bCanDoTopLeft = false;
		}
		else
		{
			pNeighbourList->push_back(m_pGrid[c_iX][c_iY - 1]);
		}

	}
	// Bottom
	if (c_iY + 1 <= 10)
	{

		if (m_pGrid[c_iX][c_iY + 1]->GetDisplayType() == 'X')
		{
			bool bCanDoBottomRight = false;
			bool bCanDoBottomLeft = false;
		}
		else
		{
			pNeighbourList->push_back(m_pGrid[c_iX][c_iY + 1]);
		}

	}

	if (bCanDoBottomleft && m_pGrid[c_iX - 1][c_iY + 1])
	{
		pNeighbourList->push_back(m_pGrid[c_iX - 1][c_iY + 1]);
	}
	if (bCanDoBottomRight && m_pGrid[c_iX + 1][c_iY + 1])
	{
		pNeighbourList->push_back(m_pGrid[c_iX + 1][c_iY + 1]);
	}

	if (bCanDoTopleft && m_pGrid[c_iX - 1][c_iY - 1])
	{
		pNeighbourList->push_back(m_pGrid[c_iX - 1][c_iY - 1]);
	}
	if (bCanDoTopRight && m_pGrid[c_iX + 1][c_iY - 1])
	{
		pNeighbourList->push_back(m_pGrid[c_iX + 1][c_iY - 1]);
	}


	return pNeighbourList;
}

bool PathFinding::SetNodeAsBlocker(int _iX, int _iY)
{
	CGridNode* CurrentNode = m_pGrid[_iX][_iY];

	if (CurrentNode->GetDisplayType() == '.')
	{
		CurrentNode->SetDisplayType('X');
		return true;
	}
	return true;
}

void PathFinding::CalculatePath()
{
	CGridNode* CurrentNode = endNode;

	while (CurrentNode->GetCameFrom()->GetDisplayType() == '.')
	{
		CurrentNode->GetCameFrom()->SetDisplayType('0');

		CurrentNode = CurrentNode->GetCameFrom();
	}
	CurrentNode->SetDisplayType('0');
}

int PathFinding::CalculateHDistanceCost(CGridNode* _pFirstNode, CGridNode* _pLastNode)
{
	int iDistanceX = abs(_pFirstNode->GetX() - _pLastNode->GetX());
	int iDistanceY = abs(_pFirstNode->GetY() - _pLastNode->GetY());
	return abs(iDistanceX + iDistanceY);
}

int PathFinding::CalculateGDistanceCost(CGridNode* _pFirstNode, CGridNode* _pLastNode)
{
	if ((_pFirstNode->GetX() == _pLastNode->GetX()) || (_pFirstNode->GetY() == _pLastNode->GetY()))
	{
		return c_iMoveStraightCost;
	}
	return c_iMoveDiagonalCost;
}


CGridNode* PathFinding::GetLowestFCostNode(vector<CGridNode*>* pathNodeList)
{
	vector<CGridNode*>::iterator it = pathNodeList->begin();
	CGridNode* LowestNode;
	LowestNode = *pathNodeList->begin();

	while (it != m_pOpenList->end()) {
		CGridNode* myNodePointer = *it;
		
		if (LowestNode->GetFCost() > myNodePointer->GetFCost())
		{
			LowestNode = myNodePointer;
		}
		it++;
	};



	return LowestNode;
}


void PathFinding::DrawGrid()
{
	CGridNode* CurrentNode;

	

	char Draw;
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{

			CurrentNode = m_pGrid[x][y];

			Draw = CurrentNode->GetDisplayType();
			cout << Draw;


		}
		cout << endl;


	}
}