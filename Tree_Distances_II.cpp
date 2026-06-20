// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<vector<int>> adj;
vector<int> res;
vector<int> subtree;
vector<int> cost;

void preCal(int node, int par){
    for(int c : adj[node]){
        if(c != par){
            preCal(c, node);
            subtree[node] += subtree[c];
            cost[node] += cost[c] + subtree[c]; 
        }
    }

}

void dfs(int node, int par){
    res[node]=cost[node];
    for(int c : adj[node]){
        if(c!=par){
            //break link
            cost[node] -= (cost[c] + subtree[c]);
            subtree[node] -= subtree[c];
            
            //new root calculation -> child become new root
            cost[c] += cost[node] + subtree[node];
            subtree[c]+=subtree[node];
            
            dfs(c, node);
            
            //reconstruct
            cost[c] -= cost[node] + subtree[node];
            subtree[c] -=subtree[node];
            
            cost[node] += (cost[c] + subtree[c]);
            subtree[node] += subtree[c];
            


        }
    }
}

void solve()
{
    int n;
    cin >> n ;
    
    adj.resize(n+1);
    res.assign(n+1, 0);
    subtree.assign(n+1, 1);
    cost.assign(n+1, 0);

    for(int i=0; i<n-1; i++){
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    preCal(1,-1);
    dfs(1, -1);
    
    for(int i=1; i<=n; i++){
        cout<<res[i]<<' ';
    }
    cout<<'\n';

    
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