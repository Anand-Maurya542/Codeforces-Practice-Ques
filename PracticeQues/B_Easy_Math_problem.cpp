// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
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

vector<int> dp;

int f(int x){
    if(x<=4) return x;
    if(dp[x]!=-1) return dp[x];

    if((x&1)){
        return dp[x]=f(x-1)+f(x-2)-f(x-3);
    }
    else return dp[x]=f(x-1)-f(x-2)+f(x-3);
}
void solve()
{
    int x;
    cin >> x ;
    dp.assign(x+1,-1);
    cout<<f(x)<<'\n';
    
    
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