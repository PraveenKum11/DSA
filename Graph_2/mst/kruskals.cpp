#include <bits/stdc++.h>
using namespace std;

/*
Kruskal's algorithm is a popular algorithm used for finding the minimum 
spanning tree (MST) of a connected, undirected graph. It was developed 
by Joseph Kruskal in 1956 and is known for its simplicity and efficiency.

The algorithm works as follows:

1. Initialize an empty set to represent the MST.
2. Sort all the edges of the graph in ascending order of their weights.
3. Iterate through the sorted edges and for each edge, do the following:
	3.a. If including the edge does not form a cycle in the MST, add it to the MST.
	3.b. Otherwise, discard the edge.
4. Continue this process until the MST contains V-1 edges, 
	where V is the number of vertices in the graph.

Kruskal's algorithm uses a disjoint-set data structure to keep track of 
connected components and detect cycles efficiently. The algorithm ensures 
that the MST is connected and acyclic, and it terminates when it has found 
V-1 edges, where V is the number of vertices in the graph, which is the 
minimum number of edges required for a connected, undirected graph to form a spanning tree.

Kruskal's algorithm has a time complexity of O(E log E), where E is the number 
of edges in the graph. It is commonly used in applications such as:
network design, clustering, and scheduling problems where finding the 
minimum spanning tree of a graph is necessary.
*/

class DSU
{
	int m_size;
	vector<int> parent;

public:
	void init(int size)
	{
		m_size = size + 1;
		parent.resize(m_size);
		for (int i = 0; i < m_size; i++)
			parent[i] = i;
	}

	int find(int x)
	{
		if (x == parent[x])
			return x;
		return parent[x] = find(parent[x]);
	}

	// return true - if no cycle 
	bool unionSet(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);

		// same parent or same set
		if (rootX == rootY)
		{
			return false;
		}

		parent[rootX] = rootY;
		return true;
	}

};

class Graph
{
	int m_vertices;
	int m_edges;
	vector<vector<int>> m_edgeList;
	// We will use edge list to store the graph
	// since we need to sort the edges by weight

	DSU dsu;		// for cycle detection in undirected graph

public:
	Graph(int vertices, int edges) : m_vertices(vertices), m_edges(edges)
	{
		dsu.init(m_vertices);
	}

	void addEdge(int src, int dst, int wt)
	{
		m_edgeList.push_back({src, dst, wt});
	}

	void print()
	{
		for (auto edge : m_edgeList)
			cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
	}


	void kruskalMST()
	{
		// vector to store the MST
		vector<vector<int>> mst;

		// sort all the edges based on their weights
		sort(begin(m_edgeList), end(m_edgeList), [](vector<int> x, vector<int> y) { return x[2] < y[2]; });

		// select edges one by one to add to MST,
		// that do not for a cycle
		for (auto edge : m_edgeList)
		{
			if (dsu.unionSet(edge[0], edge[1]))
				mst.push_back(edge);
		}

		// print mst
		for (auto edge : mst)
			cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
	}

};

int main()
{
	Graph G(6, 7);
	G.addEdge(1, 2, 2);
	G.addEdge(1, 4, 3);
	G.addEdge(2, 3, 5);
	G.addEdge(4, 3, 1);
	G.addEdge(3, 5, 8);
	G.addEdge(3, 6, 6);
	G.addEdge(5, 6, 4);

	G.kruskalMST();

	return 0;
}