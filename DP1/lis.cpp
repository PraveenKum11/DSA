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
/*========================================================================================================================================================*/

void printLis(int *arr, int n, vector<int> ans)
{
	if (n == 0)
	{
		for (auto i : ans) cout << i << " ";
		cout << endl;
		return;
	}
	if (ans.empty() || arr[0] > ans[ans.size() - 1])
	{
		vector<int> include = ans;
		include.pb(arr[0]);
		printLis(arr + 1, n - 1, include);
	}
	printLis(arr + 1, n - 1, ans);
}

int main()
{
	int n; cin >> n;
	vector<int> vec(n);
	for (auto &it : vec) cin >> it;
	printLis(vec.data(), n, {});
}