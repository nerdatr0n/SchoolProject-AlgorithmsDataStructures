#include "graph.h"



CGraph::CGraph(string _strNamesOfNodes)
{
	// removes spaces
	string::iterator end_pos = remove(_strNamesOfNodes.begin(), _strNamesOfNodes.end(), ' ');
	_strNamesOfNodes.erase(end_pos, _strNamesOfNodes.end());

	// Gets number of commers/nodes
	int iNumberOfEdges = count(_strNamesOfNodes.begin(), _strNamesOfNodes.end(), ',') + 1;

	this->m_iNumberOfVertices = iNumberOfEdges;
	m_iNumberOfNode = new list<int>[iNumberOfEdges];

	cout << _strNamesOfNodes << endl;

	std::string delimiter = ",";
	
	int i = 0;

	size_t pos = 0;

	string token;

	while ((pos = _strNamesOfNodes.find(delimiter)) != string::npos) {

		token = _strNamesOfNodes.substr(0, pos);

		_strNamesOfNodes.erase(0, pos + delimiter.length());
				
		CNode* pNode = new CNode(token);

		cout << token << endl;
		cout << _strNamesOfNodes << endl;

		m_pAdjcentNodes[i] = pNode;

		i++;
	}
	
	CNode* pNode = new CNode(_strNamesOfNodes);
	m_pAdjcentNodes[i] = pNode;
	cout << _strNamesOfNodes << endl;

}

CGraph::~CGraph()
{

}

string CGraph::GetNodeName(int _nodeNumber)
{
	
	CNode* pNode = m_pAdjcentNodes[_nodeNumber];
	return pNode->GetNodeName();

}

void CGraph::AddEdge(int _iVector1, int _iVector2)
{
	m_iNumberOfNode[_iVector1].push_back(_iVector2);
	m_iNumberOfNode[_iVector2].push_back(_iVector1);
}




void CGraph::DFSFunction(int _iVector, bool visited[])
{
	// prints the node thing and marks it as done
	visited[_iVector] = true;
	cout << GetNodeName(_iVector) << " ";



	list<int>::iterator i;

	for (i = m_iNumberOfNode[_iVector].begin(); i != m_iNumberOfNode[_iVector].end(); ++i)
	{
		if (!visited[*i])
		{
			DFSFunction(*i, visited);
		}
	}
}



void CGraph::DFS()
{
	int v = 0;
	// Mark all the vertices as not visited 
	bool *visited = new bool[m_iNumberOfVertices];

	for (int i = 0; i < m_iNumberOfVertices; i++)
	{
		visited[i] = false;
	}

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSFunction(v, visited);


	
}


void CGraph::BFS()
{
	int s = 0;
	// Mark all the vertices as not visited 
	bool *visited = new bool[m_iNumberOfVertices];


	for (int i = 0; i < m_iNumberOfVertices; i++)
	{
		visited[i] = false;
	}


	
	list<int> queue;

	
	visited[s] = true;
	queue.push_back(s);

	
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		cout << GetNodeName(s) << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (i = m_iNumberOfNode[s].begin(); i != m_iNumberOfNode[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}


