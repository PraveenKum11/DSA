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

void segregate(vector<int>& vec)
{
	int pivot = 0;	// points to the place where negative will come
	for (int i = 0; i < (int)vec.size(); i++)
	{
		if (vec[i] < 0) swap(vec[i], vec[pivot]);
		pivot++;
	}
}

void solve()
{
	int n; cin >> n;
	vector<int> vec(n);
	for (auto &it : vec) cin >> it;

	segregate(vec);
	cout << vec << endl;
}

int32_t main()
{
	// fastio();
	// int t; cin >> t;
	// while (t--)
	solve();
}