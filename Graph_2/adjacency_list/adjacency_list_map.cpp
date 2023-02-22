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

// Use template to make it of generic type
// See traversal for generic implementation
class Graph
{
	unordered_map<string, list<pair<string, int>>> l;

public:
	void addEdge(string src, string dst, bool bidir, int wt)
	{
		l[src].push_back({dst, wt});
		if (bidir) l[dst].push_back({src, wt});
	}

	void printAdjList()
	{
		for (auto v : l)
		{
			cout << "Vertex " << v.first << "->";
			for (auto i : v.second) cout << i << ",";
			cout << endl;
		}
	}
};

void solve()
{
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", false, 50);

	g.printAdjList();

	/* OUTPUT 
	Vertex B->(A, 20),(D, 40),
	Vertex C->(A, 10),(D, 40),
	Vertex D->(B, 40),(C, 40),
	Vertex A->(B, 20),(C, 10),(D, 50),
	*/
}

int32_t main()
{
	// fastio();
	// int t; cin >> t;
	// while (t--)
	solve();
}