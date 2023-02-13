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

void getCodes(string str, string result, vector<string> &output)
{
	if (str.size() == 0)
	{
		output.pb(result);
		return;
	}
	char val = str[0] - '0' + 96;
	getCodes(str.substr(1), result + val, output);

	if (str.size() > 1)
	{
		int val = (str[0] - '0') * 10 + (str[1] - '0');
		if (val > 0 && val < 27)
			getCodes(str.substr(2), result + (char)(val + 96), output);
	}
}

int main()
{
	string str; cin >> str;
	vector<string> output;
	string result = "";
	getCodes(str, result, output);
	REP(i, output.size()) cout << output[i] << endl;
}