#include <bits/stdc++.h>
using namespace std;

int ticketTime(vector<int> vec, int n, int k)
{
	priority_queue<int> pq;
	for (auto i : vec) pq.push(i);
	queue<int> que;
	for (int i = 0; i < n; i++) que.push(i);

	int time = 0;
	int poppedIdx = -1;
	while (poppedIdx != k)
	{
		if (vec[que.front()] == pq.top())
		{
			poppedIdx = que.front();
			que.pop();
			pq.pop();
			time++;
		}
		else
		{
			int tmp = que.front();
			que.pop();
			que.push(tmp);
		}
	}
	return time;
}

int main()
{
	int n; cin >> n;
	vector<int> vec(n);
	for (auto &it : vec) cin >> it;
	int k; cin >> k;

	cout << ticketTime(vec, n, k);
}