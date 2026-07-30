#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        bool have = false;

        for (int x : adj_list[a])
        {
            if (x == b)
                have = true;
        }
        if (a == b)
            have = true;

        if (have)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}