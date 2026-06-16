// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

vector<vector<int>> dp;
int solve(vector<int>& nums, int i, int j){
    if(i>j) return 0;
    if(i==j) return nums[i];
    if(dp[i][j]!=-1) return dp[i][j];

    int first = nums[i] + min(solve(nums, i+2, j), solve(nums, i+1, j-1));
    int second = nums[j] + min(solve(nums, i+1, j-1), solve(nums,i, j-2 ));

    return dp[i][j]=max(first, second);
}

void helper()
{
    int n;
    cin >> n ;
    vector<int> nums(n);
    dp.assign(n+1, vector<int>(n+1));

    for(int& x : nums) cin>>x;
    
    for(int g= 0 ; g<n; g++){
        for(int i=0, j=g; j<n; i++, j++){
            if(g==0) dp[i][j]=nums[j];
            else if(g==1) dp[i][j]=max(nums[i], nums[j]);
            else {
                int val1 = nums[i] + min(dp[i+2][j], dp[i+1][ j-1]);
                int val2 = nums[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j]=max(val2, val1);
            }
        }
    }

    cout<<dp[0][n-1]<<"\n";
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