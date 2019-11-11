//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name   : main.cpp
// Description : Main file
// Author      : Andrew Barnes and David Haverland
// Mail        : andrew.bar8456@mediadesign.school.nz and david.hav8466@mediadesign.school.nz
//



// All the libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "display.h"

#include "graph.h"

using namespace std;

void AStarAlgorithm()
{

}

void BreadthAlgorithm()
{

}

void DepthAlgorithm()
{

}

bool CheckNodeInputErrors(string _strNodeInput)
{
	if (_strNodeInput.front() == ',' or _strNodeInput.back() == ',')
	{
		return false;
	}

	for (int i = 0; i < _strNodeInput.size() - 1; i++)
	{
		if (_strNodeInput.at(i) == ',' and _strNodeInput.at(i + 1) == ',')
		{
			return false;
		}
	}

	return true;
}


bool CheckForDigits(const string &str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}


bool CheckEdgeAmountErrors(string _strEdgeAmount)
{
	if (!CheckForDigits(_strEdgeAmount))
	{
		return false;
	}

	int iEdgeAmount = stoi(_strEdgeAmount);

	if (iEdgeAmount > 0 and iEdgeAmount < 100)
	{
		return true;
	}
	
	return false;

}


void Search()
{
	DisplaySearchHeader();

	string strNodeInput = "";
	string strEdgeAmount = "";

	int iEdgeAmount = 0;


	  /////////////////////
	 // Inputting nodes //
	/////////////////////
	DisplaySearchHeader();
	cout << "	Please input Nodes seperated by ',' (All nodes must have diffrent names)" << endl;

	// Gets and clears the input
	cin.clear();
	cin.ignore(9999999,'\n');
	getline(cin, strNodeInput);


	while (!CheckNodeInputErrors(strNodeInput))
	{
		DisplaySearchHeader();
		cout << "	Error - Please input Nodes seperated by ',' (All nodes must have diffrent names)" << endl;

		cin.clear();

		getline(cin, strNodeInput);
	}

	CGraph graph(strNodeInput);



	  ///////////////////////////
	 // Inputting edge amount //
	///////////////////////////
	DisplaySearchHeader();
	cout << "	Nodes:" << endl;
	cout << strNodeInput << endl;
	cout << endl;

	cout << "	Please input the amount of edges (between 1 and 99)" << endl;
	cin.clear();

	getline(cin, strEdgeAmount);

	while (!CheckEdgeAmountErrors(strEdgeAmount))
	{
		DisplaySearchHeader();
		cout << "	Nodes:" << endl;
		cout << strNodeInput << endl;
		cout << endl;

		cout << "	Error - Please input the amount of edges (between 1 and 99)" << endl;
		cin.clear();

		getline(cin, strEdgeAmount);
	}


	
	  /////////////////////
	 // Inputting edges //
	/////////////////////
	iEdgeAmount = stoi(strEdgeAmount);

	while (iEdgeAmount != 0)
	{
		

		

	}

	
	//graph.AddEdge(0, 1);
	//graph.AddEdge(0, 2);
	//graph.AddEdge(1, 2);
	//graph.AddEdge(2, 3);
	//graph.AddEdge(3, 4);
	//graph.AddEdge(4, 5);
	//graph.AddEdge(1, 6);


	cout << "Depth First Traversal" << endl;
	graph.DFS();
	cout << endl;


	cout << "Breadth First Traversal" << endl;
	graph.BFS();
	cout << endl;

	


	int iTemp = 0;
	cin >> iTemp;
}


void InputMenu() 
{

	bool bErrorThrown = false;

	while (true)
	{
		

		if (bErrorThrown == false)
		{
			DisplayMenu();
		}
		else
		{
			DisplayMenuError();
		}
		bErrorThrown = false;

		// Inputs
		int iInput;
		cin >> iInput;

		// A* algorithm
		if (iInput == 1)
		{

		}

		// Search
		else if (iInput == 2)
		{
			Search();

		}



		//Exit function
		else if (iInput == 3)
		{
			exit(0);
		}

		// recalls this function 
		else
		{
			bErrorThrown = true;

			// Clears the input
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
}





int main()
{
	
	system("color f0");



	while (true)
	{

		// Main Menu
		InputMenu();
	
	}



	Sleep(5000);
	int iTemp = 0;
	cin >> iTemp;
	return 0;
}