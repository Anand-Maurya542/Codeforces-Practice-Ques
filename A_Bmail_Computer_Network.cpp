// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
// vector<vector<int>>dp;
// vector<int>dp;
//dp.assign(n, vector<int>(m, -1));
//dp.assign(n, -1);
void solve()
{
    int n;
    cin >> n ;
    vector<int> a(n+1);
    a[1]=1;
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    int idx=n;
    vector<int> ans;
    ans.push_back(n);
    while(a[idx]!=idx){
        ans.push_back(a[idx]);
        idx=a[idx];

    }
    // ans.push_back(1);
    reverse(all(ans));
    print(ans);    
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