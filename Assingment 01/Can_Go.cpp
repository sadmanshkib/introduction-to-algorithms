#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> v = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int m, n;
bool valid (int i, int j)
{
    if(i<0 || j<0 || i >= m || j >= n)
        return false;
    return true;

}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + v[i].first;
        cj = sj + v[i].second;
        if (!vis[ci][cj] && grid[ci][cj] != '#' && valid(ci,cj))
        {
            // vis[ci][cj] = true;
            // cout << ci << cj;
            // cout << grid[ci][cj] << endl;
            dfs(ci, cj);
        }
        // cout << ci << cj << endl;
    }
}

int main()
{
    cin >> m >> n;

    int si, sj, di, dj;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));

    dfs(si, sj);

    if (vis[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    // cout << si << sj << " " << di << dj;

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}