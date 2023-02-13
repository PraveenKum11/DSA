#include <bits/stdc++.h>
using namespace std;


void travelDFS(int **edges, int n, int sv, bool *visited)
{
	visited[sv] = true;
	for (int i = 0; i < n; i++)
		if (!visited[i] && edges[sv][i])
			travelDFS(edges, n, i, visited);
}

int countComponets(int **edges, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			count++;
			travelDFS(edges, n, i, visited);
		}
	}
	return count;
}


int main()
{
	int n, e; cin >> n >> e;
	int **edges = new int*[n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
			edges[i][j] = 0;
	}

	for (int i = 0; i < e; i++)
	{
		int v1, v2; cin >> v1 >> v2;
		edges[v1][v2] = 1;
		edges[v2 ][v1] = 1;
	}

	cout << countComponets(edges, n);
}