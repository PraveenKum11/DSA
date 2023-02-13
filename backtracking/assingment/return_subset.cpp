#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> returnSubset(int *arr, int n)
{
	if (n <= 0) return {{}};
	vector<vector<int>> smallAns = returnSubset(arr + 1, n - 1);
	int len = smallAns.size();
	for (int i = 0; i < len; i++)
		smallAns.push_back(smallAns[i]);
	for (int i = 0; i < len; i++)
		smallAns[i].push_back(arr[0]);
	return smallAns;
}

int main()
{
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<vector<int>> ans = returnSubset(arr, n);
	for (auto i : ans)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
}