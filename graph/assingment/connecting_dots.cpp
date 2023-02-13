#include <bits/stdc++.h>
using namespace std;

bool getCycle(char **matrix, int n, int m, int i, int j, pair<int, int> svc, int k, bool **visited)
{
	visited[i][j] = true;
	bool smallAns;
	vector<pair<int, int>> options = {
		{i, j + 1},
		{i + 1, j},
		{i, j - 1},
		{i - 1, j}
	};
	for (int x = 0; x < 4; x++)
	{
		// check is new coordinate is valid
		bool c1 = (0 <= options[x].first && options[x].first < n);
		bool c2 = (0 <= options[x].second && options[x].second < m);

		if (c1 && c2)
		{
			// check if the option has same letter
			bool c3 = (matrix[options[x].first][options[x].second] == matrix[i][j]);
			// check not visited
			bool c4 = (!visited[options[x].first][options[x].second]);
			// special case when we reach back to start and have covered more than 4 nodes
			bool c5 = (options[x].first == svc.first && options[x].second == svc.second && k >= 4);
			if (c5) smallAns = true;
			else if (c3 && c4)
				smallAns = getCycle(matrix, n, m, options[x].first, options[x].second, svc, k + 1, visited);
		}
	}
	if (smallAns) return true;
	else
	{
		visited[i][j] = false;
		return false;
	}
}

bool hasCycle(char **matrix, int n, int m)
{
	bool **visited = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
	}

	bool ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = true;
			pair<int, int> svc {i, j};
			ans = getCycle(matrix, n, m, i, j, svc, 1, visited); 
			if (ans) return true;
		}
	}
	return false;
}


int main()
{
	int n, m; cin >> n >> m;
	char **matrix = new char*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new char[m];
		for (int j = 0; j < m; j++)
		{
			char tmp; cin >> tmp;
			matrix[i][j] = tmp;
		}
	}

	cout << boolalpha << hasCycle(matrix, n, m);


	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		cout << (char)matrix[i][j];
	// 	cout << endl;
	// }
	// clearing up memory
	for (int i = 0; i < n; i++)
		delete [] matrix[i];
	delete [] matrix;
}