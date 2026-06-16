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

    int i=0, j=n-1;
    int cnt = 0;

    while(i<=j){
        if(a[i] + a[j] <= k) {
            i++; j--;
        }else j--;
    
        cnt++;
    }
    cout<<cnt<<'\n';

    
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