// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int a, b, n;
    cin >> a >>b >>n;
    vector<int> v(n);
    for(auto&x:v) cin>>x;

   
    int max_time = b;
    for(int i=0; i<n; i++){
        max_time += min(v[i] , a-1); // i am breaking at 1
    }

    
    cout<<max_time<<'\n';


    
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