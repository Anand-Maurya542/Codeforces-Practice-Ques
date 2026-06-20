// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<int> indeg;
vector<vector<bool>> visited;
const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void solve()
{
 cin >> n >> m;
 adj.resize(n+1);
 indeg.assign(n+1, 0);
 
   for (int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
       
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); q.pop();

        topo.push_back(u);

        for(int v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
    
    vector<int> dp(n+1,0);
    dp[1] = 1;


    for(int u : topo){



        for(int v : adj[u]){ //for each neghtbor relax distance

                dp[v] = (dp[v] + dp[u]) % MOD;


        }
    }
    
    cout<<dp[n]<<"\n";
    
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