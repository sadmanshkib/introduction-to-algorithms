#include <bits/stdc++.h>
using namespace std;
int par[100005];
int group_sz[100005];

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

    int n, e;
    cin >> n >> e;
    bool cycle = false;
    int cnt = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int lead1 = find(a);
        int lead2 = find(b);

        if(lead1 == lead2)
            {
                cycle = true;
                cnt++;
            }
        else
            dsu_union(a,b);

    }
    cout << cnt << endl;
   

    return 0;
}