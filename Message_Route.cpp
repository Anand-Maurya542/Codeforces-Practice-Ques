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
    queue<int> q;
    q.push(1);
    visited[1]=true;

    vector<int> parent(n+1,-1);

    bool found = false;
    while(!q.empty() && !found){
        int node = q.front(); q.pop();

        for(int child : adj[node]){
            if(!visited[child]){
                visited[child]=true;
                parent[child]=node;
                q.push(child);

                if(child==n){
                    found=true;
                    break;
                }
            }
        }
    }

    if(!found){
        cout<<"IMPOSSIBLE"<<'\n';
        return;
    }

    vector<int> path;
    int curr = n;
    while(curr!=-1){
        path.push_back(curr);
        curr= parent[curr];
    }
    cout<<path.size()<<'\n';
    for(int i=path.size()-1; i>=0; i--){
        cout<<path[i]<<' ';
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