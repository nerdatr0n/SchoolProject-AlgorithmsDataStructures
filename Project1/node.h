//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name   : errorCheck.cpp
// Description : Contains all the error checks
// Author      : Andrew Barnes and David Haverland
// Mail        : andrew.bar8456@mediadesign.school.nz and david.hav8466@mediadesign.school.nz
//


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