#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    long long int adj_mat[105][105];


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
                continue;
            }
            adj_mat[i][j] = LLONG_MAX;
        }
    }

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        if (adj_mat[a-1][b-1] > w)
            adj_mat[a-1][b-1] = w;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (adj_mat[i][j] == LLONG_MAX)
    //         {
    //             cout << "*" << " ";
    //             continue;
    //         }
    //         cout << adj_mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout << i << " " << k << " " << j << endl;

                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]))
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }
    // cout << "----------" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (adj_mat[i][j] == LLONG_MAX)
    //         {
    //             cout << "*" << " ";
    //             continue;
    //         }
    //         cout << adj_mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if(x <=n && y <= n )
        {
            if (adj_mat[x-1][y-1] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[x-1][y-1] << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}