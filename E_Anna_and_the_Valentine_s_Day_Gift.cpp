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
    vector<string> a(n);
    for(string &x:a) cin>>x;
    
    vector<int> zero;
    int total=0;
    for(string& s : a){
        // string s = to_string(x);
        // cout<<s<<'\n';
        int sz = s.size();
        total+=sz;
        int j=sz-1;
        int cnt=0;
        while(s[j]=='0'){
            cnt++;
            j--;
        }
        zero.push_back(cnt);
    }
    sort(zero.rbegin(), zero.rend());

    int sum = 0;
    for(int i=0; i<n; i+=2){
        sum+=zero[i];
    }
    int ans = total - sum;
    if(ans > k)cout<<"Sasha"<<'\n';
    else cout<<"Anna"<<'\n';

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