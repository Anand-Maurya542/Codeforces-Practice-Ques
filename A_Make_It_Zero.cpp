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
    for(int&x:a) cin>>x;
    if(n%2==0){
        cout<<2<<'\n';
        cout<<1<<' '<<n<<'\n';
        cout<<1<<' '<<n<<'\n';
    }else{
        cout<<4<<'\n';
        cout<<1<<' '<<n-1<<'\n';
        cout<<1<<' '<<n-1<<'\n';
        cout<<n-1<<' '<<n<<'\n';
        cout<<n-1<<' '<<n<<'\n';
        
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