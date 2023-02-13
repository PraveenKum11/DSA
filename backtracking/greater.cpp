#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
	int ans = 1;
	for (int i = 2; i <= n; i++)
		ans *= i;
	return ans;
}

// Can optimize a lot :
// 1. use pre-computed factorial array
// 2. avoid calculating the freq every time

// for repeating digits
int getGreaterRepeating(vector<int> vec, int n, int si, int ei)
{
	if (si >= ei) return 0;

	int count = 0;
	vector<int> freqCount(10, 0);
	for (int i = si; i <= ei; i++)
		freqCount[vec[i]]++;
	for (int i = si; i <= ei; i++)
		if (vec[i] > vec[si])
			count += fact(n - 1);
	for (int i = 0; i < 9; i++)
		if (freqCount[i] > 1)
			count /= freqCount[i];
	int smallAns = getGreaterRepeating(vec, n - 1, si + 1, ei);
	return smallAns + count;
}

// for distinct digits
int getGreater(vector<int> vec, int n, int si, int ei)
{
	if (si >= ei) return 0;

	int count = 0;
	for (int i = si; i <= ei; i++)
		if (vec[i] > vec[si])
			count += fact(n - 1);
	int smallAns = getGreater(vec, n - 1, si + 1, ei);
	return smallAns + count;
}

int main()
{
	int n; cin >> n;
	vector<int> vec;
	while (n)
	{
		vec.push_back(n % 10);
		n /= 10;
	}
	int i = 0, j = vec.size() - 1;
	while (i < j) swap(vec[i++], vec[j--]);
	cout << getGreaterRepeating(vec, vec.size(), 0, vec.size() - 1);
}