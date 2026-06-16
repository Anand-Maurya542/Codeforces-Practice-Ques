// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
//#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const ll inf = 1e18;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<ll> dist;
const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void solve()
{
 cin >> n >> m;
 adj.resize(n+1);
 dist.assign(n+1, inf);
   for (int i = 0; i < m; i++){
      int u, v, c;
      cin>>u>>v>>c;
      adj[u].push_back({v,c});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();

        if(d > dist[node]) continue;

        for(auto [child, cost] : adj[node]){
            if(cost + d < dist[child]){
                dist[child] = cost + d;
                pq.push({dist[child], child});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<' ';
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