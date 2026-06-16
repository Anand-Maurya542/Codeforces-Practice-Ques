// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    vector<int> pre(n+1);
    pre[0]=0;
    for(int i=0; i<n; i++){
        pre[i+1] = pre[i]+a[i];
    } 
    int total = accumulate(a.begin(), a.end(),0);

    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--; r--;
        
        int sum = pre[r+1] - pre[l];

        int newsum = total - sum + (r-l+1) * k;
        if(newsum&1){
            cout<<"YES"<<"\n";
        }else cout<<"NO"<<'\n';
    }
    
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