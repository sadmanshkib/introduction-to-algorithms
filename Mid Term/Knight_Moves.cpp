#include <bits/stdc++.h>
using namespace std;
int n, m;

int grid[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> direction = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}, {1, 2}, {-1, 2}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

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

        for (int i = 0; i < 8; i++)
        {
            int ci = pi + direction[i].first;
            int cj = pj + direction[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[parent.first][parent.second]+1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        cin >> n >> m;

        int ki, qi, kj, qj;
        cin >> ki >> kj >> qi >> qj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(ki, kj);

        cout << level[qi][qj] << endl;
    }

    

    return 0;
}