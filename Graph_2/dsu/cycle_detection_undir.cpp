#include <bits/stdc++.h>
using namespace std;

/*
NOTE:
	DSU can be used to detect cycle when we try to union
	two already nodes from the same set.
*/

class UnionFind {
	vector<int> parent;
public:
	UnionFind (int size)
	{
		parent.resize(size);
		for (int i = 0; i < size; i++)
			parent[i] = i; 				// initially each element is it's own parent
	}

	void print()
	{
		for (auto i : parent)
			cout << i << " ";
		cout << endl;
	}

	// Find the root/leader of a set from a given element
	int find(int x)
	{
		if (parent[x] == x)
			return x;
		return find(parent[x]);
	}

	// Union two sets, given elements of sets
	void unionSet(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);

		if (rootX == rootY)
		{
			// already in the same set
			cout << "Cycle Found" << endl;
			return;
		}

		// make one the parent of other || join the two trees
		parent[rootX] = rootY;
	}
};


int main()
{
	// Graph in for of edge list
	int v, e;
	v = 4, e = 4;
	vector<pair<int, int>> edgeList;
	edgeList.push_back({1, 2});
	edgeList.push_back({2, 3});
	edgeList.push_back({3, 4});
	edgeList.push_back({4, 1});

	UnionFind dsu(v);
	for (auto [src, dst] : edgeList)
	{
		dsu.unionSet(src, dst);
	}

	return 0;
}