// THEORY: A bipartite graph, also called a bigraph, is a set of graph vertices 
//		   decomposed into two disjoint sets such that no two graph vertices within
//		   the same set are adjacent.

// CORE IDEA: If a graph has odd length then it is not bipartite.
// REASON: 	  Since we can put each node it SET_1 or SET_2 (i.e. 2 sets),
//			  Therefore, when a odd length cycle is tried to partition
// 			  we will always have the first and last node as same COLOR/SET.
//			  EG.
//			 (1)   (2)   (1)   (2)   (1)
//			  1 <-> 2 <-> 3 <-> 4 <-> 5		// not a bipartite as 1 and 5 are adjacent and of same color
//			  ^_______________________^		// cycle length - 5
//
// NOTE: We don't count for the odd lenght cycle in actual code, we just
//		 simulate the process of coloring during dfs.

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	unordered_map<int, list<int>> l;
	bool m_oddCycle = false;

	void addEdge(int src, int dst, int bidir)
	{
		l[src].push_back(dst);
		if (bidir) l[dst].push_back(src);
	}
	void printGraph()
	{
		for (auto [v, nbrs] : l)
		{
			cout << v << " : ";
			for (auto nbr : nbrs)
				cout << nbr << ", ";
			cout << endl;
		}
	}

	void dfs(int src, int color, vector<int>& visited, int parent)
	{
		visited[src] = color;

		for (auto nbr : l[src])
		{
			if (!visited[nbr])
			{
				// trick to alter btw 1 & 2 color
				// 3 - 1 = 2
				// 3 - 2 = 1
				dfs(nbr, 3 - color, visited, src);
			}
			else if (nbr != parent && visited[nbr] == color)
			{
				m_oddCycle = true;
				return;
			}
		}
	}

	bool bipartite()
	{
		// visited array will contain the three states (visited & color) :
		// 0 -> not visited
		// 1 -> visited & color 1
		// 2 -> visited & color 2

		vector<int> visited(l.size(), 0);
		dfs(1, 1, visited, -1);
		return !m_oddCycle;
	}
};

int main()
{
	Graph G;
	G.addEdge(0, 1, true);
	G.addEdge(1, 2, true);
	G.addEdge(2, 3, true);
	G.addEdge(3, 4, true);
	G.addEdge(4, 5, true);
	G.addEdge(5, 0, true);
	G.printGraph();

	cout << (G.bipartite() ? "Bipartite" : "Non-Bipartite") << endl;
	return 0;
}
