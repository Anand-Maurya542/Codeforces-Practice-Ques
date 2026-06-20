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

    vector<int> v(n+1,0);
    v[1]=x;

    for(int i=2; i<= n; i++){
        v[i]=(v[i-1]*a + b)%c;
    }
    
    vector<int> prefix(n+1,0), suffix(n+2,0);


    for(int i=1 ; i<=n; i++){
        if((i-1) % k == 0) prefix[i]=v[i];
        else prefix[i] = prefix[i-1] | v[i];
    }


    for(int i=n; i>=1; i--){
        if(i%k == 0) suffix[i]=v[i];
        else suffix[i]=suffix[i+1] | v[i];

    }

    int ans = 0;
    for(int i=k; i<=n; i++){
        if(i%k == 0) ans^= prefix[i];
        else 
        ans^= prefix[i] | suffix[i-k+1];
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