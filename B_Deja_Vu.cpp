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
    vector<int> a(n), b(k);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;

    int mini = 31;
    for(int i = 0; i<k; i++){
        if(b[i] >= mini) continue;
        mini = b[i];
        int val = pow(2, mini);
        for(int &x : a){
            if(x%val==0){
                x += val/2;
            }
        }
    }
    for(int& x : a) {
        cout<<x<<' ';
    }
    cout<<'\n';
    
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