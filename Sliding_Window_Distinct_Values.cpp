// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    int l = 0;

    map<int, int> mp;
    for(int r = 0; r<n; r++){
        mp[a[r]]++;
        if(r-l+1 > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        if(r-l+1 == k) cout<<mp.size()<<' ';
    }
    cout<<'\n';
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