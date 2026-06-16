// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;

    int m; cin>>m;

    vector<int> price(m);
    vector<string> type(m);

    for(int i=0; i<m; i++){
        int p; string t;
        cin >> p;
        cin>>t;
        price[i] = p;
        type[i]=t;
    }

    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j){
        return price[i] < price[j];
    });

    int cnt = 0;
    int cost = 0;

    for(int k=0; k<m; k++){
        int i = order[k];

        string t = type[i];
        int p = price[i];

        if(t == "USB" && a>0){
            a--; cnt++; cost+=p;
        }else if(t == "PS/2" && b>0){
            b--; cnt++; cost+=p;
        }else if(c>0) {
            c--; cnt++; cost+=p;
        }
    }
    cout<<cnt<<' '<<cost<<'\n';
    
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