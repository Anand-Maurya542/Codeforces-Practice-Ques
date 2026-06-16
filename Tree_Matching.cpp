// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<vector<int>> adj;
int cnt = 0;
vector<int> visited;

void dfs(int u, int par){
    for(int v : adj[u] ){
        if(v != par){
            dfs(v, u);
            if(!visited[u] && !visited[v]){
                cnt++;
                visited[u]=1;
                visited[v]=1;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n ;
   adj.resize(n+1);
   visited.assign(n+1, 0);
   

   for(int i=0; i<n-1; i++){
    int u, v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }

   dfs(1,-1);

   cout<<cnt<<'\n';
    
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