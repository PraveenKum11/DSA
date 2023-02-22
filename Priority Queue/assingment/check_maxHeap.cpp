#include <bits/stdc++.h>
using namespace std;

bool checkMaxHeap(vector<int> vec, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		int pi = (i - 1) / 2;
		if (vec[i] > vec[pi]) return false;
	}
	return true;
}

int main()
{
	int n; cin >> n;
	vector<int> vec(n);
	for (auto &it : vec) cin >> it;
	cout << boolalpha << checkMaxHeap(vec, n);
}