#include <bits/stdc++.h>
using namespace std;

int fibo1(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return fibo1(n - 1) + fibo1(n - 2);
}

// recursive DP
int fibo2(int n, int *arr)
{
	if (n == 0 || n == 1)
		return 1;
	if (arr[n] > 0) return arr[n];
	int output = fibo2(n - 1, arr) + fibo2(n - 2, arr);
	arr[n] = output;
	return output;
}

// iterative DP
int fibo3(int n)
{
	int arr[n + 1];
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < n + 1; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	return arr[n];
}

int main()
{
	int n; cin >> n;
	int *arr = new int[n + 1];
	for (int i = 0; i < n + 1; i++) arr[i] = 0;
	// cout << fibo2(n, arr);
	cout << fibo3(n);
}