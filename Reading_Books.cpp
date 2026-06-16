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
    int sum = 0;
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        sum+=x;
        maxi=max(maxi, x);
    }
    cout<<max(sum, 2 * maxi) << '\n';
    
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