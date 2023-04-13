#include <bits/stdc++.h>
using namespace std;

// NOTE: flood fill is mostly used with implicit graphs (2D matrix)

void floodFill(vector<vector<char>> &matrix, int i, int j, char src, char dst, int n, int m)
{
	// search space border check
	if (i < 0 || j < 0 || i >= n || j >= m) return;

	// figure boundary condition
	if (matrix[i][j] != src) return;

	// directions to move in
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, -1, 0, 1};

	// dfs in all directions
	matrix[i][j] = dst;
	for (int k = 0; k < 4; k++)
	{
		floodFill(matrix, i + dx[k], j + dy[k], src, dst, n, m);
	}
}

void printMatrix(vector<vector<char>> matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> matrix(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch; cin >> ch;
			matrix[i][j] = ch;
		}
	}

	// printMatrix(matrix, n, m);
	floodFill(matrix, 9, 8, '#', '$', n, m);
	printMatrix(matrix, n, m);
	return 0;
}
