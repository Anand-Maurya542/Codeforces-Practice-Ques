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
vector<int> parent;

int cycle_start = -1, cycle_end = -1;

bool dfs(int node, int par){
    visited[node]=true;

    for(int child : adj[node]){

        if(child == par) continue;

        if(visited[child]){
            cycle_start = child;
            cycle_end = node;
            return true;
        }else{
            parent[child]=node;
            if(dfs(child, node)) return true;
        }
    }
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
       adj[v].push_back(u);
    }

    parent.assign(n+1, -1);
    
    for(int i=1; i<=n; i++){
        if(!visited[i] && dfs(i, -1)) break;

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