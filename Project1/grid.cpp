#include "grid.h"

PathFinding::PathFinding(int _iStartX, int _iStartY, int _iEndX, int _iEndY)
{
	CGridNode* startNode = new CGridNode(_iStartX, _iStartY);


	m_pOpenList = new vector <CGridNode*>; // { startNode };
	m_pClosedList = new vector <CGridNode*>;

	m_pOpenList->push_back(startNode);

	vector<CGridNode*>::iterator it = m_pOpenList->begin();

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			m_pGrid[x][y] = new CGridNode(x, y);
		}
	}


	while (it != m_pOpenList->end()) {
		CGridNode* myNodePointer = *it;
		myNodePointer->GetFCost();
	}

}

PathFinding::~PathFinding()
{


}
