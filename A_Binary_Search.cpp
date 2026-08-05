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
    for(int i=0; i<k; i++){
        int x; cin>>x;
        auto j = lower_bound(a.begin(), a.end(), x);
        if(j!=a.end()){
            if(*j == x) cout<<"YES"<<'\n';
            else cout<<"NO"<<"\n";
        }else cout<<"NO"<<"\n";
    }
    
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