#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	map<int, list<int>> l;
	int m_edges;
	bool m_cycle = false;

public:
	Graph(int edges) : m_edges(edges) {}
	void addEdge(int src, int dst, int bidir=false)
	{
		l[src].push_back(dst);
		if (bidir) l[dst].push_back(src);
	}

	void print()
	{
		for (auto [vtx, nbrs] : l)
		{
			cout << vtx << ": ";
			for (auto nbr : nbrs)
				cout << nbr << " ";
			cout << endl;
		}
	}


	void dfs(int src, map<int, bool>& visited, map<int, bool>& currentPath)
	{
		// visit the current node and add it to the current path
		visited[src] = true;
		currentPath[src] = true;

		for (auto nbr : l[src])
		{
			if (!visited[nbr])
			{
				dfs(nbr, visited, currentPath);
			}
			else if (currentPath[nbr])
			{
				m_cycle = true;
			}
		}
		// remove the current node from the current path
		currentPath[src] = false;
	}


//  NOTE: Cycle detection in directed graph is NOT same as in undirected graph
//		  eg. 1 -> 2 -> 3 <- 4
//			  ---------------^
//		  Even though 3 is visited twice (dfs) but there is not cycle, therefore to find
//		  a cycle we need to find if the current node is in the current path, if the
// 		  current node is in the path and it is visited again, then there is a cycle
//		  otherwise it does not form a cycle.
	void cycleDetection()
	{
		map<int, bool> visited;
		map<int, bool> currentPath; 		// currentPath acts as the stack for dfs nodes

		int src = 1;
		dfs(src, visited, currentPath);
		cout << (m_cycle ? "Cycle found" : "Cycle not found") << endl;
	}
};


int main()
{
	Graph G(6);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.addEdge(1, 4);
	G.addEdge(4, 5);
	G.addEdge(5, 6);
	G.addEdge(6, 3);
	G.print();

	G.cycleDetection();

	return 0;
}