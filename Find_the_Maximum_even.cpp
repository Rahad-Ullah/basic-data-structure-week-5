#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    vector<long long> evens, odds;

    for (int i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        if (val % 2 == 0)
            evens.push_back(val);
        else
            odds.push_back(val);
    }

    sort(evens.rbegin(), evens.rend());
    sort(odds.rbegin(), odds.rend());

    long long max_even = -1;

    if (!evens.empty())
    {
        max_even = max(max_even, evens[0]);
    }

    if (evens.size() >= 2)
    {
        max_even = max(max_even, evens[0] + evens[1]);
    }

    if (odds.size() >= 2)
    {
        max_even = max(max_even, odds[0] + odds[1]);
    }

    cout << max_even << endl;

    return 0;
}