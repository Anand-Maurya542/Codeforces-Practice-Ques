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
    
    int l=0, r=n-1;
    bool found = false;
    while(l<n && a[l]==0) l++;
    while(r>=0 && a[r]==0) r--;

    for(int i=l; i<=r; i++){
        if(a[i]==0){
            found = true;
            break;
        }
    }

    if(l>r) cout<<0<<'\n';
    else if(!found) cout<<1<<'\n';
    else if(found) cout<<2<<'\n';


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