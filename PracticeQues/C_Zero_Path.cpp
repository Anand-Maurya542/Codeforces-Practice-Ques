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
// vector<int>dp;
//dp.assign(n, -1);
void solve()
{
    int n, m;
    cin >> n >>m;
    // if((n+m)%2==0) {
    //     no();return;
    // }
//      if((n + m - 1) % 2 != 0){
//     no();
//     return;
// }
    // int a[n][m];
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    vector<vector<int>>dp1(n,vector<int>(m,1e9)),dp2(n,vector<int>(m,-1e9));
    dp1[0][0]=dp2[0][0]=a[0][0];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i>0 && j>0){
    //         dp1[i][j]=min(dp1[i-1][j],dp1[i][j-1])+a[i][j];
    //         dp2[i][j]=max(dp2[i-1][j],dp2[i][j-1])+a[i][j];}
    //         else if(i>0){
    //             dp1[i][j]=dp1[i-1][j] + a[i][j];
    //             dp2[i][j]=dp2[i-1][j] + a[i][j];
    //         }else if(j>0){
    //             dp1[i][j]=dp1[i][j-1]+a[i][j];
    //             dp2[i][j]=dp2[i][j-1]+a[i][j];
    //         }
    //     }
    // }
    for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(i == 0 && j == 0) continue;

        if(i > 0){
            dp1[i][j] = min(dp1[i][j], dp1[i-1][j] + a[i][j]);
            dp2[i][j] = max(dp2[i][j], dp2[i-1][j] + a[i][j]);
        }
        if(j > 0){
            dp1[i][j] = min(dp1[i][j], dp1[i][j-1] + a[i][j]);
            dp2[i][j] = max(dp2[i][j], dp2[i][j-1] + a[i][j]);
        }
    }
}
    // int mn = dp1[n-1][m-1];
    if(dp1[n-1][m-1]<=0 && dp2[n-1][m-1]>=0 && dp2[n - 1][m - 1] % 2 == 0 ) yes();
    else no();
    
    
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