#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj_list[1005];
int dis[1005];

void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int p_node = p.second;
        int p_dis = p.first;

        for(auto cld : adj_list[p_node])
        {
            int cld_node = cld.first;
            int cld_dis = cld.second;

            if(p_dis+cld_dis < dis[cld_node])
            {
                dis[cld_node] = p_dis+cld_dis;
                pq.push({dis[cld_node],cld_node});
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
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    // for (int i = 0; i < n; i++)
    // {
        
    //     for(auto x : adj_list[i])
    //         cout << i << " --> " << x.first <<"," << x.second << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    for(int i = 0; i < n; i++)
    {
        cout << i << " --> " << dis[i] << endl;
    }
    
    dijkstra(0);
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << i << " --> " << dis[i] << endl;
    }
    

    
    

    
    return 0;
}