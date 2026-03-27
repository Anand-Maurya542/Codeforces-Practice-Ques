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

vector<int> dp(1e3+1,INT_MAX);
void pre(){
    dp[1]=0;
    for(int bi=1;bi<=1e3;bi++){
        for(int x=1;x<=bi;x++){
            int val=bi+bi/x;
            if(val<=1e3)
            dp[val]=min(dp[val],1+dp[bi]);
        }
    }

}


void solve()
{
    int n, ops;
    cin >> n >> ops;
    vector<int> bi(n),val(n),wt(n);read(bi);read(val);

    ops=min(ops,1200);
    vector<vector<int>>dpp(n+1,vector<int>(ops+1,0));
    for(int i=0;i<n;i++){
        wt[i]=dp[bi[i]];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=ops;j++){
            int take=0,skip=0;
            if(wt[i-1]<=j) take=val[i-1]+dpp[i-1][j-wt[i-1]];
            skip=dpp[i-1][j];
            dpp[i][j]=max(take,skip);
        }
    }
    cout<<dpp[n][ops]<<'\n';



    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    pre();
    while (t--)
        solve();

    return 0;
}