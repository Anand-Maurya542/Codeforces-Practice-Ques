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
    
    vector<int> dp(n+1,INT_MIN);
    dp[1] = 1;
    vector<int> parent(n+1,-1);

    for(int u : topo){

        if(dp[u] == INT_MIN) continue;

        for(int v : adj[u]){ //for each neghtbor relax distance
            if(1 + dp[u] > dp[v]){
                dp[v] = 1 + dp[u];
                parent[v]=u;
            }
        }
    }

    if(dp[n]==INT_MIN){
        cout<<"IMPOSSIBLE"<<'\n';
        return ;
    }

    int curr = n;
    vector<int> path;

    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];

    }
    reverse(path.begin(), path.end());

    cout<<path.size()<<'\n';
    for(int & x : path){
        cout<<x <<' ';
    }
    cout<<'\n';
    
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