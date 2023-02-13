#include <bits/stdc++.h>
using namespace std;

int findLargest(int **cake, int n, int i, int j, bool** visited)
{
	visited[i][j] = true;
	vector<pair<int, int>> options = {
		{i, j + 1},
		{i + 1, j},
		{i, j - 1},
		{i - 1, j}
	};
	int smallAns = 0;
	for (int x = 0; x < n; x++)
	{
		// check the new coordinates are within bounds
		bool c1 = (0 <= options[x].first && options[x].first < n);
		bool c2 = (0 <= options[x].second && options[x].second < n);
		if (c1 && c2)
		{
			// coordinate should not be visited
			bool c3 = !visited[options[x].first][options[x].second];
			// next step shoud be towards 1
			bool c4 = (cake[options[x].first][options[x].second] == 1);
			if (c3 && c4)
				smallAns += findLargest(cake, n, options[x].first, options[x].second, visited);
		}
	}
	visited[i][j] = false;
	return smallAns + 1;
}

int getLargest(int **cake, int n)
{
	bool **visited = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[n];
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cake[i][j] == 1 && !visited[i][j])
				ans = max(ans, findLargest(cake, n, i, j, visited));
		}
	}
	return ans;
}

int main()
{
	int n; cin >> n;
	int **cake = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cake[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			int tmp; cin >> tmp;
			cake[i][j] = tmp;
		}
	}

	cout << getLargest(cake, n);
}