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
    vector<tuple<int,int,int>> edges(m);
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
       
    }

    vector<int> dist(n + 1, 0);
    vector<int> relaxant(n+1);
   

    //bellman ford
    int x =-1;
    for (int i = 0; i < n; i++)
    {   x=-1;
        for (auto [u, v ,wt] : edges)
        {

            if (dist[u] != LLONG_MIN && dist[u] + wt < dist[v])
            {
                dist[v] = wt + dist[u];
                relaxant[v]=u;
                x=v;
            }
        }
    }
    
    if(x==-1) {
        cout<<"NO"<<"\n";
        return;
    }

    //move x in cycle
    for(int i=0; i<n; i++){
        x = relaxant[x];
    }

    vector<int> cycle;
    int curr = x;
    for(int curr = x ;;curr=relaxant[curr]){
        cycle.push_back(curr);
        if(curr == x && cycle.size()> 1) break;
    }
    cout<<"YES"<<"\n";
    reverse(cycle.begin(), cycle.end());
    for(int c : cycle) cout<<c << ' ';
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