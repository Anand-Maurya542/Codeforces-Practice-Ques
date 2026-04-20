// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;

#define int long long

const long long INF = 1e18;

// BFS that returns full distance array
vector<int> bfs(int start, vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int next : adj[node]) {
            if (dist[next] == -1) {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
    return dist;
}

pair<int,int> bfs_far(int start, vector<vector<int>> &adj) {
    vector<int> dist = bfs(start, adj);
    int far = start;

    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] > dist[far]) {
            far = i;
        }
    }
    return {far, dist[far]};
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Find diameter endpoints
    auto [nodeA, _] = bfs_far(1, adj);
    auto [nodeB, diameter] = bfs_far(nodeA, adj);

    // Get distances from both endpoints
    vector<int> distA = bfs(nodeA, adj);
    vector<int> distB = bfs(nodeB, adj);

    // Compute answers
    for (int i = 1; i <= n; i++) {
        int best = max(distA[i], distB[i]);
        cout << max(diameter, best + 1) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}