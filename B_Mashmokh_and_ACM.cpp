// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> factors(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                factors[i].push_back(j);
                if (i / j != j)
                {
                    factors[i].push_back(i / j);
                }
            }
        }
    }

    int dp[k + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 0;
            for (int f : factors[j])
            {

                dp[i][j] = (dp[i][j] + dp[i - 1][f]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[k][i]) % MOD;
    }
    cout << ans << "\n";
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