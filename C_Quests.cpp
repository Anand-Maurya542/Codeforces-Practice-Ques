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
    vector<int> a(n), b(n);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;

    int ans = 0;
    int maxi = 0;
    int curr = 0;

    for(int i=0; i<n && i<k; i++){
        curr+=a[i];
        maxi=max(maxi, b[i]);
        ans = max(ans, curr + (k-i-1) * maxi);
    }
    cout<<ans<<'\n';
    
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