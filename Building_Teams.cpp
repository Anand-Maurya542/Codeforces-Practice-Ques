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
vector<int> team;

bool bfs(int node){
    queue<int> q;
    q.push(node);
    team[node]=1;
   

    while(!q.empty()){
        int node = q.front(); q.pop();

        for(int child : adj[node]){
            if(team[child] == -1){
                team[child] = 3 - team[node];
                q.push(child);
            }else if(team[child]==team[node]) return false;
        }
    }
    return true;

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
    
    team.assign(n+1, -1);

    for(int i=1; i<=n; i++){
        if(team[i]==-1){
            if(!bfs(i)){
                cout<<"IMPOSSIBLE"<<'\n';
                return;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<team[i]<<' ';
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