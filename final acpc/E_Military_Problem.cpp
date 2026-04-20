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
void dfs(int node,vector<vector<int>>& adj,vector<int>& order,vector<int> &subtree,vector<int> &tin ){
    tin[node]=order.size();
    order.push_back(node);

    for(int& next:adj[node]){
        dfs(next, adj, order, subtree, tin);
    }
    subtree[node]= order.size()-tin[node];

}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i=2; i<=n;i++){
        int u; cin>>u;
        adj[u].push_back(i);
    }
    vector<int> subtree(n+1,0),tin(n+1);
    vector<int> order;
    dfs(1,adj,order,subtree,tin);

    for(int i=0;i<k;i++){
        int u,ind; cin>>u>>ind;
        if(subtree[u]<ind) cout<<-1<<'\n';
        else{
            cout<< order[tin[u]+ind-1]<<'\n';
        }
    }
    
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