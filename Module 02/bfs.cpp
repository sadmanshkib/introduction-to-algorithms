#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool cheaked[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    cheaked[src] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        cout << front << " ";

        for (int x : adj_list[front])
        {
            if (!cheaked[x])
                q.push(x);

            cheaked[x] = true;
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
    memset(cheaked,false,sizeof(cheaked));
    bfs(0);

    return 0;
}