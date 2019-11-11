#pragma once


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

#include "node.h"


using namespace std;

class CGraph
{
public:
	CGraph(string _strNamesOfNodes);
	~CGraph();

	void AddEdge(int _iVector1, int _iVector2);

	void DFS();
	void BFS();

	string GetNodeName(int _nodeNumber);

	int NodeNameToNumber(string _nodeName);


private:

	int m_iNumberOfVertices;

	int m_iNumberOfNodes;

	list<int> *m_iNumberOfNode;

	vector<CNode*> m_pAllNodes;
	//CNode* m_pAdjcentNodes[];

	// keeps doing the DFS thing
	void DFSFunction(int v, bool visited[]);




};