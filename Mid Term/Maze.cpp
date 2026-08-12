#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> adj_list[1005][1005];

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void bfs(int ki, int kj)
{
    pair<int, int> p = {ki, kj};
    queue<pair<int, int>> q;
    q.push(p);
    vis[ki][kj] = true;
    level[ki][kj] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;
        // cout << pi << "  " << pj << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + direction[i].first;
            int cj = pj + direction[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[parent.first][parent.second] + 1;
                // cout << ci << cj << endl;
                adj_list[ci][cj] = {pi, pj};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;

                // cout << si << sj << endl;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;

                // cout << i << j << endl;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(si, sj);

    // cout << adj_list[di][dj].first << adj_list[di][dj].second << endl;
    // cout << adj_list[adj_list[di][dj].first][adj_list[di][dj].second].first << adj_list[adj_list[di][dj].first][adj_list[di][dj].second].second << endl;
    // cout << level[di][dj] << endl;
    if (vis[di][dj])
    {
        int pi, pj;
        pi = adj_list[di][dj].first;
        pj = adj_list[di][dj].second;
        while (true)
        {
            if (pi == si && pj == sj)
                break;

            // cout << pi << " " << pj << endl;
            grid[pi][pj] = 'X';
            int x = pi;
            pi = adj_list[x][pj].first;
            pj = adj_list[x][pj].second;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}