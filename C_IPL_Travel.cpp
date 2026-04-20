// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
// vector<vector<int>>dp;
// vector<int>dp;
//dp.assign(n, vector<int>(m, -1));
//dp.assign(n, -1);
//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int dir[4][2]={ {1,0},{-1,0}, {0,1}, {0,-1}};      
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1}); //wt,node;
    vector<int> dist(n+1,INF);
    vector<int> parent(n+1);
    parent[1]=-1;
    dist[1]=0;
    while(!pq.empty()){
        auto [wt,node]=pq.top(); pq.pop();

        if(wt>dist[node]) continue;

        for(auto& [next, cost]:adj[node]){
            if(dist[node]+cost < dist[next]){
                dist[next]=dist[node]+cost;
                pq.push({dist[next],next});
                parent[next]=node;

            }
        }
    }

    if(dist[n]==INF){
        cout<<-1<<'\n';
        return;
    }
    vector<int> path;
    // path.push_back(n);
    int node=n;
    while(parent[node]!=-1){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(all(path));
    print(path);

    
    
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