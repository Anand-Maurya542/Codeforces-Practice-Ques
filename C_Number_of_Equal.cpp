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

    map<int,int> a,b;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        b[x]++;
    }
    int cnt=0;
    auto i = a.begin();
    auto j = b.begin();

    while(i!=a.end() && j!=b.end()){
        if(i->first == j->first){
            cnt += i->second * j->second;
            i++; j++;
        }else if(i->first < j->first) i++;
        else j++;
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