// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int max_n = 1e6;

vector<vector<int>> dp(max_n+1, vector<int>(2,0));





int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2; i<=max_n; i++){
        dp[i][0]=(4*dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][1]=(2*dp[i-1][1] + dp[i-1][0])%MOD;
    }
    
    int t = 1;
    cin >> t;
    while (t--)
        {
            int n;
            cin>>n;
            cout<< ( dp[n][0] + dp[n][1]) % MOD << '\n';
        }

    return 0;
}