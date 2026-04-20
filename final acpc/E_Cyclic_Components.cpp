#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& degree, bool &isCycle){
    vis[node] = 1;

    if(degree[node] != 2) isCycle = false;

    for(auto &it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, degree, isCycle);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> degree(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    vector<int> vis(n+1, 0);
    int ans = 0;

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            bool isCycle = true;
            dfs(i, adj, vis, degree, isCycle);

            if(isCycle) ans++;
        }
    }

    cout << ans << '\n';
}