// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int&x : a) cin>>x;

    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    dp[1]=abs(a[0]-a[1]);

    for(int i=2; i<n; i++){
        for(int j=i-1; j>=0 && (i-j <= k) ; j--){
            dp[i] = min(dp[i], abs(a[i] - a[j]) + dp[j]);
        }
    }
    cout<<dp[n-1]<<'\n';
    
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