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


using namespace std;

void AStarAlgorithm()
{
	PathFinding PathFind(9, 9, 0, 0);

	PathFind.SetNodeAsBlocker(3, 3);
	PathFind.SetNodeAsBlocker(3, 2);

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




bool CheckNodeInputErrors(string _strNodeInput)
{
	if (_strNodeInput.front() == ',' or _strNodeInput.back() == ',')
	{
		// Failed check
		return false;
	}

	for (int i = 0; i < _strNodeInput.size() - 1; i++)
	{
		if (_strNodeInput.at(i) == ',' and _strNodeInput.at(i + 1) == ',')
		{
			// Failed check
			return false;
		}
	}

	
	

	// removes spaces
	string::iterator end_pos = remove(_strNodeInput.begin(), _strNodeInput.end(), ' ');
	_strNodeInput.erase(end_pos, _strNodeInput.end());


	
	
	std::vector<string>::iterator it;
	string strAllStringsSeperate;
	vector<string> strings;
	strings.push_back(strAllStringsSeperate);

	std::string delimiter = ",";


	size_t pos = 0;

	string token;

	while ((pos = _strNodeInput.find(delimiter)) != string::npos) {

		token = _strNodeInput.substr(0, pos);

		_strNodeInput.erase(0, pos + delimiter.length());

		// Finds the meme i put in
		it = find(strings.begin(), strings.end(), token);
		if (it != strings.end())
		{
			return false;
		}
		else
		{
			strings.push_back(token);
		}
	}
	it = find(strings.begin(), strings.end(), _strNodeInput);
	if (it != strings.end())
	{
		return false;
	}
	else
	{
		strings.push_back(_strNodeInput);
	}

	// Passed check
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
		// Failed check
		return false;
	}

	int iEdgeAmount = stoi(_strEdgeAmount);

	if (iEdgeAmount > 0 and iEdgeAmount < 100)
	{
		// Passed check
		return true;
	}
	// Failed check
	return false;

}

bool CheckEdgeErrors(string _strEdge, CGraph* _graph)
{
	// removes spaces
	string::iterator end_pos = remove(_strEdge.begin(), _strEdge.end(), ' ');
	_strEdge.erase(end_pos, _strEdge.end());

	if (count(_strEdge.begin(), _strEdge.end(), ',') != 1)
	{
		// Failed check
		return false;
	}

	std::string delimiter = ",";
	string token;
	size_t pos = 0;


	while ((pos = _strEdge.find(delimiter)) != string::npos) {

		token = _strEdge.substr(0, pos);

		_strEdge.erase(0, pos + delimiter.length());

		token;


		
	}

	if (token == _strEdge)
	{
		// Failed check
		return false;
	}

	if (_graph->NodeNameToNumber(token) == -1 or _graph->NodeNameToNumber(_strEdge) == -1)
	{
		// Failed check
		return false;
	}


	// Passed check
	return true;
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