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
#define repr(i,n,k) for(int i=(n);(i)>=(int)(k);(i)--)
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
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
private:
	unordered_map<T, list<pair<T, int>>> l;

public:
	void addEdge(T src, T dst, bool bidir, int wt)
	{
		l[src].pb({dst, wt});
		if (bidir) l[dst].pb({src, wt});
	}

	void printAdjList()
	{
		for (auto [vertex, nbrs] : l)
		{
			cout << vertex << " -> ";
			for (auto [node, wt] : nbrs)
				cout << node << " " << wt << " , ";
			cout << endl;
		}
	}

	int bfs(T src, T dst)
	{
		vector<bool> visited(l.size() + 1, false);
		vector<int> dist(l.size() + 1, INT_MAX);
		dist[src] = 0;

		queue<T> q;
		q.push(src);
		visited[src] = true;

		while (!q.empty())
		{
			T front = q.front();
			q.pop();

			for (auto [nbr, nbr_wt] : l[front])
			{
				if (!visited[nbr])
				{
					q.push(nbr);
					visited[nbr] = true;
					dist[nbr] = min(dist[nbr], dist[front] + 1);
				}
			}
		}
		return dist[dst];
	}

	/*
	NOTE :  Dijkstra is exactly same as bfs the only changes are:
			1) We mark a node as visited when it gets pop-ed from the queue
			(instead of marking it visited the moment it is reached from
			any node -- done in bfs)
			2) We use priority queue instead of normal queue, as it will
			give the current node with least distance, and any other node
			will obviously give a larger distance at that moment.
	*/
	int dijkstras(T src, T dst)
	{
		vector<bool> visited(l.size() + 1, false);
		vector<int> dist(l.size() + 1, INT_MAX);
		dist[src] = 0;

		class compare
		{
		public:
			bool operator()(pi a, pi b)
			{
				return a.second > b.second;
			}
		};
		priority_queue<pi, vector<pi>, compare> q;
		q.push({src, 0});
		visited[src] = true;

		while (!q.empty())
		{
			pi front = q.top();
			q.pop();
			visited[front.first] = true;

			for (auto [nbr, nbr_wt] : l[front.first])
			{
				if (!visited[nbr])
				{
					q.push({nbr, front.second + nbr_wt});
					dist[nbr] = min(dist[nbr], front.second + nbr_wt);
				}
			}
		}
		return dist[dst];
	}
};

void solve()
{
	Graph<int> G;

	int v; cin >> v;
	while(v--)
	{
		int src, dst, wt;
		cin >> src >> dst >> wt;
		G.addEdge(src, dst, true, wt);
	}
	// G.printAdjList();
	// cout << G.bfs(1, 4) << endl;
	cout << G.dijkstras(1, 3) << endl;
}

int32_t main()
{
	// fastio();
	// int t; cin >> t;
	// while (t--)
	solve();
}