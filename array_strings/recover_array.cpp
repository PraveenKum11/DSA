#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x) std::cerr << #x <<" "; _print(x); std::cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {std::cerr << t;}
void _print(int t) {std::cerr << t;}
void _print(std::string t) {std::cerr << t;}
void _print(char t) {std::cerr << t;}
void _print(lld t) {std::cerr << t;}
void _print(double t) {std::cerr << t;}
void _print(ull t) {std::cerr << t;}
template <class T, class V> void _print(std::pair <T, V> p);
template <class T> void _print(std::vector <T> v);
template <class T> void _print(std::set <T> v);
template <class T, class V> void _print(std::map <T, V> v);
template <class T> void _print(std::multiset <T> v);
template <class T, class V> void _print(std::pair <T, V> p) {std::cerr << "{"; _print(p.ff); std::cerr << ","; _print(p.ss); std::cerr << "}";}
template <class T> void _print(std::vector <T> v) {std::cerr << "[ "; for (T i : v) {_print(i); std::cerr << " ";} std::cerr << "]";}
template <class T> void _print(std::set <T> v) {std::cerr << "[ "; for (T i : v) {_print(i); std::cerr << " ";} std::cerr << "]";}
template <class T> void _print(std::multiset <T> v) {std::cerr << "[ "; for (T i : v) {_print(i); std::cerr << " ";} std::cerr << "]";}
template <class T, class V> void _print(std::map <T, V> v) {std::cerr << "[ "; for (auto i : v) {_print(i); std::cerr << " ";} std::cerr << "]";}
/*========================================================================================================================================================*/

void solve()
{
	int n; cin >> n;
	vi vec(n);
	for (auto &it : vec) cin >> it;
	vi output(n);

	int left, right;
	int mid = n / 2;
	int i = 0;
	if (n & 1)
	{
		output[mid] = vec[i];
		left = mid - 1;
		right = mid + 1;
		i++;
	}
	else
	{
		left = mid - 1;
		right = mid;
	}

	while (i < n)
	{
		output[left] = vec[i];
		left--, i++;
		output[right] = vec[i];
		right++, i++;
	}

	// output
	for (auto i : output) cout << i << " ";
	cout << endl;
}

int main()
{
	fastio();
	int t;
	cin >> t;
	while (t--)
		solve();
}