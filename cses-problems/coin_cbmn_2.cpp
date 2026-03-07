// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()

/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

// vector<vector<int>> dp;
// int helper(vector<int>& nums,int x,int i,int X){
//     if(x>X) return 0;
//     if(x==X) return 1;
//     if(i>=(int)nums.size()) return 0;
//     if(dp[x][i] != -1) return dp[x][i];
//     return dp[x][i]=(helper(nums,x+nums[i],i,X)%MOD+helper(nums,x,i+1,X)%MOD)%MOD;
// }

// void solve()
// {
//     int n, x;
//     cin >> n >> x;
//     dp.assign(x+1,vector<int>(n+1,-1));
//     vector<int> nums(n);
//     read(nums);
//     sort(all(nums));
//     cout<<helper(nums,0,0,x);
    

// }

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    read(coins);

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for(int coin : coins){
        for(int i = coin; i <= x; i++){
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    cout << dp[x] << '\n';
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