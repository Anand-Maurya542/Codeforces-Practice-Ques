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
    vector<int> a(n);
    for(int &x:a) cin>>x;
    sort(a.begin(), a.end());
    
    int cnt = 0;
    int curr = 1;
    for(int i=1; i<n;i++){
        if(a[i] - a[i-1] <= k) curr++;
        else{
            cnt=max(cnt, curr);
            curr=1;
        }
    }
    cnt=max(cnt, curr);
    cout<<n-cnt<<'\n';
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