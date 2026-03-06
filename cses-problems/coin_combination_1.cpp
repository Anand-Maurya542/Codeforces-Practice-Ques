// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }
template <typename T>
void read(vector<T> &v)
{
    for (auto &x : v)
        cin >> x;
}

template <typename T>
void print(const vector<T> &v)
{
    for (const auto &x : v)
        cout << x << ' ';
    cout << '\n';
}

#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

vector<int> nums, dp;

int helper(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    dp[n]=0;
    for (int i = 0; i < nums.size(); i++)
    {
        dp[n] =(dp[n]+  helper(n - nums[i]))%MOD;
    }
    return dp[n];
}

void solve()
{
    int n, x;
    cin >> n >> x;
    nums.assign(n, 0);
    dp.assign(x + 1, -1);
    read(nums);
    int res = helper(x);
    // if (res == INF)
    //     cout << -1 << '\n';
    // else
        cout << res;
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