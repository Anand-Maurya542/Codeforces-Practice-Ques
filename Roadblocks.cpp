// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> adj[n+1];

    while(k--){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});

    }

    vector<vector<int>> dist(n+1);
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<> > pq;
    pq.push({0,1});


    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();

        if(dist[u].size()>=2) continue;
        
        dist[u].push_back(d);

        for(auto& [v, cost] : adj[u]){
            pq.push({cost + d, v});
        }

        if(dist[n].size()==2) break;
    }
    cout<<dist[n][1]<<'\n';

    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}