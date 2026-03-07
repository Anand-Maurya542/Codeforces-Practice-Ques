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

vector<int> dp;
int f(vector<int>& nums,int x){
    if(x<0) return 1e9;
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    
    dp[x]=1e9;
    for(int coin:nums){
        dp[x]=min(dp[x],1+f(nums,x-coin));
    }
    return dp[x];

}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    read(nums);
    dp.assign(x+1,-1);
    int res=f(nums,x);
    if(res==1e9) cout<<-1<<'\n';
    else cout<<res;

    
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