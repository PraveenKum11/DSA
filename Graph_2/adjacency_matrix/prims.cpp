#include <bits/stdc++.h>
using namespace std;

void prims(int **edge, int n, int e)
{
	bool visited[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	int parents[n];
	for (int i = 0; i < n; i++) parents[i] = -1;
	int weight[n]; weight[0] = 0;
	for (int i = 1; i < n; i++) weight[i] = INT_MAX;

	for (int k = 0; k < n; k++)
	{
		// find the minimum weight and idx
		int minWeightVertex, minWeight = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && weight[i] < minWeight)
			{
				minWeight = weight[i];
				minWeightVertex = i;
			}
		}

		visited[minWeightVertex] = true;
		// push the weight from the selected vertex
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && edge[minWeightVertex][j])
			{
				if (weight[j] > edge[minWeightVertex][j])
				{
					weight[j] = edge[minWeightVertex][j];
					parents[j] = minWeightVertex;
				}
			}
		}
	}
	// NOTE : not working for the smaple input

	// print the MST which is in the parent array
	// print first the smaller vertex
	cout << "MST" << endl;
	for (int i = 1; i < n; i++)
	{
		if (i < parents[i])
			cout << i << " " << parents[i] << " " << weight[i] << endl;
		else
			cout << parents[i] << " " << i << " " << weight[i] << endl;
	}
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

	prims(edge, n, e);
}