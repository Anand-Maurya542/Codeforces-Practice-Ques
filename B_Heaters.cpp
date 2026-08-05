// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, r;
    cin >> n >> r;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int curr = 1;
    int used = 0;

    while (curr <= n)
    {
        int right = min(n, curr + r - 1);
        int left = max(1, curr - r + 1);

        bool found = false;

        for (int i = right; i >= left; i--)
        {
            if (a[i] == 1)
            {
                found = true;
                curr = i + r;
                used++;
                break;
            }
        }
        if (!found)
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << used << '\n';
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