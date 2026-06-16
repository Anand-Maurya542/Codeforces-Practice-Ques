// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> pre(n), suffix(n);
    pre[0] = a[0];
    suffix[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] | a[i];
    }
    long long p = 1;
    for (int j = 0; j < k; j++)
        p *= x;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int orr = a[i] * p;
        orr |= i ? pre[i - 1] : 0;
        orr |= i < n - 1 ? suffix[i + 1] : 0;
        res = max(res, orr);
    }
    cout << res << '\n';
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