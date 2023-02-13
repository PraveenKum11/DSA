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

void mergeSorted(int arr1[], int size1, int arr2[], int size2, int result[])
{
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2)
	{
		if (arr1[i] < arr2[j])
			result[k++] = arr1[i++];
		else
			result[k++] = arr2[j++];
	}
	while (i < size1) result[k++] = arr1[i++];
	while (j < size2) result[k++] = arr2[j++];
}

void mergeSort(int arr[], int si, int ei)
{
	if (si >= ei) return;
	int mid = si + (ei - si) / 2;
	int size1 = (mid - si) + 1;
	int size2 = (ei - mid);
	int arr1[size1], arr2[size2];
	for (int i = si; i < mid + 1; i++) arr1[i] = arr[i];
	for (int i = mid + 1; i < ei + 1; i++) arr2[i - mid - 1] = arr[i];
	mergeSort(arr1, 0, size1 - 1);
	mergeSort(arr2, 0, size2 - 1);
	mergeSorted(arr1, size1, arr2, size2, arr);
}

int main()
{
	fastio();
	int n; cin >> n;
	int arr[n];
	REP(i, n) cin >> arr[i];
	mergeSort(arr, 0, n - 1);
	REP(i, n) cout << arr[i] << " ";
}