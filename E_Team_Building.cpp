// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long NEG = -(long long)4e18;

void solve()
{
    int n,p, k;
    cin >> n >>p>> k;
    vector<int> a(n);
    for(int&x : a) cin>>x;
    vector<vector<int>> s(n, vector<int>(p));
    for(auto& v :s){
        for(int& x:v) cin>>x;
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y){
        return a[x] > a[y];
    });

    vector<int> dp(1<<p,NEG);
    dp[0]=0;

    //for every person
    for(int idx = 0 ; idx < n; idx++){
        int i = order[idx];
        vector<int> newdp = dp;

        for(int mask = 0; mask < (1<<p); mask++){
            if(dp[mask]==NEG) continue;

            int players_used = __builtin_popcount(mask);
            int audience_used = idx - players_used;

            if(audience_used < k){
                newdp[mask] = max(newdp[mask], dp[mask] + a[i]);
            }

            //try positions
            for(int j=0; j<p; j++){
                if(!(mask & (1<<j))){
                    int newmask = mask | (1<<j);
                    newdp[newmask] = max(newdp[newmask] , dp[mask]+s[i][j]);
                }
            }
        }
        dp = newdp;


    }

    cout<<dp[(1<<p)-1];


    
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