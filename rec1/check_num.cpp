#include <bits/stdc++.h>
using namespace std;

bool checkNum(int arr[], int n, int toFind)
{
	if (n == 0) return false;
	if (arr[0] == toFind) return true;
	return checkNum(arr + 1, n - 1, toFind);
}

int main()
{
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int toFind; cin >> toFind;
	cout << boolalpha << checkNum(arr, n, toFind);
}