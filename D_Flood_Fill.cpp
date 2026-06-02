// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<vector<int>> dp;

int help(vector<int> &a, int l, int r)
{
    if (l >= r)
        return 0;
   
    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = LLONG_MAX;
    if (a[l] == a[r])
    {
        ans = 1 + help(a,l+1, r-1);
    }
    else
        ans = min(ans, 1 + min(help(a, l + 1, r), help(a, l, r - 1)));

    return dp[l][r] = ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> b;

    for (int x : a)
    {
        if (b.empty() || b.back() != x)
            b.push_back(x);
    }
    dp.assign(n, vector<int>(n, -1));

    int ans = help(b, 0, b.size() - 1);

    cout << ans << '\n';
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