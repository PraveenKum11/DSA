#include <bits/stdc++.h>
using namespace std;

bool isZero(vector<int> &vec, int n)
{
	unordered_map<int, bool> seen;
	int preSum = 0;
	for (auto i : vec)
	{
		preSum += i;
		if (seen.count(preSum))
			return true;
		seen[preSum] = true;
	}
	return false;
}

int main()
{
	int n; cin >> n;
	vector<int> vec(n);
	for (auto &it : vec) cin >> it;
	cout << boolalpha << isZero(vec, n) << endl;
}