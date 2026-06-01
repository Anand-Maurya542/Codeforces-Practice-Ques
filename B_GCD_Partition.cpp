// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int&x : a) cin>>x;
    int sum = accumulate(a.begin(), a.end(),0LL);
    int ans = 0;
    int temp = 0;
    for(int i =0 ; i<n-1; i++){
        temp+=a[i];
        sum-=a[i];
        ans = max(ans, __gcd(temp, sum));

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