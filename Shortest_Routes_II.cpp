// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
//#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const ll inf = 1e18;

int n, m,q;
vector<vector<ll>> dist;
// vector<ll> dist;
const vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void solve()
{
 cin >> n >> m >> q;
 dist.assign(n, vector<ll>(n, inf));


for(int i = 0; i < n; i++)
    dist[i][i] = 0;
//  dist.assign(n+1, inf);
   for (int i = 0; i < m; i++){
      ll u, v, c;
      cin>>u>>v>>c;
      u--;v--;
     dist[u][v] = min(dist[u][v], c);
    dist[v][u] = min(dist[v][u], c);
     
    }

     for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] != inf && dist[k][j] != inf){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
     }

     for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        cout<< ((dist[a][b]==inf) ? -1 : dist[a][b])<<'\n';
     }


    
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