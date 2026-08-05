// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

bool valid(int side, int w, int h, int n){
    int cols = side/w;
    int rows = side/h; //ek col me itne log aayenge

    //simple logic => cols * rows >= n
    //but to avoid interger overflow , we have done division arithmetic

    if(cols == 0 || rows == 0) return false;

    int needed_col = (n + rows -1)/rows;

    return needed_col <= cols;
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