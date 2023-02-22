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

class Graph
{
	int V;
	// list<int> *l;
	vector<list<int>> l;

public:
	Graph(int v)
	{
		this->V = v;
		l.resize(v);
		// l = new list<int>[v];
	}
	~Graph()
	{
		// delete l;
	}

	void addEdge(int src, int dst)
	{
		l[src].push_back(dst);
		l[dst].push_back(src);
	}

	void printAdjList()
	{
		for (int i = 0; i < V; i++)
		{
			cout << "Vertex " << i << "->";
			for (auto x : l[i])
				cout << x << ",";
			cout << endl;
		}
	}
};

void solve()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);

	g.printAdjList();

	/*
	Vertex 0->1,2,
	Vertex 1->0,2,
	Vertex 2->0,1,3,
	Vertex 3->2,
	*/
}

int32_t main()
{
	// fastio();
	// int t; cin >> t;
	// while (t--)
	solve();
}