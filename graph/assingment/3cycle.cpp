#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, e; cin >> n >> e;
	int **edges = new int*[n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
			edges[i][j] = 0;
	}

	for (int i = 0; i < e; i++)
	{
		int v1, v2; cin >> v1 >> v2;
		edges[v1][v2] = 1;
		edges[v2][v1] = 1;
	}

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;

	int count = 0;
	// iteratively loop -- iRj , jRk => iRk
	for (int i = 0; i < n; i++)
	{
		visited[i] = true;
		for (int j = 0; j < n; j++)
		{
			if (edges[i][j] && !visited[j])		// iRj
			{
				for (int k = 0; k < n; k++)
				{
					if (k == i) continue;
					if (edges[j][k] && !visited[k])		// jRk
					{
						if (edges[i][k])		// iRk
							count++;
					}
				}
			}
		}
	}
	cout << count;
}



// solution using adjacency list
#if 0

#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, vector <int> u, vector <int> v)

{
    unordered_map <int, unordered_set<int>> adj;
    for (int i = 0; i < m; i++) {
        adj[u[i]].insert(v[i]);
        adj[v[i]].insert(u[i]);
    }
    int thcycle = 0;
    for (int i = 1; i <= n; i++) {
        int node = i;
        for (int p = 1; p < n; p++) {
            for (int q = p + 1; q <= n; q++) {
                if (adj[node].count(p) == 0)
                    break;
                if (adj[node].count(q) == 0)
                    continue;
                if (adj[node].count(p) && adj[node].count(q)) {
                    if (adj[p].count(q))
                        thcycle++;
                }
            }
        }
    }
    return thcycle / 3;
}
#endif