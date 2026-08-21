#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
long long int dis[1005];
vector<Edge> edge_list;

bool neg = false;

void bellman_ford(int src)
{
    for (int i = 1; i < n; i++)
    {
        for (auto x : edge_list)
        {
            int a, b, c;
            a = x.a;
            b = x.b;
            c = x.c;

            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto x : edge_list)
        {
            int a, b, c;
            a = x.a;
            b = x.b;
            c = x.c;

            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                neg = true;
                break;
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }

    int s, t;
    cin >> s >> t;

    dis[s] = 0;
    bellman_ford(s);

    if (neg)
        cout << "Negative Cycle Detected" << endl;
    else
    {
        while (t--)
        {
            int x;
            cin >> x;
            if (dis[x] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[x] << endl;
        }
    }

    // for (int i = s; i <= n; i++)
    // {
    //     cout << i << " - > " << dis[i] << endl;
    // }

    return 0;
}