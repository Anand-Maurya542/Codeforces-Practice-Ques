// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int cnt(vector<int>& a, int x){
    int n = a.size();

    int ans = 0;
    int l = 0, r = n-1;

    while(l<=r){
        if(a[l] + a[r] <= x){
            ans += r-l;
            l++;
        }else r--;
    }
    return ans;

}

void solve()
{
    int n, l,r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    sort(a.begin(), a.end());

    cout<<cnt(a,r) - cnt(a, l-1)<<'\n';

    
    
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