#pragma once


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>

#include "gridNode.h"

using namespace std;

class PathFinding
{
public:
	PathFinding(int _iStartX, int _iStartY, int _iEndX, int _iEndY);
	~PathFinding();

	int CalculateHDistanceCost(CGridNode* _pFirstNode, CGridNode* _pLastNode);
	int CalculateGDistanceCost(CGridNode* _pFirstNode, CGridNode* _pLastNode);
	
	bool FindPath();
	bool SetNodeAsBlocker(int _iX, int _iY);

	void CalculatePath();
	void DrawGrid();

private:

	const int c_iMoveStraightCost = 10;
	const int c_iMoveDiagonalCost = 14;
	string m_strName;


	vector <CGridNode*>* m_pOpenList;
	vector <CGridNode*>* m_pClosedList;
	
	CGridNode* m_pGrid[10][10];
	CGridNode* startNode;
	CGridNode* endNode;


	list<int> *m_pAdjcentNodes;

	// Random functions taht do things
	
	CGridNode* GetLowestFCostNode(vector<CGridNode*>* pathNodeList);
	vector<CGridNode*>* GetNeighbourList(CGridNode* _pCurrentNode);
};


