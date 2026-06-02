// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

vector<vector<int>> dp;

int help(vector<int> &a, int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return 1;

    if (dp[l][r] != -1)
        return dp[l][r];

    // Option 1: Destroy the first gemstone by itself
    int ans = 1 + help(a, l + 1, r);

    // Option 2: The first gemstone matches the one right next to it
    if (a[l] == a[l + 1])
    {
        ans = min(ans, 1 + help(a, l + 2, r));
    }

    for (int k = l + 2; k <= r; k++)
    {
        if (a[l] == a[k])
        {
            // Destroy a[l] and a[k] along with the inner palindrome,
            // then destroy the rest of the right side independently.
            int temp = help(a, l + 1, k - 1) + help(a, k + 1, r);
            ans = min(ans, temp);
        }
    }
    return dp[l][r] = ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    dp.assign(n, vector<int>(n, -1));
    cout << help(a, 0, n - 1) << '\n';
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