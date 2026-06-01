// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

vector<vector<vector<int>>> dp;

int helper(vector<int> &a, int idx, vector<int> &val, int used, int mx){
    if(idx < 0) return 0;
    if(dp[idx][mx][used] !=-1) return dp[idx][mx][used];

    int res = -4e18;
   

    for(int i = 0; i<5; i++){

        
        int new_used = used + (i != a[idx] );

        if(new_used > 1 ) continue;

        
        // if(i>= mx) mx = i;
        //neg
        int gain = 0;
        if(i < mx) gain = -val[i];
        else gain = val[i];
        res = max(res, gain + helper(a, idx-1, val, new_used, max(i,mx)) );


        
    }
    return dp[idx][mx][used]=res;

}

void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    vector<int> a;
    for(char&ch : s){
        a.push_back(ch-'A');
    }
    vector<int> val = {1,10,100,1000,10000};
    dp.assign(n+1,vector<vector<int>> (5, vector<int>(2,-1)));
    
    int ans = helper(a, n-1, val, 0, 0);
    cout<<ans << '\n';
    
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