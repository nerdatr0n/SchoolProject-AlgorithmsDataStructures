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

class CGridNode
{
public:
	CGridNode(int _iX, int _iY);
	~CGridNode();

	void SetGCost(int _iGCost);
	void SetHCost(int _iHCost);
	void SetFCost(int _iFCost);
	
	void SetCameFrom(CGridNode* _pCameFrom);

	
	int GetX();
	int GetY();

	int GetGCost();
	int GetHCost();
	int GetFCost();
	
	CGridNode* GetCameFrom();

	char GetDisplayType();
	void SetDisplayType(char _cDisplayType);


private:

	int m_iX;
	int m_iY;

	int m_iGCost;
	int m_iHCost;
	int m_iFCost;

	CGridNode* m_pCameFrom;

	char cDisplayType = '.';

};