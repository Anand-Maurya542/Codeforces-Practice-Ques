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

// #define int long long
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

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
// vector<vector<int>>dp;
// vector<int>dp;
//dp.assign(n, vector<int>(m, -1));
//dp.assign(n, -1);
//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int dir[4][2]={ {1,0},{-1,0}, {0,1}, {0,-1}};      
// vector<vector<int>> adj(n);
void solve()
{
    int n;
    cin >> n ;
    vector<vector<int>> nums(n,vector<int> (2));
    int R=0, C=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<2; j++){
            cin>>nums[i][j];
        }
    }
    for(auto& it:nums){
        int r=it[0];
        int c=it[1];
        R=max(R,r);
        C=max(C,c);
    }

    Disjoint ds(R+C+5);
    
    unordered_set<int> st;
    unordered_set<int> nodes;
    for(auto& it:nums){
        int r=it[0];
        int c=it[1] + R +1;
       ds.unionBySize(r,c);
       nodes.insert(r);
        nodes.insert(c);
        
    }
    unordered_set<int> comps;

for(auto node : nodes){
    comps.insert(ds.findUPar(node));
}
    cout << comps.size() - 1 << '\n';
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