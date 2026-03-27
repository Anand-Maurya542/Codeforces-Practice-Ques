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

void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n+1,false),a(n+1);
    dp[0]=true;

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(dp[i-1] && i+x<=n) dp[i+x]=true;  //forward/right marking
        if(i-x>=1 && dp[i-x-1]) dp[i]=true;  //backward/left marking
    }
    if(dp[n]) yes();
    else no();

    
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