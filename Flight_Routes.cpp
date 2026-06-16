// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
//#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const ll inf = 1e18;

int n, m,k;
vector<vector<pair<int, int>>> adj;
const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void solve()
{
    cin >> n >> m >> k;
    adj.resize(n+1);
  
    for (int i = 0; i < m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0,1});
    vector<vector<ll>> dist(n+1);


    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();

        if(dist[u].size() >= k) continue;
        dist[u].push_back(d);

        for(auto& [v, cost] : adj[u]){
            pq.push({d+cost, v});
        }

        if(dist[n].size() == k) break;

        
    }
    for(int i=0; i<k; i++){
        cout<<dist[n][i]<<' ';
    }
    cout<<'\n';




    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
        solve();

    return 0;
}