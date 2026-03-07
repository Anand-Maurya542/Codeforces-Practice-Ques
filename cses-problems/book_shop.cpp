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

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n),value(n);
    read(price);read(value);
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            int take=0;
            if(price[i-1]<=j){
                take=dp[i-1][j-price[i-1]]+value[i-1];
            }
            int skip=dp[i-1][j];
            dp[i][j]=max(take,skip);
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=x;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[n][x];
    
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