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

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
// vector<vector<int>>dp;
// vector<int>dp;
//dp.assign(n, vector<int>(m, -1));
//dp.assign(n, -1);
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);read(a);
    vector<int> dp(d+1,1e9);dp[0]=0;
    sort(all(a));
    for(int i=1;i<=d;i++){
        for(int j=n-1;j>=0;j--){
            if(a[j]<=i){
                dp[i]=min(dp[i],1+dp[i-a[j]]);
            }
        }

    }
    if(dp[d]<1e9)
    cout<<dp[d]<<'\n';
    else cout<<-1<<'\n';
    // cout<<(dp[d]!=1e9)?dp[d]:-1<<'\n';

    
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