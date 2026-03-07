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
vector<vector<int>> dp;
// int f(vector<int> & nums,int i,int x){
//     if(x<0) return 0;
//     if(x==0) return 1;
//     if(i>=nums.size()) return 0;
//     if(dp[i][x]!=-1) return dp[i][x];
//     dp[i][x]=0;
//     for(int j=i;j<nums.size();j++){
//         dp[j][x]=(dp[j][x]+f(nums,j,x-nums[j])%MOD+f(nums,j+1,x)%MOD)%MOD;
//     }
//     return dp[i][x];
// }
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);read(nums);
    sort(all(nums));
    dp.assign(n,vector<int>(x+1,-1));
    
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