// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

vector<int> dp;

int f(vector<int>& a, int i){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans = INT_MAX;
    
    if(i>0) ans = min(ans, abs(a[i] - a[i-1]) + f(a, i-1));
    if(i>1) ans = min(ans, abs(a[i] - a[i-2]) + f(a, i-2));
    return dp[i]=ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin>>x;

    dp.assign(n+1, -1);

    int ans = f(a, n-1);
    cout<<ans<<'\n';
    
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