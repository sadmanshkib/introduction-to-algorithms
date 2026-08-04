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
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        vector<int> v = adj_list[x];
        sort(v.begin(), v.end(), greater<int>());
        for (int p : v)
            cout << p << " ";
        if (v.empty())
            cout << -1;
        cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " > ";
    //     for(int x : adj_list[i])
    //         cout << x << " ";
    //     cout << endl;
    // }

    return 0;
}