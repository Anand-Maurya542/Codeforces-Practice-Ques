// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
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

// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
// vector<vector<int>>dp;
vector<int> dp;
// dp.assign(n, vector<int>(m, -1));
// dp.assign(n, -1);
int f(string &s, int ind)
{
    if (ind >= s.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    vector<int> v(26, 0);
    ll cnt = 0;
    for (int j = ind; j < s.size(); j++)
    {
        if (v[s[j] - 'a'])
            continue;
        v[s[j] - 'a'] = 1;
        cnt = (cnt + 1 + f(s, j + 1)) % MOD;
    }
    return dp[ind] = cnt;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    dp.assign(n, 0);

    // int ans = f(s, 0);
    // cout << ans+1 << '\n';

    for (int ind = n-1; ind >= 0; ind--)
    {
        vector<int> v(26, 0);
        ll cnt = 0;
        for (int j = ind; j <=n-ind+1; j++)
        {
            if (v[s[j] - 'a'])
                continue;
            v[s[j] - 'a']=1;
            cnt = (cnt + 1 + dp[ j + 1]) % MOD;
        }
         dp[ind] = cnt;
    }
    cout<<dp[0]+1<<'\n';
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