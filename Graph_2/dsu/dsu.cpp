#include <bits/stdc++.h>
using namespace std;

/*
NOTE:
	Union-Find is a data structure used for efficiently managing disjoint 
	sets or partitions of elements. It provides two main operations: 
	union, which combines two sets into one, and find, which determines 
	the representative or leader of a set to which an element belongs. 
	Union-Find is also known as disjoint-set data structure.
*/

/*
OPTIMIZAITONS 

NOTE: Complexity Analysis
	== >> No optimizaion : Union - O(N) ; Find - O(N)
	Case of skewed tree

	==>> Path Compression: Union - O(logN) ; Find - O(logN) => On Average

	Path compression is applied during the "find" operation in DSU. 
	The goal of path compression is to optimize the performance of "find" 
	operation by flattening the tree-like structure that represents the subsets, 
	which can become deep and unbalanced over time. Path compression compresses 
	the paths from the nodes to the root of the tree, by making each node 
	directly point to the root, effectively reducing the height of the tree.

	When the "find" operation is called on a node, it traverses the path from 
	the node to the root of the tree by following the parent pointers. 
	During this traversal, path compression is applied by updating the parent 
	pointers of intermediate nodes to directly point to the root. This way, 
	subsequent "find" operations on the same or related nodes will have a shorter 
	path to traverse, resulting in improved amortized time complexity for "find" operation in DSU.

	==>> Union By Rank : Union - O(1) ; Find - O(1) => On Average

	Union by rank is an optimization technique used in the Union-Find (Disjoint Set)
	data structure to improve the performance of the union operation. 
	In a standard implementation of Union-Find, when two sets are merged (unioned), 
	one of the sets is arbitrarily chosen as the parent, and the other set is made 
	a child of the chosen parent. However, this simple approach can lead to 
	performance issues, specifically in scenarios where there are many operations 
	involving union, and the trees become unbalanced.

	Union by rank aims to balance the trees in the Union-Find data structure 
	by considering the height (rank) of the trees. The rank of a tree is an 
	upper bound on its height, which is the longest path from the root to any leaf. 
	The basic idea of the union by rank optimization is to always attach the 
	smaller tree (i.e., the tree with the smaller rank) to the root of the larger 
	tree during the union operation. This ensures that the height of the resulting 
	tree remains balanced, and the worst-case time complexity of the union operation is reduced.

*/


class UnionFind {
	vector<int> parent; 	// parent of each node
	vector<int> rank;		// rank (size) of each component
public:
	UnionFind (int size)
	{
		parent.resize(size);
		for (int i = 0; i < size; i++)
		{
			parent[i] = i; 				// initially each element as it's own parent
			rank[i] = 1;				// initailly each component is of size/rank 1
		}
	}

	// Find the root/leader of a set from a given element
	int find(int x)
	{
		if (parent[x] == x)
			return x;
		// path compression - each node is directly connected to parent
		return parent[x] = find(parent[x]);	
	}

	// Union two sets, given elements of sets
	void unionSet(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);

		if (rootX == rootY)
		{
			// already in the same set
			return;
		}

		// make one the parent of other || join the two trees
		// parent[rootX] = rootY;

		// Union by rank optimization
		if (rank[rootX] < rank[rootY])
		{
			parent[rootX] = rootY;
			rank[rootY] += rank[rootX];
		}
		else
		{
			parent[rootY] = rootX;
			rank[rootX] += rank[rootY];
		}
	}
};


int main()
{
	UnionFind dsu(5);
	return 0;
}