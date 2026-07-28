#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000 + 5];
bool vis[1000 + 5];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

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
    int src, dest;
    cin >> src >> dest;

    bfs(src);

    if (vis[dest] == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}