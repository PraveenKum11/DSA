#include <bits/stdc++.h>
using namespace std;

// NOTE: Cycle is present if we can reach a already visited node again and that node is
//		 note equal to the parent of that node.

template <typename T>
class Graph
{
public:
	unordered_map<T, list<T>> l;

	void addEdge(T src, T dst, bool bidir)
	{
		l[src].push_back(dst);
		if (bidir) l[dst].push_back(src);
	}

	void printGraph()
	{
		for (auto [v, nbrs] : l)
		{
			cout << v << ": ";
			for (auto nbr : nbrs)
			{
				cout << nbr << ", ";
			}
			cout << endl;
		}
	}

	bool isCycleHelper(T src, vector<bool>& visited, T parent)
	{
		visited[src] = true;
		for (auto nbr : l[src])
		{
			if (visited[nbr] && nbr != parent)
				return true;
			if (!visited[nbr])
				if (isCycleHelper(nbr, visited, src))
					return true;
		}
		return false;
	}

	bool isCycle(T src)
	{
		vector<bool> visited(l.size(), false);
		return isCycleHelper(src, visited, -1);
	}
};

int main()
{
	Graph<int> G;
	G.addEdge(0, 1, true);
	G.addEdge(1, 2, true);
	G.addEdge(2, 3, true);
	G.addEdge(3, 4, true);
	G.addEdge(4, 1, true);

	// G.printGraph();

	cout << (G.isCycle(0) ? "YES" : "NO") << endl;
	return 0;
}