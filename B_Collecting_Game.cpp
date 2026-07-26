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
    for(int &x:a) cin>>x;
    
    vector<int> order(n);
    vector<int> arr = a;
    sort(arr.begin(), arr.end());

    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int &i, int &j){
        return a[i] < a[j];
    });

    vector<int> ans(n);

    vector<int> pre(n, 0LL);
    pre[0]=arr[0];
    for(int i=1; i<n; i++){
        pre[i]=pre[i-1] + arr[i];
    }
    for(int i=0; i<n; i++){
        int cnt = i;
        int idx = i;

        while(idx < n){

            auto it = lower_bound(arr.begin(), arr.end(), pre[idx]+1) - arr.begin();
            it--;
            if(it == idx) break; //no new elements found

            cnt += it - idx;
            idx = it;
        }

        ans[order[i]] = cnt;
    }
    for(int &x : ans){
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