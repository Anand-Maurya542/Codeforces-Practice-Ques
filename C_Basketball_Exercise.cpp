// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

vector<vector<int>> dp;
int n;

int solve(int i, int prevRow, vector<int>& row1, vector<int>& row2){
    if(i==n) return 0;

    if(dp[i][prevRow] !=-1) return dp[i][prevRow];
    
    int take = 0, skip = 0;
    int ans = 0;
    if(prevRow == 2){
        take = row1[i] + solve(i+1, 0, row1, row2);
        ans = max(ans, take);

        take = row2[i] + solve(i+1, 1, row1, row2);
        ans=max(ans, take);

        skip = solve(i+1, 2, row1, row2);
        ans=max(ans, skip);
    }else if(prevRow == 0){
        take = row2[i] + solve(i+1, 1, row1, row2);
        ans=max(ans, take);

        skip = solve(i+1, 2, row1, row2);
        ans=max(ans, skip);

    }else{
        take = row1[i] + solve(i+1, 0, row1, row2);
        ans = max(ans, take);
        skip = solve(i+1, 2, row1, row2);
        ans=max(ans, skip);

    }

    return dp[i][prevRow] = ans;
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;
    vector<int> row1(n), row2(n);
    for(int &x:row1) cin>>x;
    for(int &x:row2) cin>>x;

    dp.assign(n, vector<int>(3,-1));

    int ans = solve(0,2, row1, row2);
    cout<<ans<<'\n';


    return 0;
}