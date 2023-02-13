#include <bits/stdc++.h>
using namespace std;

bool helper(char **matrix, int n, int m, int i, int j, bool **visited, string str)
{
	// cout << str << endl;
	if (str.size() == 0) return true;
	visited[i][j] = true;
	vector<pair<int, int>> options = \
	{
		{i + 1, j + 1},
		{i + 1, j},
		{i + 1, j - 1},
		{i - 1, j + 1},
		{i - 1, j},
		{i - 1, j - 1},
		{i, j - 1},
		{i, j + 1}};

	bool smallAns;
	for (int i = 0; i < 8; i++)
	{
		// is the x coordinate valid
		bool c1 = (0 <= options[i].first && options[i].first < n);
		// is the y coordinate valid
		bool c2 = (0 <= options[i].second && options[i].second < m);
		if (c1 && c2)
		{
			// cout << options[i].first << " " << options[i].second << endl;
			// the option in not visited
			bool c3 = !visited[options[i].first][options[i].second];
			// cout << c3 << endl;
			// the option is the required option
			bool c4 = (matrix[options[i].first][options[i].second] == str[0]);
			// cout << c4 << endl;
			// cout << "-------" << endl	;

			if (c3 && c4)
			{
				// cout << options[i].first << " " << options[i].second << endl;
				smallAns = helper(matrix, n, m, options[i].first, options[i].second, visited, str.substr(1));
			}
		}
	}
	if (smallAns)
		return true;
	visited[i][j] = false;
	return false;
}

bool hasCN(char **matrix, int n, int m)
{
	string str = "ODINGNINJA";
	bool **visited = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
	}
	bool ans = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == 'C')
			{
				visited[i][j] = true; // for first C encounterd
				ans = helper(matrix, n, m, i, j, visited, str);
			}
			if (ans) return true;
		}
	}
	return ans;
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

	cout << boolalpha << hasCN(matrix, n, m);


	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < m; j++)
	// 		cout << (char)matrix[i][j] << " ";
	// clearing up memory
	for (int i = 0; i < n; i++)
		delete [] matrix[i];
	delete [] matrix;
}