// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n);
    for(int i=0; i<n; i++){
        int wtt, v;
        cin>>wtt >> v;
        wt[i]=wtt;
        val[i]=v;

    }

    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(wt[i-1] <= j){
                dp[i][j]=max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
            }else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][w]<<'\n';
    
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