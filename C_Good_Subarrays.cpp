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
    string s;
    cin >> s;

    long long ans = 0;

    unordered_map<long long, long long> mp;

    mp[0] = 1;

    long long prefix = 0;

    for (int i = 1; i <= n; i++)
    {

        prefix += (s[i-1] - '0');

        long long key = prefix - i;

        ans += mp[key];

        mp[key]++;
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