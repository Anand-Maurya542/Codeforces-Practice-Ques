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
    for(int&x : a) cin>>x;

    int maxi = LLONG_MIN;
    int sum = 0;
    for(int &x : a){
        sum += x;

        maxi = max(maxi, sum);
        if(sum < 0) sum = 0;
    }
    cout<<maxi<<'\n';
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