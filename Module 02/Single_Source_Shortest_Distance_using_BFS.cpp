#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool cheaked[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    cheaked[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int x : adj_list[front])
        {
            if (!cheaked[x])
            {
                q.push(x);
                cheaked[x] = true;
                level[x] = level[front] + 1;
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

    memset(cheaked, false, sizeof(cheaked));
    memset(level, -1, sizeof(level));

    int src, dst;
    cin >> src >> dst;
    bfs(src);

    // for (int i=0; i < n; i++)
    // {
    //     cout << i << " -> " << level[i] << endl;
    // }

    cout << " -> " << level[dst] << endl;

    return 0;
} 