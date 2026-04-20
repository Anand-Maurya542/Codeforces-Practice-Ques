// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
// vector<vector<int>>dp;
// vector<int>dp;
//dp.assign(n, vector<int>(m, -1));
//dp.assign(n, -1);
class Disjoint {
    public:
    vector<int> rank, parent, size;
    int components;
    Disjoint(int n){
        components=n;
        rank.assign(n+1,0); //1 based
        parent.assign(n+1,0);
        size.assign(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
        // path compression
    }

    bool unionByRank(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u == ulp_v) return false ;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] <rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        components--;
        return true;
        
    }
    
    bool unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u == ulp_v) return false ;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v];
        }
        components--;
        return true;

        
    }
    bool isConnected(){
        return components==1;
    }

};


int maxedge(vector<tuple<int,int,int>> &edges,int n){
    Disjoint alice(n), bob(n);
    int used_edges=0;
    for(auto &[p,u,v]:edges){
        if(p==3){
            if(alice.unionBySize(u,v) | bob.unionBySize(u,v))
                used_edges++;
        }else if(p==1){
            if(alice.unionBySize(u,v)) used_edges++;
        }else if(p==2){
            if(bob.unionBySize(u,v)) used_edges++;
        }        
    }
    if(alice.isConnected() && bob.isConnected()) return (int)edges.size()-used_edges;
    return -1;

}

void solve()
{
    int n, e;
    cin >> n >> e;
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<e;i++){
        int path, u,v;
        cin>>path>>u>>v;
        edges.push_back({path,u,v});
    }
    sort(edges.rbegin(),edges.rend());
    cout<<maxedge(edges,n)<<"\n";

    
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