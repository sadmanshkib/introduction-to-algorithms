#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[99999 + 5];
bool vis[99999 + 5];
int level[99999];
int parent[99999 + 5];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int fnt = q.front();
        q.pop();

        // node er kaj

        // child er kaj
        for (int cld : adj_list[fnt])
        {
            if (!vis[cld])
            {
                q.push(cld);
                vis[cld] = true;
                level[cld] = level[fnt] + 1;
                parent[cld] = fnt;
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
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    int src, dest;
    src = 1;
    dest = n;

    bfs(src);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " parent -> " << parent[i] << endl;
    // }

    int node = dest;
    vector<int> path;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    if (!vis[dest])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    else
    {
       cout << level[dest]+1 <<endl;
    reverse(path.begin(),path.end());
    
    for(int x: path)
    cout << x << " ";
    // cout << level[dest] << endl;
    }

    return 0;
}