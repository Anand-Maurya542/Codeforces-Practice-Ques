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

// #define int long long

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
void dfs(vector<vector<int>>& adj,vector<int>& vis, int node ){
    vis[node]=1;
    for(auto& it:adj[node]){
        if(!vis[it]){
            dfs(adj,vis,it);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n*m);
    string horizontal; cin>>horizontal;
    string vertical; cin>>vertical;
    
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            if(horizontal[i]=='>'){
                adj[i*m+j-1].push_back(i*m+j);
                
            }else{
                adj[i*m+j].push_back(i*m+j-1);
            }
        }
    }
    for(int j=0; j<m; j++){
        for(int i=1; i<n; i++){
            if(vertical[j]=='v'){
                adj[(i-1)*m+j].push_back(i*m+j);
            }else{
                adj[i*m+j].push_back((i-1)*m+j);
            }
        }
    }
    for(int i=0; i<n*m ; i++){
        vector<int> vis(n*m,0);
        dfs(adj, vis, i);
            if(any_of(all(vis),[](int& x){
                return x==0;
            })){
                no();
                return;
            }
        
    }
    yes();

    
    
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