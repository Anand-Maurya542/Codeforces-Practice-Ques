// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
//#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const ll inf = 1e18;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<vector<ll>> dist;
const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void solve()
{
 cin >> n >> m;
 adj.resize(n+1);
 dist.assign(n+1,vector<ll>(2, inf));
   for (int i = 0; i < m; i++){
      int u, v, c;
      cin>>u>>v>>c;
      adj[u].push_back({v,c});
    }
    //COST, node, state (0/1)
    priority_queue<tuple<ll,int, int>, vector<tuple<ll, int ,int>>, greater<>> pq;
    pq.push({0,1,0});
    dist[1][0]=0;

    while(!pq.empty()){
        auto [d, u, used] = pq.top(); pq.pop();

        if(d > dist[u][used]) continue;

        for(auto [v, cost] : adj[u]){
            if(used == 0){
                //dis not used yet

                //dont use
                if(d + cost < dist[v][0]){
                    dist[v][0]=d + cost;
                    pq.push({dist[v][0], v, 0});
                }

                //use dis
                if(d + cost / 2 < dist[v][1]){
                    dist[v][1] = d + cost/2;
                    pq.push({dist[v][1], v, 1});
                }

            }else{
                //already used
                if(d + cost < dist[v][1]){
                    dist[v][1]=d + cost;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }
    cout<<dist[n][1]<<'\n';




    
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