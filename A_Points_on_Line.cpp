// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    int ans = 0;
    int r = 0;

    for(int l=0; l<n; l++){
        while(r<n && a[r]-a[l]<=k) r++;
        int len = r-l-1;
        int ways = 0;
        if(len>=2)
         ways = len * (len-1)/2;
        ans += ways;

    }
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