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



int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int mul=j;mul<=n;mul+=j){
                dp[i][j]=(dp[i][j]+dp[i-1][mul])%MOD;
            }
        }
    }
    int sum=0;
    for(int i=0;i<=n;i++){
        sum=(sum+dp[k][i])%MOD;
    }
    cout<<sum<<'\n';

    

    return 0;
}