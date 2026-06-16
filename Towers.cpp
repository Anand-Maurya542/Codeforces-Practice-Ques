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
    for(int&x :a)cin>>x;

    int cnt = 1;
    vector<int> curr;
    curr.push_back(a[0]);

    for(int i=1;i<n; i++){
        auto it = upper_bound(curr.begin(), curr.end(), a[i]);
        if(it != curr.end()){
            *it = a[i];
        }else curr.push_back(a[i]);

    }
    cout<<curr.size()<<'\n';
    
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