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

    for(int &x : a){
        if(x==1) x++;
    }
    for(int i=1; i<n; i++){
        if(a[i]%a[i-1] == 0) a[i]++;
    }
    for(int& x:a) cout<<x<<" ";
    cout<<'\n';
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