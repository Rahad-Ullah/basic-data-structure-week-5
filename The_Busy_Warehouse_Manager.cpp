#include <bits/stdc++.h>
using namespace std;

int counts[1000001];

int main()
{
    int n;
    cin >> n;

    priority_queue<pair<int, int>> pq;
    int total_items = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (n--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            counts[x]++;
            total_items++;
            pq.push({counts[x], x});
        }
        else if (type == 2)
        {
            if (total_items == 0)
            {
                cout << "empty" << endl;
            }
            else
            {
                while (!pq.empty())
                {
                    pair<int, int> top = pq.top();
                    int qty = top.first;
                    int id = top.second;

                    if (counts[id] == qty && qty > 0)
                    {
                        cout << id << endl;
                        total_items -= counts[id];
                        counts[id] = 0;
                        pq.pop();
                        break;
                    }
                    else
                    {
                        pq.pop();
                    }
                }
            }
        }
    }

    return 0;
}