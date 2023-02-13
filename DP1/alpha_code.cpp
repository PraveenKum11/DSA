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

// with memorization
int getCodeCount(string num, int *arr)
{
	// for a 0 size code empty string is one possible answer
	if (num.size() == 0) return 1;
	else if (num.size() == 1)
	{
		if (num[0] - '0' > 0) return 1;
	}
	if (arr[num.size()] > 0) return arr[num.size()];
	int tens = num[0] - '0';
	int ones = num[1] - '0';
	int smallAns = 0;
	if ((tens * 10 + ones) <= 26)
		smallAns += getCodeCount(num.substr(2), arr);
	if (ones > 0)
		smallAns += getCodeCount(num.substr(1), arr);
	arr[num.size()] = smallAns;
	return smallAns;
}

// using array version
int numCodes(int *n, int size)
{
	if (size == 1) return 1;
	if (size == 0) return 1;
	int output = 0;
	if (n[size - 1] > 0)
		output += numCodes(n, size - 1);
	if (n[size - 2] * 10 + n[size - 1] <= 26)
		output += numCodes(n, size - 2);
	return output;
}

int getCodeCountIter(string str)
{
	int dp[str.size() + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = dp[1] = 1;

	for (int i = 2; i < str.size() + 1; i++)
	{
		if (str[i - 1] > 0)
			dp[i] = dp[i - 1];
		if ((str[i - 2] - '0') * 10 + (str[i - 1] - '0') <= 26)
			dp[i] += dp[i - 2];
	}
	return dp[str.size()];
}

int main()
{
	string num; cin >> num;
	cout << getCodeCountIter(num);
	// int arr[num.size() + 1];
	// memset(arr, 0, sizeof(arr));
	// cout << getCodeCount(num, arr);
	// int n; cin >> n;
	// int *arr = new int[n];
	// for (int i = 0; i < n; i++)
	// {
	// 	int t; cin >> t;
	// 	arr[i] = t;
	// }
	// cout << numCodes(arr, n);
}