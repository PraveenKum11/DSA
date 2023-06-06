#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;


class DSU
{
	vector<int> parent;
	int m_size;

public:
	DSU(int size) : m_size(size)
	{
		parent.resize(m_size);
		for (int i = 0; i < m_size; i++)
			parent[i] = i;
	}

	// find parent
	int find(int x)
	{
		if (x == parent[x])
			return x;
		// path compression
		return parent[x] = find(parent[x]);
	}

	// set parent
	void unionSet(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);

		if (rootX == rootY) return;
		parent[rootX] = rootY;		// since rootY will always be larger
	}
};


int main()
{
	fastio();
	int n, q;
	cin >> n >> q;
	vector<int> l(q), r(q), c(q);

	for (int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i] >> c[i];
	}

	DSU dsu(n + 2);
	vector<int> result(n + 2, 0);
	for (int i = q - 1; i >= 0; i--)
	{
		int idx = dsu.find(l[i]); 		// rightmost non colored idx
		while (idx <= r[i])
		{
			result[idx] = c[i];
			dsu.unionSet(idx, idx + 1);
			idx = dsu.find(idx);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << endl;

	return 0;
}