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
    for(int& x: a) cin>>x;
    // vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    // dp[0][0]=1;
    vector<int> dp(k+1, 0);
    dp[0]=1;

    for(int s = 1; s<=k; s++){
        for(int& c :a){
            if(c<=s){
                dp[s]=(dp[s] + dp[s-c])%MOD;
            }
        }
    }
    cout<<dp[k]<<"\n";
    
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