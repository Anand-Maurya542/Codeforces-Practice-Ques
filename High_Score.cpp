// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    vector<pair<int, pair<int, int>>> edges(m);
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, {v, wt}};
        adj[u].push_back(v);
    }

    vector<int> dist(n + 1, LLONG_MIN);
    dist[1] = 0;

    //bellman ford
    for (int i = 0; i < n - 1; i++)
    {
        for (auto [u, vw] : edges)
        {
            int v = vw.first, wt = vw.second;

            if (dist[u] != LLONG_MIN && dist[u] + wt > dist[v])
            {
                dist[v] = wt + dist[u];
            }
        }
    }

    // detect positive cycle
    unordered_set<int> cycle_nodes;
    for (auto [u, vw] : edges)
    {
        int v = vw.first, wt = vw.second;

        if (dist[u] != LLONG_MIN && dist[u] + wt > dist[v])
        {
            cycle_nodes.insert(v);
        }
    }

    queue<int> q;
    queue<int> cycle_q;

    q.push(1);

    //find reachable cycle nodes from 1

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if(visited[node]) continue;
        visited[node]=true;

        if(cycle_nodes.count(node)){
            cycle_q.push(node);
        }

        for(int v : adj[node]) {
            if(!visited[v]) q.push(v);
        }

    }

    //check if any cycle node can reach n
    visited.assign(n+1 , false);
bool can_reach = false;
while(!cycle_q.empty()){
    int u = cycle_q.front(); cycle_q.pop();
    if(visited[u]) continue;
    visited[u]=true;

    if(u == n){
        can_reach=true;
        break;
    }
    for(int v : adj[u]){
        if(!visited[v]) cycle_q.push(v);
    }
}

if(can_reach) cout<<-1<<'\n';
else cout<<dist[n]<<'\n';

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