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




	



private:

	string m_strName;


	vector <CGridNode*>* m_pOpenList;
	vector <CGridNode*>* m_pClosedList;
	
	CGridNode* m_pGrid[10][10];

	list<int> *m_pAdjcentNodes;


};


