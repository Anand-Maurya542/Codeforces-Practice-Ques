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

// vector<vector<int>>dp;
vector<int>dp;

bool check(int n){
    string s=to_string(n);
    string temp=s;
    reverse(all(s));
    return s==temp;
}
vector<int>nums;
void precompute(){
for(int i=1;i<=1e5;i++){
    if(check(i)) nums.push_back(i);
}
dp.assign(1e5+1,0);

    
    dp[0]=1;
    for(int x:nums){
        
        for(int i=x;i<=1e5;i++){
            dp[i]=(dp[i]+dp[i-x])%MOD;
        }
    }
}
void solve()
{
    int n;
    cin >> n;

    // dp.assign(n+1,vector<int>(n+1,0));
    
    cout<<dp[n]<<'\n';
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    precompute();
    cin >> t;
    while (t--)
        solve();

    return 0;
}