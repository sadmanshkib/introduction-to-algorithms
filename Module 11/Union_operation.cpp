#include <bits/stdc++.h>
using namespace std;

int par[105];
int group_sz[105];

int find(int node)
{
    if (par[node] == -1)
        return node;
    // cout << node << endl;
    int p = find(par[node]);
    par[node] = p;
    return p;
}

void dsu_union(int node1, int node2)
{
    int lead1 = find(node1);
    int lead2 = find(node2);
    if (group_sz[lead1] >= group_sz[lead2])
    {
        par[lead2] = lead1;
        group_sz[lead1] += group_sz[lead2];
    }
    else
    {
        par[lead1] = lead2;
        group_sz[lead2] += group_sz[lead1];
    }
}

int main()
{
    memset(par, -1, sizeof(par));
    memset(group_sz, 1, sizeof(group_sz));
    
    dsu_union(1, 2);
    dsu_union(2, 0);
    dsu_union(3, 1);


    cout << find(4) << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << i << " -> " << par[i] << endl;
    }

    return 0;
}