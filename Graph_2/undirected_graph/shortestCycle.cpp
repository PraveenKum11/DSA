#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	map<int, list<int>> l;

	void addEdge(int src, int dst, bool bidir=true)
	{
		l[src].push_back(dst);
		if (bidir) l[dst].push_back(src);
	}

	void print()
	{
		for (auto [v, nbrs] : l)
		{
			cout << v << " : ";
			for (auto nbr : nbrs)
			{
				cout << nbr << " ";
			}
			cout << endl;
		}
	}

//  NOTE: Since, this function used edge distance to find the length of the
//		  shortest cycle, therefore the src node needs to be present in the
//		  cycle to find the correct length, otherwise it will also count the
//		  the distance/edges to reach the cycle.
	void shortestCycleUtil(int src, vector<int>& dist, int& ans)
	{
		queue<int> q;
		q.push(src);

		while (!q.empty())
		{
			int front = q.front();
			q.pop();

			for (auto nbr : l[front])
			{
				if (dist[nbr] == INT_MAX) 	// not visited
				{
					q.push(nbr);
					dist[nbr] = dist[front] + 1;
				}
				// This is used to avoid parent, as the distance of parent node
				// will always be less than the distance of child node in BFS.
				else if (dist[nbr] >= dist[front])	// backedge found - cycle
				{
					ans = min(ans, dist[front] + dist[nbr] + 1);
				}
			}
		}
	}


//	NOTE:  To find the shortest cycle in the whole graph when no source
//		   is given we will find cycle from each node and take the min,
//		   because the node needs to be present in the cycle to get 
//		   correct ans.
	void shortestCycle()
	{
		// also acts as the visited array
		vector<int> dist(l.size(), INT_MAX);
		int ans = INT_MAX;

		int src = 1;
		dist[src] = 0;
		shortestCycleUtil(src, dist, ans);
		if (ans == INT_MAX)
			cout << "No Cycle Found" << endl;
		else
			cout << "Shortest Cycle : " << ans << endl;
	}
};

int main()
{
	Graph G;
	G.addEdge(1, 5);
	G.addEdge(1, 3);
	G.addEdge(1, 2);
	G.addEdge(5, 3);
	G.addEdge(3, 7);
	G.addEdge(2, 4);
	G.addEdge(3, 4);
	G.print();

	G.shortestCycle();

	return 0;
}