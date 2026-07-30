#include <bits/stdc++.h>
using namespace std;

char grid[100][100];
bool vis[100][100];
int dist[100][100];
vector<pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    pair<int, int> p = {si, sj};
    queue<pair<int, int>> q;
    q.push(p);
    vis[p.first][p.second] = true;
    dist[p.first][p.second] = 0;

    while (!q.empty())
    {
        pair<int, int> pa = q.front();
        q.pop();
        // cout << pa.first << " " << pa.second << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = pa.first + d[i].first;
            int cj = pa.second + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj]== '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dist[ci][cj] = dist[pa.first][pa.second] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    // dfs(si, sj);

    bfs(si, sj);
    cout << dist[di][dj] << endl;
    return 0;
}