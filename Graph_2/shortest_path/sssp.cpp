#include <bits/stdc++.h>
using namespace std;

/*
Single source shortest path using BFS is a graph traversal algorithm that finds 
the shortest path from a single source vertex to all other vertices in an unweighted graph. 

The algorithm works by starting at the source vertex and exploring all its adjacent 
vertices first, then moving to their adjacent vertices, and so on, until all vertices 
have been visited. During this process, the algorithm keeps track of the distance 
from the source vertex to each visited vertex.

To find the shortest path from the source vertex to all other vertices, the algorithm uses a 
queue to store the vertices to be visited next. The distance to each vertex is initialized to 
infinity except for the source vertex, which is set to zero.

As the algorithm explores the graph, it updates the distance of each adjacent vertex to the 
source vertex if the distance is smaller than the current distance. This ensures that the 
algorithm finds the shortest path to each vertex from the source vertex.

The algorithm terminates when all vertices have been visited, and the final distances to 
all vertices are the shortest paths from the source vertex to each vertex in the graph.
*/

class Graph
{
	int m_vertices;
	int m_edges;
	map<int, list<int>> l;

public:
	Graph(int v, int e) : m_vertices(v), m_edges(e) {}
	void addEdge(int src, int dst, int bidir=true)
	{
		l[src].push_back(dst);
		if (bidir) l[dst].push_back(src);
	}

	void print()
	{
		for (auto vertex : l)
		{
			cout << vertex.first << " : ";
			for (auto nbr : vertex.second)
				cout << nbr << " ";
			cout << endl;
		}
	}

	void ssspBFS(int src)
	{
		// All vertices are initial at infinite distance
		vector<int> dist(m_vertices + 1, INT_MAX);
		queue<int> q;

		dist[src] = 0;
		q.push(src);

		while (!q.empty())
		{
			auto front = q.front();
			q.pop();

			for (auto nbr : l[front])
			{
				// if node not visited
				if (dist[nbr] == INT_MAX)
				{
					q.push(nbr);
					dist[nbr] = dist[front] + 1;
				}
			}
		}

		// print all the distance
		for (auto vertex : l)
		{
			cout << "Distance of " << vertex.first << " is " << dist[vertex.first] << endl;
		}
	}
};

int main()
{
	Graph G(6, 6);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(2, 3);
	G.addEdge(1, 3);
	G.addEdge(3, 4);
	G.addEdge(4, 5);

	G.ssspBFS(0);

	return 0;
}