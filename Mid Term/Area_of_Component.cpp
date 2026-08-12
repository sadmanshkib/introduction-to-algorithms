#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt;
char grid[1005][1005];

bool vis[1005][1005];

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
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

    //  for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    memset(vis, false, sizeof(vis));
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                ans = min(cnt, ans);
            }
        }
    }

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;

    // cout << ans << endl;

    // if (vis[di][dj])
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;

    return 0;
}