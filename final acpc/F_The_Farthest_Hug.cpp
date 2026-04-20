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
// vector<vector<int>> adj(n);
pair<int,int> bfs(int start,vector<vector<int>> &adj ){
    int n=adj.size();
    vector<int> dist(n,INF);
    queue<int> q; q.push(start);
    dist[start]=0;
    int far=start;

    while(!q.empty()){
        int node=q.front(); q.pop();

        for(int next:adj[node]){

            if(dist[next]==INF){
                dist[next]=dist[node]+1;
                q.push(next);
                if(dist[next]>dist[far]){
                    far=next;
                }
            }
        }
    }
    return {far, dist[far]};

}
void solve()
{
    int n;
    cin >> n ;
    if(n==1){
        cout<<0<<"\n";
        return ;
    }
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto [nodeA,d]=bfs(1,adj);
    auto [node, diameter]=bfs(nodeA,adj);
    cout<<diameter<<'\n';
    
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