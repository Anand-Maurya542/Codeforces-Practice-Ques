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
    vector<int> a(n),b(k);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;

    int i=0, j=0;
    while(i<n & j<k){
        if(a[i]<b[j]) i++;
        else{
            cout<<i<<' ';
            j++;
        }
    }
    while(j++<k) cout<<n<<' ';
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