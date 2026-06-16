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
    vector<int> s(n),e(n);
    for(int i=0; i<n; i++){
        int st, en;
        cin>>st>>en;
        s[i]=st; e[i]=en;
    }

    vector<int>order(n);
    iota(order.begin(), order.end(),0);
    sort(order.begin(), order.end(),[&](int i, int j){
        return e[i] < e[j];
    });
    int cnt = 0;

    int curr_ending = 0;

    for(int i=0; i<n; i++){
        int idx = order[i];

        if(s[idx] >= curr_ending){
            curr_ending = e[idx];
            cnt++;
        }
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