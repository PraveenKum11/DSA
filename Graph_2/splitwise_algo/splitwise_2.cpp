#include <bits/stdc++.h>
using namespace std;

// Splitwise algorithm to minimize the number of transactions
// and find the new transactions.

int main()
{
	int v, e;
	cin >> v >> e;

	string src, dst;
	int amount;

	// map to store the next gain/loss
	map<string, int> net;

	while (e--)
	{
		cin >> src >> dst >> amount;

		net[src] -= amount;
		net[dst] += amount;
	}

	// Comparator class for multiset
	class Compare
	{
	public:
		bool operator()(const pair<string, int>& x, const pair<string, int>& y) const
		{
			return x.second < y.second;
		}
	};

	// multiset to store all the non zero net
	multiset<pair<string, int>, Compare> mset;

	// Add all the non zero net to set
	for (auto [name, amt] : net)
	{
		if (amt) mset.insert({name, amt});
	}

	// new min transactions
	int cnt = 0;

	while (!mset.empty())
	{
		// get the largest debit and credit
		auto low 	= begin(mset);			// debit
		auto high 	= prev(end(mset));		// credit

		pair<string, int> debit 	= *low;
		pair<string, int> credit 	= *high;

		// pop those out
		mset.erase(low);
		mset.erase(high);

		// find the best settlement amount such that
		// one of the transactions will become zero
		int settlementAmount = min(-debit.second, credit.second);

		// print the transaction
		cout << debit.first << " pays " << settlementAmount << " to " << credit.first << endl;

		// make settlement
		debit.second 	+= settlementAmount;
		credit.second 	-= settlementAmount;

		// if one of the transactions remain
		// add it again to set
		if (debit.second != 0) 	mset.insert(debit);
		if (credit.second != 0)	mset.insert(credit);

		cnt++;
	}
	cout << "Total Transactions: " << cnt << endl;

	return 0;
}

/*
input:
3 3
Table Chair 100
Chair Sofa 50
Sofa Table 40
*/