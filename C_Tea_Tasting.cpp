// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e18 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> tea(n), tester(n);
    for (int &x : tea)
        cin >> x;
    for (int &x : tester)
        cin >> x;

    vector<int> pre(n);
    pre[0] = tester[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + tester[i];
    }

    vector<int> diff(n + 1, 0);
    vector<int> extra(n, 0);

    for (int i = 0; i < n; i++)
    {
        int need = tea[i];

        if (i > 0)
            need += pre[i - 1];

        int pos = lower_bound(pre.begin(), pre.end(), need) - pre.begin();

        if (pos == n)
        {
            // full tea consumed
            diff[i]++;
            diff[pos]--;
        }
        else
        {
            diff[i]++;
            diff[pos]--;

            int already = 0;
            if (pos > i)
            {
                already += pre[pos - 1];
                if (i > 0)
                    already -= pre[i - 1];
            }
            extra[pos] += tea[i] - already;
        }
    }

    int active = 0;
    for (int i = 0; i < n; i++)
    {
        active += diff[i];
        cout << (active * tester[i] + extra[i]) << ' ';
    }
    cout << '\n';
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