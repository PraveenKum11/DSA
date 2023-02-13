#include <bits/stdc++.h>
using namespace std;

void printSubsetsK(int *arr, int n, int k, vector<int> ans)
{
	if (n == 0)
	{
		if (k == 0)
		{
			for (auto i : ans) cout << i << " ";
			cout << endl;
		}
		return;
	}
	vector<int> include = ans;
	include.push_back(arr[0]);
	printSubsetsK(arr + 1, n - 1, k - arr[0], include);
	printSubsetsK(arr + 1, n - 1, k, ans);
}

int main()
{
	int n, k; cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	printSubsetsK(arr, n, k, {});
}