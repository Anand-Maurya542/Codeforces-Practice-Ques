// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    sort(a.begin(), a.end());

    int l = 0, r = 0;
    int ans = 1;
    while(r < n){
        while(r<n && a[r] - a[l] <= 5) r++;

        ans = max(ans, r-l);

        while(l<r && r < n && a[r] - a[l] > 5) l++;

        r++;
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