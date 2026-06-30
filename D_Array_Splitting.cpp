// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
int n, k;



void solve()
{
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    vector<int> suffix(n+1, 0);
    for(int i=n-1; i>=0; i--){
        suffix[i]=suffix[i+1] + a[i];
    }
    vector<int> contri;
    for(int i=1; i<n; i++) contri.push_back(suffix[i]);

    sort(contri.rbegin(), contri.rend());
    int ans = accumulate(a.begin(),a.end(),0LL);

    for(int i=0; i<k-1;i++){
        ans+=contri[i];
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