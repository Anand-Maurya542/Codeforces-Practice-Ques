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
    vector<int> m(n);
    for (int &x : m)
        cin >> x;

    int best = 0;
    vector<int> ans;

    for (int peak = 0; peak < n; peak++)
    {

        vector<long long> a(n);

        a[peak] = m[peak];

        for (int i = peak - 1; i >= 0; i--)
            a[i] = min((long long)m[i], a[i + 1]);

        for (int i = peak + 1; i < n; i++)
            a[i] = min((long long)m[i], a[i - 1]);

        long long sum = 0;

        for (auto x : a)
            sum += x;

        if (sum > best)
        {
            best = sum;
            ans = a;
        }
    }

    for(int & x : ans){
        cout<<x<<" ";
    }
    cout<<'\n';
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