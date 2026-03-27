// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
vector<vector<int>> dp;

int n;
int helper(vector<vector<int>>& nums,int i,int j){
    if(i>=n || j>=n) return 0;
    if(i==n-1 && j==n-1) return nums[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int right=nums[i][j]+helper(nums,i,j+1);
    int down=nums[i][j]+helper(nums,i+1,j);
    return dp[i][j]=max(down,right);
}
void solve()
{
    cin >> n ;
    dp.assign(n+1,vector<int>(n,-1));
    vector<vector<int>> nums(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    cout<<helper(nums,0,0)<<"\n";

    
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