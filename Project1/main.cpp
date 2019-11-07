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

#include "display.h"
#include "node.h"
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


void DFSSearch()
{
	DisplaySearchHeader();

	//while (true)
	//{
	//	
	//
	//}

	CGraph graph(4);
	graph.AddEdge(0, 1);
	graph.AddEdge(0, 2);
	graph.AddEdge(1, 2);
	graph.AddEdge(2, 0);
	graph.AddEdge(2, 3);
	graph.AddEdge(3, 3);

	cout << "Following is Depth First Traversal"
		" (starting from vertex 1) \n";
	graph.DFS(1);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	graph.BFS(2);

	int iTemp = 0;
	cin >> iTemp;
}


void InputMenu() 
{

	bool bErrorThrown = false;


Start:
	if (bErrorThrown == false)
	{
		DisplayMenu();
	}
	else
	{
		DisplayMenuError();
	}
	
	
	// Inputs
	int iInput;
	cin >> iInput;

	// A* algorithm
	if (iInput == 1) 
	{
		
	}

	// Breadth-First Search
	else if (iInput == 2)
	{
		DFSSearch();
		
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
		goto Start;
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