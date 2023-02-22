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

template<typename T>
class Graph
{
	map<T, list<T>> l;

public:
	void addEdge(T src, T dst)
	{
		l[src].push_back(dst);
	}

	void printAdjList()
	{
		for (auto node : l)
		{
			cout << node.first << "-> ";
			for (auto nbr : node.second)
				cout << nbr << ",";
			cout << endl;
		}
	}

	int bfsSSSP(T src, T dst)
	{
		// to print the shortest path
		map<T, T> parent;

		map<T, int> dist;
		for (auto nodePair : l)
			dist[nodePair.first] = INT_MAX;
		dist[src] = 0;

		queue<int> q;
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
					parent[nbr] = front;
				}
			}
		}
		// Printing the shortest path
		T tmp = dst;
		while (tmp != src)
		{
			cout << tmp << "<-";
			tmp = parent[tmp];
		}
		cout << src << endl;
		// return the distance for destination
		return dist[dst];
	}
};

void solve()
{
	int jump[50] = {0};
	jump[2] = 13;
	jump[5] = 2;
	jump[9] = 18;
	jump[18] = 11;
	jump[17] = -13;
	jump[20] = -14;
	jump[24] = -8;
	jump[25] = 10;
	jump[32] = -2;
	jump[34] = -22;

	Graph<int> g;

	// for every board peice
	for (int i = 0; i <= 36; i++)
	{
		// for every possible dice throw
		for (int j = 1; j <= 6; j++)
		{
			int dest = i + j + jump[i + j];
			if (dest <= 36)
				g.addEdge(i, dest);
		}
	}
	g.addEdge(36, 36); // Needs to be added otherwise map will have no node(36)
	cout << g.bfsSSSP(0, 36) << endl;

	/* OUTPUT 
	36<-30<-29<-15<-0
	4
	*/
}

int32_t main()
{
	// fastio();
	// int t; cin >> t;
	// while (t--)
	solve();
}