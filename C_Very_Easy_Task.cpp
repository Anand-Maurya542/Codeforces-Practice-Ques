// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
int n, x,y;

bool valid(int t){
    if (t < min(x, y))
        return false;

    t -= min(x,y);
    int a = t/x;
    int b = t/y;

    return a+b >= n-1;
}

void solve()
{
    cin >> n >> x >> y;
    
    int lo = 0, hi = n*max(x,y);
    int ans;

    while(lo<=hi){
        int mid = (lo + hi)/2;
        if(valid(mid)){
            ans = mid;
            hi = mid-1;
        }else lo = mid+1;
    }
    cout<<lo<<'\n';
    
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