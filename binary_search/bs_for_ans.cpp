"""
Advanced Binary Search || Tutorial + Problem Solving Session(English)
->
https://www.youtube.com/watch?v=Ya0W8ZMzjgc
"""

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int n)
{
    // boolean predicate function
    if ("conditions are meet")
        return true;
    return false;
}

void solve()
{
    ll l, r, mid;
    // invariants: l is always false and r is always true
    l = 0;
    r = 1e12;

    // breaks when r = l + 1
    while (r > l + 1)
    {
        mid = (l + r) / 2;
        // Now don't think just follow the invariants 
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    // according to the invariant r should be true
    cout << r << endl;
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
}