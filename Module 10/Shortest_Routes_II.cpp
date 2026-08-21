#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, m, q;
    cin >> n >> m >> q;
    long long int adj_mat[n + 3][n + 3];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
                continue;
            }
            adj_mat[i][j] = LLONG_MAX;
        }
    }

    while (m--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        if(c < adj_mat[a][b]){adj_mat[a][b] = c;}
        if(c < adj_mat[b][a]){adj_mat[b][a] = c;}
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // cout << i << " " << k << " " << j << endl;

                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]))
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (adj_mat[a][b] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[a][b] << endl;
    }

    return 0;
}