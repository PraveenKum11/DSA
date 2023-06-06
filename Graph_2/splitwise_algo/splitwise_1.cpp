#include <bits/stdc++.h>
using namespace std;

// Splitwise algo to minimize the number of transactions

int main()
{
	int v, e;
	cin >> v >> e;

	int src, dst, amount;

	// vector to store the net gain or loss
	// initially all nodes have 0 net amount
	vector<int> net(v, 0);

	// calculate the net amount for each node
	while (e--)
	{
		cin >> src >> dst >> amount;
		net[src] -= amount;
		net[dst] += amount;
	}

	// multimap to store the net debit and credit amount
	multiset<int> mset;

	// minimun number of new transactions
	int cnt = 0;

	// add all the non zero amounts (non settled amount)
	for (auto i : net)
	{
		if (i) mset.insert(i);
	}

	while (!mset.empty())
	{
		// take the largest debit and largest credit
		auto low 	= begin(mset);
		auto high 	= prev(end(mset));

		int debit = *low, credit = *high;

		// pop those out of the set
		mset.erase(low);
		mset.erase(high);

		// find the settlement amount such that
		// one of the transactions will become zero
		int settlementAmount = min(-debit, credit);

		// make settlement
		debit 	+= settlementAmount;
		credit 	-= settlementAmount;

		// if one of the transactions remain
		// add it again in the set
		if (debit != 0) 	mset.insert(debit);
		if (credit != 0) 	mset.insert(credit);

		cnt++;
	}
	cout << cnt << endl;

	return 0;
}

/*
input:

3 3
0 1 100
1 2 50
2 0 40
*/