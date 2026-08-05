// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

bool valid(double mid,vector<int> &a, int k ){
    int cnt = 0;

    for(auto& x : a){
        cnt += (int)x/mid;
        if(cnt >= k) return true;
    }
    return cnt>=k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x:a) cin>>x;

    double lo = 0;
    double hi = *max_element(a.begin(), a.end());
    double ans;

    while(hi - lo > 1e-6){
        double mid = lo + (hi-lo)/2;
        if(valid(mid, a, k)){
            ans = mid;
            lo = mid;
        }else hi = mid;

    }
    cout<<fixed<<setprecision(6)<<lo<<'\n';
    
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