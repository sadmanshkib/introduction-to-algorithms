#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj_list[1005];
int dis[1005];

void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});

    dis[src] = 0;

    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();

        int p_node = p.first;
        int p_dis = p.second;



        for(auto cld : adj_list[p_node])
        {
            int cld_node  = cld.first;
            int cld_dis = cld.second;

            if(p_dis+cld_dis < dis[cld_node])
            {
                dis[cld_node] = p_dis+cld_dis;
                q.push({cld_node,dis[cld_node]});
            }
        }
    }
    

}

int main()
{
    int n,e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});

    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dis[i] << endl;
    // }
    

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " --> "  << dis[i];
        cout << endl;
    }
    
    
    
    return 0;
}