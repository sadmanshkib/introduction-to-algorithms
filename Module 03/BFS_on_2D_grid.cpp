#include <bits/stdc++.h>
using namespace std;

char grid[100][100];
bool vis[100][100];
vector<pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

// void dfs(int si, int sj)
// {
//     cout << si << " " << sj << endl;
//     vis[si][sj] = true;

//     for (int i = 0; i < 4; i++)
//     {
//         int ci, cj;
//         ci = si + d[i].first;
//         cj = sj + d[i].second;

//         if (valid(ci, cj) && !vis[ci][cj])
//             dfs(ci, cj);
//     }
// }

void bfs(int si,int sj)
{
    pair<int,int> p = {si,sj};
    queue<pair<int,int>> q;
    q.push(p);
    vis[p.first][p.second] = true;

    while (!q.empty())
    {
        pair<int,int> pa = q.front();
        q.pop();

        // for(pair<int,int> cld : grid[pa.first][pa.second])
        // {
        //     if(!vis[cls])
        //      {
        //         q.push(cld);
        //         vis[cld] = true;
        //      }   
        // }
        for (int i = 0; i < 4; i++)
        {
            int ci = pa.first + d[i].first;
            int cj =pa.second + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj])
                bfs(ci,cj);
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

    int si, sj;
    cin >> si >> sj;
    // dfs(si, sj);

    bfs(si,sj);
    return 0;
}