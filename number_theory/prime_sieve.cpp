#include <bits/stdc++.h>
using namespace std;

void solve()
{
	// const int n = 1e2;
	// vector<bool> isPrime(n, true);
	// isPrime[0] = isPrime[1] = false;

	// simple sieve 
	// for (int i = 2; i < n; i++)
	// {
	// 	if (isPrime[i])
	// 	{
	// 		for (int j = 2 * i; j < n; j+=i)
	// 			isPrime[j] = false;
	// 	}
	// }

	// optimization 1: sieve till the root
	// optimization 2: start j from i * i 
	// for (int i = 2; i * i < n; i++)
	// {
	// 	if (isPrime[i])
	// 	{
	// 		for (int j = i * i; j < n; j+=i)
	// 			isPrime[j] = false;
	// 	}
	// }

	// optimization 3: all even numbers are composite(i.e not prime) except 2
	const int n = 1e2;
	vector<bool> isPrime(n, false);
	isPrime[2] = true;

	// mark all odd numbers as prime
	for (int i = 3; i < n; i+=2)
		isPrime[i] = true;
	// mark all multiples
	for (int i = 3; i * i < n; i+=2)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < n; j+=i)
				isPrime[j] = false;
		}
	}

	// driver code
	for (int i = 2; i < n; i++)
		if (isPrime[i])
			cout << i << " ";
}

int32_t main()
{
	// fastio();
	// int t; cin >> t;
	// while (t--)
	solve();
}