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
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        a[i]={x,i};
    }



    sort(a.begin(), a.end());

    vector<int> pre(n);
    pre[0]=a[0].first;
    for(int i=1; i<n; i++){
        pre[i]=pre[i-1]+a[i].first;
    }

    vector<int> ans(n);

    for(int i=0 ;i<n; i++){
        int j=i;
        int found = i; //no of additional elements

        while(j < n){
            pair<int, int> p = {pre[j] + 1, INT_MIN};

            int idx = lower_bound(a.begin(), a.end(), p) - a.begin();

            idx--;
            if(idx == j) break;

            found += idx-j;

            j = idx;
        }

        ans[a[i].second] = found;

    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';

    //1,2,4,5,20
    //1,3,7,12,32
    
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