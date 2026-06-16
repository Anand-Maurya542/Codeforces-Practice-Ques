// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<vector<int>> adj;
vector<int> subtree;

void dfs(int u){
    subtree[u]=1;

    for(int v : adj[u]){
        dfs(v);
        subtree[u]+=subtree[v];
    }
    
}

void solve()
{
    int n;
    cin >> n;
    
    adj.resize(n+1);
    subtree.resize(n+1);

    for(int i=2; i<=n; i++){
       int b ; cin>>b;
       adj[b].push_back(i);
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        cout<<subtree[i]-1<<' ';
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