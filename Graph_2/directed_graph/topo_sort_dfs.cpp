#include <bits/stdc++.h>
using namespace std;

// NOTE: Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering 
//		 of vertices such that for every directed edge u v, vertex u comes before v 
//		 in the ordering.

class Graph
{
public:
	map<int, list<int>> l;
	int m_size;

	Graph(int size) : m_size(size) {}

	void addEdge(int src, int dst, bool bidir=false)
	{
		l[src].push_back(dst);
		if (bidir) l[dst].push_back(src);
	}

	void print()
	{
		for (auto [v, nbrs] : l)
		{
			cout << v << " : ";
			for (auto nbr : nbrs)
			{
				cout << nbr << " ";
			}
			cout << endl;
		}
	}

	void dfs(int src, list<int>& result, vector<bool>& visited)
	{
		for (auto nbr : l[src])
		{
			if (!visited[nbr])
			{
				visited[nbr] = true;
				dfs(nbr, result, visited);
			}
		}
		result.push_front(src);
	}

//  NOTE: Just dfs traverse the graph and add the nodes to the front of
//		  result just before leaving (adding to prevent reverse order).
	void topologicalSort()
	{
		list<int> result;
		vector<bool> visited(m_size, false);
		int src = 1;

		dfs(src, result, visited);
		for (auto i : result)
			cout << i << " ";
		cout << endl;
	}
};

int main()
{
	Graph G(6);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.addEdge(6, 3);
	G.addEdge(5, 6);
	G.addEdge(4, 5);
	G.addEdge(1, 4);
	// G.print();


	G.topologicalSort();
	// result => 1 4 5 6 2 3 

	return 0;
}

/*

	12		23
	  \		/
	   V   V
	  	 5

to complete 5, we first need to finish 12 and 23, therefore topo order -> 12 23 5

*/