#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int source;
	int destination;
	int weight;
};

int main()
{
	int n, e; cin >> n >> e;
	Edge edgeList[e];
	Edge output[n - 1];
	for (int i = 0; i < e; i++)
	{
		int src, dst, wght;
		cin >> src >> dst >> wght;
		edgeList[i].source = src;
		edgeList[i].destination = dst;
		edgeList[i].weight = wght;
	}
	sort (edgeList, edgeList + e, [](Edge A, Edge B) { return A.weight < B.weight; });

	// Union Find
	int parent[n];
	for (int i = 0; i < n; i++) parent[i] = i;

	int j = 0;
	for (int i = 0; i < e; i++)
	{
		// get parents
		int src = edgeList[i].source;
		while (src != parent[src])
			src = parent[src];
		int dest = edgeList[i].destination;
		while (dest != parent[dest])
			dest = parent[dest];
		if (src != dest)	// comparing the upper-most parent
		{
			output[j++] = edgeList[i];
			parent[edgeList[i].destination] = edgeList[i].source;
		}
	}

	cout << "MST: " << endl;
	for (int i = 0; i < n - 1; i++)
		cout << output[i].source << " " \
		<< output[i].destination << " " \
		<< output[i].weight << endl;
}