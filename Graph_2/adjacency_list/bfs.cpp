#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include <debugging.h>
#endif
using namespace std;
#define int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i,k,n) for(int i=(k);(i)<(int)(n);(i)++)
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set; // find_by_order, order_of_key
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset; // {elem, id}
/*========================================================================================================================================================*/

template <typename T>
class Graph
{
	unordered_map<T, list<T>> l;

public:
	void addEdge(T src, T dst)
	{
		l[src].push_back(dst);
		l[dst].push_back(src);
	}

	void bfs(T src)
	{
		map<T, bool> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;
		while (!q.empty())
		{
			T front = q.front();
			q.pop();
			cout << front << " ";
			for (auto nbr : l[front])
			{
				if (!visited[nbr])
				{
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

	// sssp -> single source shortest path
	void bfsSSSP(T src)
	{
		map<T, int> dist;
		// make distance of all nodes INF, except of src
		// now the dist(child) = dist(parent) + 1
		for (auto nodePair : l)
			dist[nodePair.first] = INT_MAX;

		dist[src] = 0;
		queue<T> q;
		q.push(src);

		while (!q.empty())
		{
			T front = q.front();
			q.pop();

			for (auto nbr : l[front])
			{
				if (dist[nbr] == INT_MAX)
				{
					q.push(nbr);
					dist[nbr] = dist[front] + 1;
				}
			}
		}

		// print the shortest path from source to all nodes
		for (auto nodePair : dist)
		{
			cout << "Node " << nodePair.first << " Distance from src " << nodePair.second << endl;
		}
	}
};

void solve()
{
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.bfs(0);
	// OUTPUT : 0 1 3 2 4 5 

	g.bfsSSSP(0);
	/*
	Node 0 Distance from src 0
	Node 1 Distance from src 1
	Node 2 Distance from src 2
	Node 3 Distance from src 1
	Node 4 Distance from src 2
	Node 5 Distance from src 3
	*/
}

int32_t main()
{
	// fastio();
	// int t; cin >> t;
	// while (t--)
	solve();
}