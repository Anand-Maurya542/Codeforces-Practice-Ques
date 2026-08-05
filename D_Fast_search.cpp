// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    sort(a.begin(), a.end());

    int k; cin>>k;

    for(int i=0 ; i<k; i++){
        int l; cin>>l;
        int r; cin>>r;


        auto left = lower_bound(a.begin(), a.end(),l)-a.begin();
        auto right = upper_bound(a.begin(), a.end(), r)-a.begin();
        cout<<right-left<<' ';


        
    }
    cout<<'\n';
    
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