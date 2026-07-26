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
    int maxi = *max_element(a.begin(), a.end());
    int mini = *min_element(a.begin(), a.end());
    
    if(maxi == mini ){
        cout<<0<<'\n';
        return ;
    }

    unordered_set<int> st;
    for(int i=1; i*i <= n; i++){
        if(n%i == 0){
            st.insert(i);
            st.insert(n/i);
        }
    }

    vector<int> pre(n+1,0);
    for(int i=0; i<n; i++){
        pre[i+1]=pre[i]+a[i];
    }

    int ans = 0;

    for(int k : st){
        int maxi = LLONG_MIN;
        int mini = LLONG_MAX;
        
        int l = 0, r = k-1;
        while(r<n){
            int sum = pre[r+1] - pre[l];
            maxi=max(maxi, sum);
            mini=min(mini, sum);

            l+=k;
            r+=k;
        } 
        ans = max(ans, maxi - mini);
    }
    cout<<ans<<'\n';


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