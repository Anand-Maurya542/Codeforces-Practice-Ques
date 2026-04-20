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
int dir[4][2]={ {1,0},{-1,0}, {0,1}, {0,-1}}; 
int ans; 
void dfs(vector<vector<int>> &adj,vector<int>&a,int node, int parent, int cats, int k){
    
    if(node != 0 && adj[node].size() == 1 && cats <= k){
        // cout<<"node -leaf"<<node<<'\n';
        ans++;
    }
   
    
    
    for(auto& it:adj[node]){
        if(cats>k) return;
        int newCats=a[it]==1? cats+1:0;
        
        
        if(it!=parent){
            dfs(adj,a, it, node, newCats,k);
            
        }
    }


}    
void solve(){
    int n, k;
    cin >> n >> k;
    ans=0;
    vector<int> a(n); read(a);
    vector<vector<int>> adj(n);
    vector<int> vis(n);
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);    
    }
    dfs(adj,a,0,-1,a[0],k);
    cout<<ans<<'\n';
    
    
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