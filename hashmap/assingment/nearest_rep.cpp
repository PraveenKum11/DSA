#include <bits/stdc++.h>
using namespace std;

int nearestRepetition(vector<int> vec, int n)
{
	unordered_map<int, int> ump;
	int minDist = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (ump.count(vec[i]))
			minDist = min(minDist, i - vec[i] + 1);
		ump[vec[i]] = i;
	}
	return minDist;
}

int main()
{
	int n; cin >> n;
	vector<int> vec(n);
	for (auto &it : vec) cin >> it;
	cout << nearestRepetition(vec, n);
}