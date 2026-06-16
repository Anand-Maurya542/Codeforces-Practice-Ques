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
    vector<char> s(n);
    for(char &x:s) cin>>x;

    int len = 0;
    int curr = 1;
    for(int i=1; i<n;i++){
        if(s[i] == s[i-1]) curr++;
        else{
            len = max(curr, len);
            curr=1;
        }
    }
    len=max(len, curr);
    cout<<len+1<<'\n';
    
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