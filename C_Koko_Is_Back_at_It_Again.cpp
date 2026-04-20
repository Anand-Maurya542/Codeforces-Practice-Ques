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
void solve()
{
    int n, k;
    cin >> n >> k;
    if(n==1){
        cout<<0<<" "<<0<<'\n';
        return;
    }
    vector<vector<int>> adj(n);
    vector<int> outdeg(n,0);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        outdeg[u]++;
        // cout<<outdeg[u]<<'\n';
    }
    
    vector<int> vis(n,0);
    queue<int> q;
    int bag=0, eat=0;
    q.push(0);
    vis[0]=1;
    // print(outdeg);
    
    while(!q.empty()){
        int node=q.front(); q.pop();
        vis[node]=1;
        int x=outdeg[node];
         while(x>0){
            int take=min(x, k-bag);
            bag+=take;
            x-=take;

            if(bag==k && x>0){
                eat+=k;
                bag=0;
            }

         }
        
        // cout<<eat<<" "<<bag<<'\n';
        for(int it:adj[node]){
            if(outdeg[it] && !vis[it]){
                q.push(it);
            }

        }
    }
    cout<<eat<<" "<<bag<<'\n';
    
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