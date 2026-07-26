// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
bool valid(int mid, int n){
    int cnt = 0;
    for(int i=1; i<=n; i++){
        cnt += min(n, mid/i);

    }

    return cnt >= (n*n + 1)/2;
}

void solve()
{
    int n;
    cin >> n ;

    int lo = 1, hi = n*n;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(valid(mid, n)){
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