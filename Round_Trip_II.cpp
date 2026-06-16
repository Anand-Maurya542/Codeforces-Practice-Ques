// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
//#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<bool> visited, recstack;
const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
vector<int> parent;

int cycle_start = -1, cycle_end = -1;

bool dfs(int u){
    visited[u]=true;
    recstack[u]=true;

    for(int v : adj[u]){

       if(!visited[v]){
        parent[v]=u;
        if(dfs(v)) return true;
       }else if(recstack[v]){
        cycle_end = u;
        cycle_start=v;
        return true;
       }
    }
    recstack[u]=false;
    return false;
}
void solve()
{
 cin >> n >> m;
 adj.resize(n+1);
 visited.assign(n+1, false);
   for (int i = 0; i < m; i++){
       int u,v;
       cin>>u >> v;
       adj[u].push_back(v);

    }

    parent.assign(n+1, -1);
    recstack.assign(n+1, false);
    
    for(int i=1; i<=n; i++){
        if(!visited[i] && dfs(i)) break;

    }

    if(cycle_start ==-1 ){
        cout<<"IMPOSSIBLE"<<'\n';
        return ;
    }

    vector<int> path;
    path.push_back(cycle_start);
    int curr = cycle_end;

    while(curr!=cycle_start){
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(curr);
    reverse(path.begin(), path.end());

    cout<<path.size()<<'\n';
    for(int& x:path) cout<<x<<' ';
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