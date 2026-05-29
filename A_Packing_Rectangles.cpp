// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

bool valid(int x, int w, int h, int n){
    int max_w = x/w;
    int max_h = x/h;
    if(max_w ==0 || max_h == 0) return false;
    return max_w >= (n+max_h-1)/max_h;
}

void solve()
{
    int w, h, n;
    cin >> w >> h >> n;

    int lo =1;
    int hi = max(w, h) * n;
    int ans;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;

        if(valid(mid, w, h, n)){
            ans = mid;
            hi = mid -1;
        }else lo = mid+1;
    }
    cout<<ans<<'\n';
    
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