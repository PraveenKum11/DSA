#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
	vector<int> pq;

public:
	PriorityQueue(){}

	int getSize()
	{
		return pq.size();
	}

	bool isEmpty()
	{
		return pq.empty();
	}

	int getMin()
	{
		return pq[0];
	}

	void printPQ()
	{
		for (auto i : pq) cout << i << " ";
		cout << endl;
	}

	void insert(int val)
	{
		pq.push_back(val);
		// up-heapify
		int ci = pq.size() - 1;
		int pi = (ci - 1) / 2;
		while (pi >= 0 && pq[pi] > pq[ci])
		{
			swap(pq[pi], pq[ci]);
			ci = pi;
			pi = (ci - 1) / 2;
		}
	}

	void removeMin()
	{
		if (pq.empty())
		{
			cout << "Heap Empty" << endl;
			return;
		}
		swap(pq[0], pq[pq.size() - 1]);
		pq.pop_back();
		// down-heapify
		int pi = 0;
		int lci = (2 * pi + 1), rci = (2 * pi + 2);
		while (lci < pq.size())
		{
			int minIdx = pi;
			if (pq[minIdx] > pq[lci])
				minIdx = lci;
			if (rci < pq.size() && pq[minIdx] > pq[rci])
				minIdx = rci;
			if (minIdx == pi) break;
			swap(pq[pi], pq[minIdx]);

			pi = minIdx;
			lci = (2 * pi + 1), rci = (2 * pi + 2);
		}
	}
};