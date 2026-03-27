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

// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(d,vector<int>(2,0)));
    for(int i=0;i<n;i++) dp[i][0][0]=dp[i][0][1]=1;

    for(int j=1;j<d;j++){
        for(int i=n-1;i>=0;i--){
            int v1=1,v2=1;
            if(i+1<n) v1=dp[i+1][j][1];  //right-1
            if(i-1>=0) v2=dp[i-1][j-1][0];
            dp[i][j][1]=(v2+v1)%MOD;
        }
        for(int i=0;i<n;i++){
            int v1=1,v2=1;
            if(i-1>=0) v1=dp[i-1][j][0];
            if(i+1<n) v2=dp[i+1][j-1][1];
            dp[i][j][0]=(v2+v1)%MOD;
        }
    }
    cout<<dp[0][d-1][1]<<"\n";


    
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