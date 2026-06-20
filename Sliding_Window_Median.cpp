// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void rebalance(multiset<int>& left, multiset<int>& right){
    while(right.size() > left.size()){
        auto it = right.begin();
        left.insert(*it);
        right.erase(it);
    }
    while(left.size() > right.size()+1){
        auto it = prev(left.end());
        right.insert(*it);
        left.erase(it);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    multiset<int> left, right;

    for(int i=0; i<k; i++){
        int x = a[i];
        if(left.empty() || x <= *left.rbegin() ) left.insert(x);
        else right.insert(x);

        rebalance(left, right);
    }
    cout<<*left.rbegin()<<' ';

    for(int i=k; i<n; i++){
        int curr = a[i];
        int prev = a[i-k];

        if(!left.empty() && curr <= *left.rbegin()) left.insert(curr);
        else right.insert(curr);

        if(!left.empty() && prev <= *left.rbegin()) left.erase(left.find(prev));
        else right.erase(right.find(prev));

        rebalance(left, right);

        cout<<*left.rbegin()<<' ';

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