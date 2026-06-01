// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(auto& v : a){
        for(int& x: v) cin>>x;
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cin>>a[i][j];
    //     }
    // }

    vector<int> dp(1<<n, 0);
    dp[0]=1;

    for(int mask = 0; mask < (1<<n); mask++){
        int i = __builtin_popcount(mask);

        if(i>=n) continue;
        //all men assigned

        if(dp[mask] == 0) continue; //state unreachable

        for(int j=0; j<n; j++){
            if(!(mask & (1<<j)) && a[i][j]==1){
                int newmask = mask|(1<<j);
                dp[newmask] = (dp[newmask] + dp[mask])%MOD;
            }
        }
    }
    cout<< dp[(1<<n)-1]<<'\n';
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