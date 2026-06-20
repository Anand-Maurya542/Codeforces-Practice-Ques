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

    set<pair<int,int>> st;
    map<int, int> mp;

    int l=0;
    for(int r=0; r<n; r++){
        if(mp.count(-a[r])) st.erase({mp[-a[r]],-a[r]});
        mp[-a[r]]++;
        st.insert({ mp[-a[r]], -a[r]});

        if(r-l+1 > k){
            st.erase({mp[-a[l]], -a[l]});
            mp[-a[l]]--;
            if(mp[-a[l]] == 0){
                mp.erase(-a[l]);
            }else st.insert({mp[-a[l]], -a[l]});
            l++;
        }
        if(r-l+1 == k)
        cout<<-st.rbegin()->second<<" ";
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