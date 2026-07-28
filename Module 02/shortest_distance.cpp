#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000 + 5];
bool vis[1000 + 5];
int level[1005];

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
                level[cld] = level[fnt]+1;

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
    int src, dest;
    cin >> src >> dest;

    bfs(src);

    // for(int i=0; i<n;i++)
    // {
    //     cout << i << " --> " << level[i] << endl;
    // }
    cout << level[dest] << endl;

    return 0;
}