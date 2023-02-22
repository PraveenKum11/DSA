#include <bits/stdc++.h>
using namespace std;

// shortest path to all vertices from the source vertex 0
void dijkstra(int **edge, int n, int e)
{
	bool visited[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	int weight[n]; // stores the least path weight from source
	for (int i = 0; i < n; i++) weight[i] = INT_MAX;
	weight[0] = 0;

	for (int k = 0; k < n; k++)
	{
		// get the vertex with minimum weight/distance
		int minWeightVertex = -1;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && (minWeightVertex == -1 || weight[i] < weight[minWeightVertex]))
				minWeightVertex = i;
		}
		visited[minWeightVertex] = true;

		// travese all the neighbours
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && edge[minWeightVertex][j])
			{
				if (weight[j] > weight[minWeightVertex] + edge[minWeightVertex][j])
					weight[j] = weight[minWeightVertex] + edge[minWeightVertex][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << i << " " << weight[i] << endl;
}

int main()
{
	int n, e; cin >> n >> e;
	int **edge = new int*[n];
	for (int i = 0; i < n; i++)
	{
		edge[i] = new int[n];
		for (int j = 0; j < n; j++)
			edge[i][j] = 0;
	}

	for (int i = 0; i < e; i++)
	{
		int v1, v2, w; cin >> v1 >> v2 >> w;
		edge[v1][v2] = w;
		edge[v2][v1] = w;
	}

	dijkstra(edge, n, e);
}