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

int countSteps(int n, int currSteps)
{
	if (currSteps > n) return 0;
	if (currSteps == n) return 1;
	int smallAns1 = countSteps(n, currSteps + 1);
	int smallAns2 = countSteps(n, currSteps + 2);
	int smallAns3 = countSteps(n, currSteps + 3);
	return smallAns1 + smallAns2 + smallAns3;
}

// Note : the mistake i did in my orignal solution was to add 1 + sA1 + sA2 + sa2 in all cases
//		  which assumes that the first step on n size is a valid move which is not the case when
//		  when considering n > 3 because n = 4 is not a valid move but it still would have contributed
//		  1 to the final answer which makes ans from 7 to 8. Similarly, in case of 5 we are adding
//		  2 extra moves for n = 4 and n = 5 which makes answer from 13 to 15.
int countStepsVar1(int n)
{
	if (n <= 0) return 0;
	int smallAns1 = countStepsOrig(n - 1);
	int smallAns2 = countStepsOrig(n - 2);
	int smallAns3 = countStepsOrig(n - 3);
	if (n <= 3)
		return 1 + smallAns1 + smallAns2 + smallAns3;
	return smallAns1 + smallAns2 + smallAns3;
}

int countStepsVar2(int n)		// another variation
{
	if (n < 0) return 0;		// if is n < 0 it is a invalid move and contributes nothing.
	if (n == 0) return 1;	
	// for 0 -> { [0] }
	// if n becomes 0 it is a valid move and contributes one to the final answer.

	int smallAns1 = countStepsOrig(n - 1);
	int smallAns2 = countStepsOrig(n - 2);
	int smallAns3 = countStepsOrig(n - 3);
	return smallAns1 + smallAns2 + smallAns3;
}
	
int main()
{
	fastio();
	int n; cin >> n;
	int currSteps = 0;
	// cout << countSteps(n, currSteps);
	// cout << countStepsVar1(n);
}