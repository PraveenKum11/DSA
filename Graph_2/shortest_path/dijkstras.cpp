#include <bits/stdc++.h>
using namespace std;

/*
Dijkstra's algorithm is a popular shortest-path algorithm used to find the 
shortest path between two nodes in a weighted graph. It was developed by 
computer scientist Edsger W. Dijkstra in 1956.

The algorithm works by maintaining a set of unvisited nodes and 
their tentative distances from a source node. Initially, all 
nodes are considered unvisited, and the distance to the source 
node is set to 0. The algorithm then proceeds by selecting the 
node with the minimum tentative distance, marking it as visited, 
and updating the tentative distances of its unvisited neighbors.

The process is repeated until all nodes have been visited, and 
the shortest distance from the source node to each node has been 
determined. The algorithm can also be modified to keep track of 
the shortest path from the source node to each node.

Dijkstra's algorithm is commonly used in routing and network packet forwarding. 
It has a time complexity of O(|E| + |V|log|V|), where |V| is the number of 
nodes in the graph and |E| is the number of edges.

Conditions that need to be met in order for the algorithm to work correctly.
These conditions are:

1. Non-negative edge weights: Dijkstra's algorithm can only be used for 
graphs with non-negative edge weights. If there are negative edge weights 
in the graph, the algorithm will not give the correct shortest path.
Result in incorrect answer.

2. Connected graph: The graph needs to be connected, meaning that 
there is a path from every node to every other node. If the graph 
is not connected, the algorithm will only give the shortest path 
between nodes in the same connected component.

3. Directed or undirected graph: Dijkstra's algorithm can be used 
for both directed and undirected graphs.

4. No negative cycles: A negative cycle is a cycle of edges that 
have a negative weight, and it can cause the algorithm to give 
incorrect results. Therefore, the graph should not have any negative cycles.
Results in infinite loop due to relaxation.
*/

class Graph
{
	int m_vertices;
	int m_edges;
	map<int, list<pair<int, int>>> l;

public:
	Graph(int v, int e) : m_vertices(v), m_edges(e) {}
	void addEdge(int src, int dst, int wt, bool bidir=true)
	{
		l[src].push_back({dst, wt});
		if (bidir) l[dst].push_back({src, wt});
	}

	void print()
	{
		for (auto vertex : l)
		{
			cout << vertex.first << " : ";
			for (auto [nbr, wt] : vertex.second)
				cout << nbr << "-" << wt << " ";
			cout << endl;
		}
	}

	void dijkstras(int src)
	{
		// initially all nodes at infinite distance
		vector<int> dist(m_vertices + 1, INT_MAX);
		vector<int> visited(m_vertices + 1, false);
		// queue to get the next min weight edge to expolore/ relax
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		// priority_queue<pair<int, int>> pq;

		dist[src] = 0;
		pq.push({src, dist[src]});

		while (!pq.empty())
		{
			auto [front, front_wt] = pq.top();
			visited[front] = true;
			pq.pop();

			for (auto [nbr, nbr_wt] : l[front])
			{
				if (!visited[nbr])
				{
					dist[nbr] = min(dist[nbr], dist[front] + nbr_wt);
					pq.push({nbr, dist[nbr]});
				}
			}
		}

		// print the shortest path to all nodes
		for (auto [vertex, nbrs] : l)
		{
			cout << "Distance to " << vertex << " is " << dist[vertex] << endl;
		}
	}
};

int main()
{
	Graph G(4, 5);
	G.addEdge(1, 2, 1);
	G.addEdge(2, 3, 1);
	G.addEdge(1, 3, 4);
	G.addEdge(3, 4, 2);
	G.addEdge(1, 4, 7);

	G.dijkstras(1);

	return 0;
}