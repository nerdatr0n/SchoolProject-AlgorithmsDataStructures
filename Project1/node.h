#pragma once


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

class CNode
{
public:
	CNode(string _strName);
	~CNode();




	string GetNodeName();

	

private:

	string m_strName;

	
	list<int> *m_pAdjcentNodes;
	

};