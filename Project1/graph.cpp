#include "graph.h"

CGraph::CGraph(int _iNumberOfEdges)
{
	this->m_iNumberOfVertices = _iNumberOfEdges;
	m_pAdjcentNodes = new list<int>[_iNumberOfEdges];
}

CGraph::~CGraph()
{

}


void CGraph::AddEdge(int _iVector1, int _iVector2)
{
	m_pAdjcentNodes[_iVector1].push_back(_iVector2);
}




void CGraph::DFSUtil(int _iVector, bool visited[])
{
	// Mark the current node as visited and 
	// print it 
	visited[_iVector] = true;
	cout << _iVector << " ";

	// Recur for all the vertices adjacent 
	// to this vertex 

	list<int>::iterator i;

	for (i = m_pAdjcentNodes[_iVector].begin(); i != m_pAdjcentNodes[_iVector].end(); ++i)
	{
		if (!visited[*i])
		{
			DFSUtil(*i, visited);
		}
	}
}



void CGraph::DFS(int v)
{
	// Mark all the vertices as not visited 
	bool *visited = new bool[m_iNumberOfVertices];

	for (int i = 0; i < m_iNumberOfVertices; i++)
	{
		visited[i] = false;
	}

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(v, visited);
}


void CGraph::BFS(int s)
{
	// Mark all the vertices as not visited 
	bool *visited = new bool[m_iNumberOfVertices];


	for (int i = 0; i < m_iNumberOfVertices; i++)
	{
		visited[i] = false;
	}


	// Create a queue for BFS 
	list<int> queue;

	// Mark the current node as visited and enqueue it 
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent 
	// vertices of a vertex 
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (i = m_pAdjcentNodes[s].begin(); i != m_pAdjcentNodes[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}


