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
    int ans = 0;
    vector<int> mp(1e5+1,0);
    int size = 0;
    while(r<n){
        mp[a[r]]++;
        if(mp[a[r]]==1) size++;
        while(size>k){
            mp[a[l]]--;
            if(mp[a[l]]==0) size--;
         
            l++;
        }
        ans += r-l+1;
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