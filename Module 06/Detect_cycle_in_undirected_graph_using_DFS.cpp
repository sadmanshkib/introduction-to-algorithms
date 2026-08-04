#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
int par[105];
bool cycle;



void dfs(int src)
{
    vis[src] = true;

    for (int cld : adj_list[src])
    {
        if (vis[cld] && par[src] != cld)
            cycle = true;
        if (!vis[cld])
        {
            par[cld] = src; // importanr
            dfs(cld);
        }
    }
}

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
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));

    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " --- " << par[i] << endl;
    }

    if (cycle)
        cout << "There is a Cycle" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}