// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

vector<int> dp;

int noOfWays(int n){

    if(n<0) return 0;
    if(n==0) return 1;

    if(dp[n]!=-1) return dp[n];
    
    dp[n]=0;
    for(int i=1;i<=6;i++){
        dp[n]=(dp[n] + noOfWays(n - i)) % MOD;
    }

    return dp[n];
}

void solve()
{
    int n;cin>>n;
    dp.assign(n+1,-1);
    cout<<noOfWays(n)<<'\n';
    
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