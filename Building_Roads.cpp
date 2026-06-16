// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
//#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int node){
    visited[node]=true;

    for(int child : adj[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
}

void solve()
{
 cin >> n >> m;
 adj.resize(n+1);
 visited.assign(n+1, false);
   for (int i = 0; i < m; i++){
    int u, v;
    cin>> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);

       
    }

    vector<int> rep;

    for(int i = 1 ; i<=n; i++){
        if(!visited[i]){
            rep.push_back(i);
            dfs(i);
        }
    }

    cout<<rep.size()-1<<'\n';
    for(int i=0 ; i<rep.size()-1; i++)
        cout<<rep[i] << ' '<<rep[i+1]<<"\n";
    
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