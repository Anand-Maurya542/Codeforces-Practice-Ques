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

    int l = 0 , r = 0;
    int ans = 0, sum = 0;
    while(r<n){
        sum += a[r];
        while(l<n && sum>=k){
            ans += n-r;
            sum-= a[l];
            l++;
        }
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