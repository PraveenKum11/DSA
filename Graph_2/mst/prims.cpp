#include <bits/stdc++.h>
using namespace std;

/*
Prim's algorithm is a popular minimum spanning tree (MST) algorithm used to 
find the minimum spanning tree of a connected, undirected graph with weighted 
edges. It was developed by mathematician Robert Prim in 1957 and is widely used 
in computer networks, clustering, and other applications.

The algorithm starts with an arbitrary vertex of the graph and iteratively 
grows a tree by adding edges that connect the tree to vertices outside the 
tree, while keeping the tree connected and acyclic. The algorithm maintains 
a set of vertices that are part of the MST and a set of vertices that are 
not yet included in the MST. The basic steps of Prim's algorithm are as follows:

1. Start with an arbitrary vertex as the starting vertex of the MST.
2. Initialize a set of vertices included in the MST with only the starting vertex.
3. While there are vertices not yet included in the MST:
   a. Find the minimum-weight edge that connects a vertex in the MST to a vertex outside the MST.
   b. Add this edge to the MST, and add the newly included vertex to the set of vertices included in the MST.
4. Repeat step 3 until all vertices are included in the MST.

Prim's algorithm can be implemented using various data structures such as priority 
queues or heaps to efficiently find the minimum-weight edge in step 3a. The time 
complexity of Prim's algorithm is typically O(|V|^2) for a naive implementation with 
an adjacency matrix, but it can be optimized to O(|V| + |E| log |V|) using a priority queue or a heap.

The output of Prim's algorithm is a minimum spanning tree, which is a tree that spans 
all the vertices of the original graph with the minimum possible total edge weight. 
The resulting tree may not be unique, but it will always have the same total weight, 
which is the minimum possible weight among all spanning trees of the graph.

Conditions for Prim's algorithm to work correctly:

1. The graph must be connected: This means that there is a path 
between any two vertices of the graph. If the graph is not connected, 
the algorithm will only generate a minimum spanning tree for the 
connected component containing the starting vertex.

2. The graph must be undirected: Prim's algorithm only works 
for undirected graphs because it relies on the ability to 
find the minimum-weight edge that connects a vertex in the 
MST to a vertex outside the MST. In a directed graph, there 
may not be a corresponding edge that connects vertices in both directions.

3. The edges must have weights: Prim's algorithm requires that 
the edges of the graph have weights, which represent the cost 
or distance associated with traversing that edge. If the edges 
do not have weights, then the algorithm cannot determine 
the minimum spanning tree.

4. The weights must be non-negative: Prim's algorithm assumes 
that the edge weights are non-negative. If there are negative 
edge weights, the algorithm may not work correctly.

NOTE: It very similar to dijkastra's algo (which itself it just bfs with priority_queue and visited changed).
*/

class Graph
{
	int m_vertices;
	int m_edges;
	map<int, list<pair<int, int>>> l;
					// weight, vertex

public:
	Graph(int vertices, int edges)
	: m_vertices(vertices)
	, m_edges(edges) {}

	void addEdge(int src, int dst, int wt)
	{
		l[src].push_back({wt, dst});
		l[dst].push_back({wt, src});
	}

	void print()
	{
		for (auto vertex : l)
		{
			cout << vertex.first << " : ";
			for (auto nbr : vertex.second)
			{
				cout << nbr.second << " ";
			}
			cout << endl;
		}
	}

	int prims()
	{
		int mstWeight = 0;
		vector<bool> visited(m_vertices + 1, false);

		// Min Heap to get the next min weight edge
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
																	  // weight, vertex

		// push the souce vertex with weight 0 (can be any node)
		pq.push({0, 1});

		while(!pq.empty())
		{
			pair<int, int> front = pq.top();
			pq.pop();

			if (visited[front.second]) continue;		// not an active edge
			// x -- y is an active edge if 
			// x is mst vertex and y in non 
			// mst vertex or vice versa

			mstWeight += front.first;
			visited[front.second] = true;
			// cout<< front.second << "--" << front.first << endl;

			for (auto nbr : l[front.second])
			{
				if (!visited[nbr.second])
				{
					pq.push(nbr);
				}
			}
		}
		return mstWeight;
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
	// G.print();

	cout << G.prims() << endl;
	return 0;
}