#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int source;
	int destination;
	int weight;
};

// recursive function to find parent
int findParent(int child, int *parents)
{
	if (child == parents[child])
		return child;
	return findParent(parents[child], parents);
}

void kruskals(Edge *edgeList, int e, int n)
{
	sort (edgeList, edgeList + e, [](Edge A, Edge B) { return A.weight < B.weight; });
	Edge output[n - 1];
	int *parents = new int[n];
	for (int i = 0; i < n; i++) parents[i] = i;

	// Union find
	int k = 0;
	for (int i = 0; i < e; i++)
	{
		int pSource = findParent(edgeList[i].source, parents);
		int pDestination = findParent(edgeList[i].destination, parents);

		if (pSource != pDestination)
		{
			output[k++] = edgeList[i];
			parents[edgeList[i].source] = edgeList[i].destination;
		}
		if (k > n - 1) break;
	}

	// print the output
	for (int i = 0; i < n - 1; i++)
	{
		if (output[i].source < output[i].destination)
			cout << output[i].source << " " \
			<< output[i].destination << " " \
			<< output[i].weight << endl;
		else
			cout << output[i].destination << " " \
			<< output[i].source << " " \
			<< output[i].weight << endl;
	}
}

int main()
{
	int n, e; cin >> n >> e;
	Edge *edgeList = new Edge[e];
	for (int i = 0; i < e; i++)
	{
		int src, dst, wght;
		cin >> src >> dst >> wght;
		edgeList[i].source = src;
		edgeList[i].destination = dst;
		edgeList[i].weight = wght;
	}

	kruskals(edgeList, e, n);
}