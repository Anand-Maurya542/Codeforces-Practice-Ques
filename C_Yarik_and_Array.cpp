// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    
    int ans = INT_MIN;
    int l=0, r=0;
    int sum = 0;

    while(r<n){
        if(sum<0){
            sum=0;
            l=r;
        }

        if(l<r){
            if((a[r] ^ a[r-1]) & 1){
                sum+=a[r];
            }else{
                sum=a[r];
                l=r;
            }

        }else{
            sum=a[r];
        }

        ans = max(ans, sum);
        r++;


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