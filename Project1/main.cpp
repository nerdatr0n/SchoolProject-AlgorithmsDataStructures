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
#include <vector>

#include "display.h"

#include "graph.h"
#include "grid.h"
#include "errorCheck.h"

using namespace std;

void AStarAlgorithm()
{
	

	string strCoordInputs;
	int iStartNodeX;
	int iStartNodeY;
	int iEndNodeX;
	int iEndNodeY;


	  //////////////////////////
	 // Inputting Start Node //
	//////////////////////////
	DisplaySearchHeader();
	cout << "	Start Node:  ,  End Node:  ,  " << endl;
	cout << "	Please input the start position seperated by ','" << endl;

	// Gets and clears the input
	cin.clear();
	cin.ignore(9999999, '\n');
	getline(cin, strCoordInputs);


	while (!CheckStringCoords(strCoordInputs))
	{
		DisplaySearchHeader();
		cout << "	Error - Please input the start position seperated by ','" << endl;

		cin.clear();

		getline(cin, strCoordInputs);
	}

	// removes spaces
	string::iterator end_pos = remove(strCoordInputs.begin(), strCoordInputs.end(), ' ');
	strCoordInputs.erase(end_pos, strCoordInputs.end());

	std::string delimiter = ",";
	string token;
	size_t pos = 0;

	string _strCoordY;

	while ((pos = strCoordInputs.find(delimiter)) != string::npos)
	{
		strCoordInputs = strCoordInputs.substr(0, pos);

		strCoordInputs.erase(0, pos + delimiter.length());
	}


	iStartNodeX = stoi(strCoordInputs);
	iStartNodeY = stoi(_strCoordY);


	////////////////////////
   // Inputting End Node //
  ////////////////////////
	DisplaySearchHeader();
	cout << "	Start Node: " << iStartNodeX << "," << iStartNodeY << " End Node:  ,  " << endl;
	cout << "	Please input the end position seperated by ','" << endl;

	// Gets and clears the input
	cin.clear();
	cin.ignore(9999999, '\n');
	getline(cin, strCoordInputs);


	while (!CheckStringCoords(strCoordInputs))
	{
		DisplaySearchHeader();
		cout << "	Start Node: " << iStartNodeX << "," << iStartNodeY << " End Node:  ,  " << endl;
		cout << "	Error - Please input the end position seperated by ','" << endl;

		cin.clear();

		getline(cin, strCoordInputs);
	}

	// removes spaces
	end_pos = remove(strCoordInputs.begin(), strCoordInputs.end(), ' ');
	strCoordInputs.erase(end_pos, strCoordInputs.end());

	pos = 0;

	

	while ((pos = strCoordInputs.find(delimiter)) != string::npos)
	{
		strCoordInputs = strCoordInputs.substr(0, pos);

		strCoordInputs.erase(0, pos + delimiter.length());
	}


	iEndNodeX = stoi(strCoordInputs);
	iEndNodeY = stoi(_strCoordY);





	PathFinding PathFind(iStartNodeX, iStartNodeY, iEndNodeX, iEndNodeY);
	DisplaySearchHeader();
	cout << "	Start Node: " << iStartNodeX << "," << iStartNodeY << " End Node: " << iEndNodeX << "," << iEndNodeY << endl;
	cout << "	Error - Please input blocker coords seperated by ','" << endl;
	PathFind.DrawGrid();










	if (PathFind.FindPath())
	{
		PathFind.CalculatePath();
	}
	else
	{
		cout << "No path";
	}

	PathFind.DrawGrid();

	int iTemp = 0;
	cin >> iTemp;
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
	cout << "	" << strNodeInput << endl;
	cout << endl;

	cout << "	Please input the amount of edges (between 1 and 99)" << endl;
	cin.clear();

	getline(cin, strEdgeAmount);

	while (!CheckEdgeAmountErrors(strEdgeAmount))
	{
		DisplaySearchHeader();
		cout << "	Nodes:" << endl;
		cout << "	" << strNodeInput << endl;
		cout << endl;

		cout << "	Error - Please input the amount of edges (between 1 and 99)" << endl;
		cin.clear();

		getline(cin, strEdgeAmount);
	}


	
	  /////////////////////
	 // Inputting edges //
	/////////////////////
	iEdgeAmount = stoi(strEdgeAmount);
	int iEdgesLeft = iEdgeAmount;

	string strEdgeInput;
	string token;
	size_t pos = 0;
	string delimiter = ",";

	while (iEdgesLeft != 0)
	{
		DisplaySearchHeader();
		cout << "	Nodes:" << endl;
		cout << "	" << strNodeInput << endl;
		cout << endl;
		cout << "	Total number of nodes: " << iEdgeAmount << endl;
		cout << "	Nodes left: " << iEdgesLeft << endl;
		cout << endl;
		cout << "	Please input two nodes seperated by a ','" << endl;
		cin.clear();

		

		getline(cin, strEdgeInput);

		while (!CheckEdgeErrors(strEdgeInput, &graph))
		{
			DisplaySearchHeader();
			cout << "	Nodes:" << endl;
			cout << "	" << strNodeInput << endl;
			cout << endl;
			cout << "	Total number of nodes: " << iEdgeAmount << endl;
			cout << "	Nodes left: " << iEdgesLeft << endl;
			cout << endl;
			cout << "	Error - Please input two nodes seperated by a ','" << endl;
			cin.clear();

			

			getline(cin, strEdgeInput);


		}
		

		
		iEdgesLeft--;
		string::iterator end_pos = remove(strEdgeInput.begin(), strEdgeInput.end(), ' ');
		strEdgeInput.erase(end_pos, strEdgeInput.end());

		
		token = "";
		pos = 0;


		while ((pos = strEdgeInput.find(delimiter)) != string::npos) {

			token = strEdgeInput.substr(0, pos);

			strEdgeInput.erase(0, pos + delimiter.length());


		}
		graph.AddEdge(graph.NodeNameToNumber(token), graph.NodeNameToNumber(strEdgeInput));
		
	}

	



	cout << "Depth First Traversal" << endl;
	graph.DFS();
	cout << endl;
	cout << endl;

	cout << "Breadth First Traversal" << endl;
	graph.BFS();
	cout << endl;
	cout << endl;
	cout << "Input anything to return to the menu" << endl;


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
			AStarAlgorithm();
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