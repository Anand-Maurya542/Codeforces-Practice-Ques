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
    
    int x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<int> v(n);
    v[0]=x;

    for(int i=1; i<n; i++){
        v[i]=(v[i-1]*a + b)%c;
    }
    vector<int> sum;
    int s = 0;
    for(int i=0; i<k; i++){
        s += v[i];
    }
    sum.push_back(s);
    
    int r=k, l=0;
    while(r<n){
        s -= v[l];
        s += v[r];
        sum.push_back(s);
        r++;
        l++;

    }
    int ans = 0;
    for(int &x : sum) ans^=x;
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