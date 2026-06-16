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

    vector<int> s,t;
    s.push_back(INT_MAX);
    t.push_back(INT_MAX);

    int cnt = 0;

    for(int &num : a){
        if(num <= s.back() && num <= t.back()){
            if(s.back() <= t.back()) s.push_back(num);
            else t.push_back(num);
        }else if(num > s.back() && num > t.back()){
            cnt++;
            if(s.back() <= t.back()) s.push_back(num);
            else t.push_back(num);

        }else{
            if(num <= s.back()) s.push_back(num);
            else t.push_back(num);
        }

    }
    cout<<cnt<<'\n';
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