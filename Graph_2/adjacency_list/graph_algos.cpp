#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{

	// GRAPH STRUCTURE AND INTERNAL IMPLEMENTATION
public:
	unordered_map<T, list<T>> l;

	void addEdge(T src, T dst)
	{
		l[src].push_back(dst);
		l[dst].push_back(src);
	}

	void printAdjList()
	{
		for (auto [k, v] : l)
		{
			cout << k << " : ";
			for (auto i : v) cout << i << ", ";
			cout << endl;
		}
	}

	// BFS TRAVERSAL
	void bfs(T src)
	{
		unordered_map<T, bool> visited;
		visited[src] = true;
		queue<T> q;
		q.push(src);

		while (!q.empty())
		{
			T front = q.front();
			cout << front << " ";
			q.pop();
			for (auto nbr : l[front])
			{
				if (!visited[nbr])
				{
					visited[nbr] = true;
					q.push(nbr);
				}
			}
		}
	}

	// SINGLE SOURCE SHORTEST PATH USING BFS
	int bfsSSSP(T src, T dst)
	{
		unordered_map<T, int> dist;
		for (auto [k, v] : l) dist[k] = INT_MAX;
		dist[src] = 0;
		queue<T> q;
		q.push(src);

		while (!q.empty())
		{
			T front = q.front();
			q.pop();
			for (auto nbr : l[front])
			{
				if (dist[nbr] == INT_MAX)
				{
					dist[nbr] = dist[front] + 1;
					q.push(nbr);
				}
			}
		}
		return dist[dst];
	}

	// DFS WITH IT'S HELPER FUNCTION
private:
	void dfsHelper(T src, unordered_map<T, bool> &visited)
	{
		cout << src << " ";
		visited[src] = true;
		for (auto nbr : l[src])
		{
			if (!visited[nbr])
				dfsHelper(nbr, visited);
		}
	}
public:
	void dfs(T src)
	{
		unordered_map<T, bool> visited;
		dfsHelper(src, visited);
		cout << endl;
	}

	// CONNECTED COMPONENTS WITH DFS
	void dfs()
	{
		int cnt = 0;
		unordered_map<T, bool> visited;

		for (auto [node, nbr] : l)
		{
			if (!visited[node])
			{
				cout << "Component " << cnt << " : ";
				dfsHelper(node, visited);
				cnt++;
				cout << endl;
			}
		}
	}
};

int main()
{
	Graph<int> g;
	// g.addEdge(0, 1);
	// g.addEdge(0, 3);
	// g.addEdge(1, 2);
	// g.addEdge(2, 3);
	// g.addEdge(3, 4);
	// g.addEdge(4, 5);

	// g.bfs(0);
	// cout << g.bfsSSSP(0, 5) << endl;
	// g.dfs(0);


	// For connected components
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);


	g.addEdge(5, 6);
	g.addEdge(6, 7);

	g.addEdge(8, 8);

	g.dfs();
}