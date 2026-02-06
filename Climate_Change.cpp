#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    long long total_sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total_sum += a[i];
    }

    if (total_sum % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    long long target = total_sum / 2;
    long long current_sum = 0;
    int valid_splits = 0;

    for (int k = 0; k < n - 1; k++)
    {
        current_sum += a[k];
        if (current_sum == target)
        {
            valid_splits++;
        }
    }

    cout << valid_splits << endl;

    return 0;
}