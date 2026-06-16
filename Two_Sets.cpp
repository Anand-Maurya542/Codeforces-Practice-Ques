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
    int sum = n*(n+1)/2;
    if(sum&1){
        cout<<"NO"<<'\n';
        return;
    }
    vector<int> set1, set2;
    int target = sum/2;

    int sum1= 0;
    for(int i=n; i>=1; i--){
        if(sum1 + i <= target){
            sum1+=i;
            set1.push_back(i);
        }else set2.push_back(i);
    }
    cout<<"YES"<<'\n';
    cout<<set1.size()<<'\n';
    for(int &x : set1){
        cout<<x<<' ';
    }
    cout<<'\n';
    cout<<set2.size()<<'\n';
    for(int &x : set2){
        cout<<x<<' ';
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