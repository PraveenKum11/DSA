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

// memorization
int getSteps(int n, int *arr)
{
	if (n == 1) return 0;
	if (arr[n] > 0) return arr[n];

	int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
	if (n % 3 == 0) ans1 = getSteps(n / 3, arr);
	if (n % 2 == 0) ans2 = getSteps(n / 2, arr);
	ans3 = getSteps(n - 1, arr);
	int output = 1 + min({ans3, ans2, ans1});
	arr[n] = output;
	return output;
}

int getStepsDP(int n)
{
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = dp[1] = 0;
	
	for (int i = 2; i < n + 1; i++)
	{
		int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
		if (i % 3 == 0) ans1 = dp[i / 3];
		if (i % 2 == 0) ans2 = dp[i / 2];
		ans3 = dp[i - 1];
		dp[i] = 1 + min({ans1, ans2, ans3});
	}
	return dp[n];
}

int main()
{
	int n; cin >> n;
	int *arr = new int[n + 1];
	for (int i = 0; i < n + 1; i++) arr[i] = 0;
	cout << getStepsDP(n);
}