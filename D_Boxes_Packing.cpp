// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n,m, k;
    cin >> n >> m>> k;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    int j=n-1;
    for(int i=1; i<=m; i++){
        int sum = k;
        while(j>=0 && a[j]<=sum){
            sum-=a[j];
            j--;
        }
    }
    cout<<n-j-1<<'\n';
    
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