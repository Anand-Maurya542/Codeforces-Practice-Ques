// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int mod = 1e9 + 7;
int n, m;


void helper()
{
    cin >> n >> m;
    vector<int> a(n);
    for(int &x : a) cin>>x;

    vector<vector<int>> dp(n+1, vector<int>(m+2, 0));

    if(a[0] == 0){ //first element 0
        for(int i = 1; i<=m; i++) dp[1][i]=1;
    }else{
        int j = a[0];
        dp[1][j]=1;
    }

    for(int i=2; i<=n ;i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == 0){
                dp[i][j]= (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%mod;
            }else{
                int k = a[i-1];
                dp[i][k] = (dp[i-1][k-1] + dp[i-1][k] + dp[i-1][k+1])%mod; 
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
        ans = (ans + dp[n][i])%mod;
    }
    cout<<ans << '\n';

    


    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        helper();

    return 0;
}