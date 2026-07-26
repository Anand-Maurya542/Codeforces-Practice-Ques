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
    string s;
    cin>>s;

    unordered_set<char> st;
    st.insert(s[0]);
    int ans = 1;
    for(int i=1; i<n; i++){
        st.insert(s[i]);

        ans += st.size();
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