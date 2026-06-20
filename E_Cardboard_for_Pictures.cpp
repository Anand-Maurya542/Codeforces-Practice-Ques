// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    //n * 4 * x^2 + 4x * sum = k - sum(x^2)
    // (12 * x^2 + 24x )= 36
    // x^2 + 2x = 3
    int lo=1, hi=1e9, ans=-1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;

        int sum = 0;
        for(int& x:a){
            sum += (x+2*mid) * (x+2*mid);
            if(sum > k) break;
        }
       
        if(sum <= k) {
            lo=mid+1;
            ans = mid;
        }
        else hi=mid-1;
    }
    cout<<ans<<'\n';



    
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