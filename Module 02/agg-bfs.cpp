#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000 + 1];
bool vis[1000 + 1];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        // ber kore ana
        int fn = q.front();
        q.pop();

        // front ber kora
        cout << fn << " ";

        // child push kora
        for (int ch : adj_list[fn])
        {
            if (vis[ch] == false)
            {
                q.push(ch);
                vis[ch] = true;
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
        adj_list[b].push_back(a);
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));

    bfs(0);
    return 0;
}