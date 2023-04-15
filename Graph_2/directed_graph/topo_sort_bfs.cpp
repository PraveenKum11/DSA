#include <bits/stdc++.h>
#include <debugging.h>
using namespace std;

// NOTE: Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering 
//		 of vertices such that for every directed edge u v, vertex u comes before v 
//		 in the ordering.

class Graph
{
	map<int, list<int>> l;
	int m_size;

public:
	Graph(int size) : m_size(size) {}

	void addEdge(int src, int dst, bool bidir=false)
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

//  NOTE: Count the IN-DEGREE of the nodes, the nodes with 0 indegree will be added
//		  to the queue, then poped and printed and their nbr nodes indegree will be 
//		  also reduced and added to queue if their indegree also becomes zero.
	void topologicalSort()
	{
		// Initialize indegree vector with 0
		vector<int> indegree(m_size + 1, 0);

		// update all indegrees
		for (auto [v, nbrs] : l)
		{
			for (auto nbr : nbrs)
				indegree[nbr]++;
		}

		// push the nodes with indegree 0
		// in the queue (i.e. they can be printed)
		queue<int> q;
		for (size_t i = 1; i < indegree.size(); i++)
		{
			if (indegree[i] == 0) q.push(i);
		}

		// print/complete the queue nodes and reduce
		// their nbr node indegree by 1 and if their indegree
		// becomes zero add them to queue. repeat until queue is empty
		while (!q.empty())
		{
			int front = q.front();
			q.pop();
			cout << front << " ";

			for (auto nbr : l[front])
			{
				indegree[nbr]--;
				if (indegree[nbr] == 0) q.push(nbr);
			}
		}
	}
};

int main()
{
	Graph G(6);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.addEdge(6, 3);
	G.addEdge(5, 6);
	G.addEdge(4, 5);
	G.addEdge(1, 4);
	// G.print();

	G.topologicalSort();
	// result => 1 2 4 5 6 3 

	return 0;
}

/*

	12		23
	  \		/
	   V   V
	  	 5

to complete 5, we first need to finish 12 and 23, therefore topo order -> 12 23 5

*/