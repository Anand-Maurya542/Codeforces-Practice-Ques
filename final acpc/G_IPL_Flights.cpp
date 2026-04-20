#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'

class DisjointSet{
    public:
    vector<int> rank, parent, size;
        DisjointSet(int n){
            rank.resize(n+1, 0); //declaring n+1 works both 0 based indexing and 1 base indexing
            size.resize(n+1, 1); //declaring n+1 works both 0 based indexing and 1 base indexing
            parent.resize(n+1);
            for(int i=0;i<n+1;i++){
                parent[i] = i;
            }
        }

        int findUltimateParent(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);

            if(ulp_u==ulp_v)return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_v]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);

            if(ulp_u==ulp_v)return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_u] = size[ulp_u]+size[ulp_v];
            }
            else if(size[ulp_u] >= size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_v] = size[ulp_u]+size[ulp_v];
            }
        }

};

void solve() {
    int n;
    cin >> n;

    DisjointSet ds(n);

    vector<pair<int,int>> mark;

    for(int i=0;i<n-1;i++){
        int a;
        int b;
        cin>>a;
        cin>>b;

        if(ds.findUltimateParent(a)!=ds.findUltimateParent(b)){
            ds.unionBySize(a, b);
        }
        else{
            mark.push_back({a,b});
        }

    }
    unordered_set<int> st;
    for(int i=1;i<=n; i++){
        st.insert(ds.findUltimateParent(i));
    }
    int cnt=st.size()-1;
    cout<<cnt<<'\n';
    if(st.size()==1) return;
    vector<int> a;
    for(auto& it:st){
        a.push_back(it);
        // cout<<*it<<' ';
    }
    int i=0,j=0;
    while(i<mark.size() && j<a.size()){
        cout<<mark[i].first<<' '<<mark[i].second<<' '<<a[j]<<' '<<a[j+1]<<'\n';
        i++;j++;
    }
    
  

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}