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

    set<int> st;
    vector<int> cnt(k+1,0);
    for(int i=0; i<=k; i++){
        st.insert(i);
    }

    for(int i=0; i<k; i++){
        if(a[i] <= k){
        if(st.count(a[i])) st.erase(a[i]);
        cnt[a[i]]++;
        }
    
    }
    
    cout<<*st.begin()<<' ';

    for(int i=k; i<n; i++){
        int prev = a[i-k];
        int curr = a[i];

        if(prev <=k){
            cnt[prev]--;
            if(cnt[prev] == 0)
            st.insert(prev);
        }
        if(curr <= k){
            st.erase(curr);
            cnt[curr]++;
        }
        cout<<*st.begin()<<' ';
    }
    cout<<'\n';

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