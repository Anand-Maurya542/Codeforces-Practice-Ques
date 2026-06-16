// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<vector<int>> adj;
vector<int> dist;

void dfs(int u, int par){
    for(int v : adj[u]){
        if(v!=par){
            dist[v]=1+dist[u];
            dfs(v,u);
        }
    }
}

void solve()
{
    int n;
    cin >> n ;

    if(n==1){
        cout<<0<<'\n';
        return;
    }
    
    adj.resize(n+1);
    dist.assign(n+1, 0);

    for(int i=0; i<n ;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);
    int far1 = -1;
    int maxi=0;

    for(int  i=1; i<=n; i++){
        if(dist[i]>maxi){
            maxi=dist[i];
            far1=i;
        }
    }

    dist.assign(n+1, 0);
    dfs(far1, -1);
    
    int far2=-1;
    maxi=0;
    for(int  i=1; i<=n; i++){
        if(dist[i]>maxi){
            maxi=dist[i];
            far2=i;
        }
    }
    
    vector<int> dist1 = dist;
    dist.assign(n+1, 0);
    dfs(far2,-1);






    for(int i=1; i<=n; i++){
        cout<< max(dist[i], dist1[i])<<" ";
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