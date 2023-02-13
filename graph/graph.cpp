#include <bits/stdc++.h>
// #include <vector>
// #include <string>
// #include <iostream>
// #include <queue>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
	cout << sv << " ";
	visited[sv] = true;
	for (int i = 0; i < n; i++)
	{
		if (sv == i) continue;
		if (edges[sv][i] && !visited[i])
			printDFS(edges, n, i, visited);
	}
}

void printBFS(int **edges, int n, int sv, bool *visited)
{
	queue<int> pendingVer;
	pendingVer.push(sv);
	visited[sv] = true;
	while (!pendingVer.empty())
	{
		int front = pendingVer.front();
		pendingVer.pop();
		cout << front << " ";
		for (int i = 0; i < n; i++)
		{
			if (i == front) continue;
			if (!visited[i] && edges[front][i])
			{
				pendingVer.push(i);
				visited[i] = true;
			}
		}
	}
}

void DFS(int **edges, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;

	cout << "DFS: " << endl;
	for (int i = 0; i < n; i++)
		if (!visited[i])
			printDFS(edges, n, i, visited);

	delete [] visited;
	cout << endl;
}

void BFS(int **edges, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;

	cout << "BFS: " << endl;
	for (int i = 0; i < n; i++)
		if (!visited[i])
			printBFS(edges, n, i, visited);

	cout << endl;
}

bool hasPath(int **edges, int n, int sv, int ev, bool *visited)
{
	if (edges[sv][ev]) return true;
	visited[sv] = true;
	for (int i = 0; i < n; i++)
		if (!visited[i] && edges[sv][i])
			if (hasPath(edges, n, i, ev, visited)) return true;
	return false;
}

bool hasPathHelper(int **edges, int n, int sv, int ev)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	return hasPath(edges, n, sv, ev, visited);
}

bool getPathDFS(int **edges, int n, int sv, int ev, bool *visited, vector<int> &ans)
{
	if (sv == ev)
	{
		ans.push_back(ev);
		return true;
	}
	visited[sv] = true;
	bool foundPath = false;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && edges[sv][i])
			foundPath = getPathDFS(edges, n, i, ev, visited, ans);
		if (foundPath)
		{
			ans.push_back(sv);
			return true;
		}
	}
	return false;
}

void getPathHelperDFS(int **edges, int n, int sv, int ev)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	vector<int> ans;
	getPathDFS(edges, n, sv, ev, visited, ans);
	for (auto i : ans) cout << i << " ";
}

void getPathBFS(int **edges, int n, int sv, int ev, bool *visited, unordered_map<int, int> &parent)
{
	queue<int> pendingVer;
	pendingVer.push(sv);
	visited[sv] = true;
	while (!pendingVer.empty())
	{
		int front = pendingVer.front();
		pendingVer.pop();
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && edges[front][i])
			{
				pendingVer.push(i);
				parent[i] = front;
				visited[i] = true;
			}
			if (parent.count(ev)) return;
		}
	}
}

void getPathHelperBFS(int **edges, int n, int sv, int ev)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	unordered_map<int, int> parent;
	getPathBFS(edges, n, sv, ev, visited,parent);
	vector<int> ans;
	if (parent.count(ev))
	{
		int curr = ev;
		ans.push_back(ev);
		while (parent.count(curr))
		{
			ans.push_back(parent[curr]);
			curr = parent[curr];
		}
	}
	for (auto i : ans) cout << i << " ";
	cout << endl;
}

void isConnectedHelper(int **edges, int n, int sv, bool *visited)
{
	visited[sv] = true;
	for (int i = 0; i < n; i++)
		if (!visited[i] && edges[sv][i])
			isConnectedHelper(edges, n, i, visited);
}

bool isConnected(int **edges, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	isConnectedHelper(edges, n, 0, visited);
	for (int i = 0; i < n; i++) if (!visited[i]) return false;
	return true;
}

void travelDFS(int **edges, int n, int sv, bool* visited, vector<int> &currAns)
{
	currAns.push_back(sv);
	visited[sv] = true;
	for (int i = 0; i < n; i++)
		if (!visited[i] && edges[sv][i])
			travelDFS(edges, n, i, visited, currAns);
}

vector<vector<int>> allConnComponents(int **edges, int n)
{
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	vector<vector<int>> ans;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			vector<int> currAns;
			travelDFS(edges, n, i, visited, currAns);
			ans.push_back(currAns);
		}
	}
	return ans;
}


int main()
{
	cout << "V: E:" << endl;
	int n, e; cin >> n >> e;
	int **edges = new int*[n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
			edges[i][j] = 0;
	}

	cout << "V1 V2" << endl;
	for (int i = 0; i < e; i++)
	{
		int v1, v2; cin >> v1 >> v2;
		edges[v1][v2] = 1;
		edges[v2][v1] = 1;
	}

	// DFS(edges, n);
	// BFS(edges, n);

	// int sv, ev; cin >> sv >> ev;
	// cout << boolalpha << hasPathHelper(edges, n, sv, ev);
	// getPathHelperDFS(edges, n, sv, ev);
	// getPathHelperBFS(edges, n, sv, ev);
	// cout << boolalpha << isConnected(edges, n);
	vector<vector<int>> ans = allConnComponents(edges, n);
	for (auto i : ans)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}


// clearing memory
	for (int i = 0; i < n; i++)
		delete [] edges[i];
	delete [] edges;
}