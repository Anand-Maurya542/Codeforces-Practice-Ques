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
int find_level(vector<int>& parent, vector<int> &level, int node){
    if(node==0) return 0;
    if(level[node]!=0) return level[node];
    return 1+find_level(parent, level,parent[node] );
}
void solve()
{
    int n;
    cin >> n;
    vector<int> parent(n+1);
    vector<int> level(n+1,0);
    for(int i=1;i<n;i++){
        int par,child;
        cin>>par>>child;
        parent[child]=par;
        // cout<<parent[child]<<' ';
        
    }
    // cout<<'\n';
    level[0]=0;

    int ans=1;
    for(int node=1; node<=n; node++){
        level[node]=find_level(parent,level,node);
        ans=max(ans,level[node]);
    }
    // print(parent);
    // print(level);
    cout<<ans-1<<'\n';

    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}