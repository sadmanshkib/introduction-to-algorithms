#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
int par[105];
bool cycle ;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        cout << parent << endl;
        q.pop();
        for (int cld : adj_list[parent])
        {
            if(vis[cld] && par[parent] != cld)
                cycle = true;
            if (!vis[cld])
               {
                q.push(cld);
                vis[cld] = true;
                par[cld] = parent;
               }
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
    memset(par,-1,sizeof(par));

    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    if(cycle)
        cout << "There is a Cycle" <<endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}