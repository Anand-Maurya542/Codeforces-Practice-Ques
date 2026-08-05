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
    for (int &x : a)
        cin >> x;

    long long ans = 0;
    int l = 0;
    deque<int> maxdq, mindq;
    for(int r=0; r<n; r++){
        //increasing
        while(!maxdq.empty() && a[maxdq.back()] <= a[r]) maxdq.pop_back();
        maxdq.push_back(r);

        //decreasing
        while(!mindq.empty() && a[mindq.back()] >= a[r]) mindq.pop_back();
        mindq.push_back(r);

        //shrink
        while(a[maxdq.front()] - a[mindq.front()] > k){
            l++;

            while(!maxdq.empty() && maxdq.front() < l) maxdq.pop_front();
            while(!mindq.empty() && mindq.front() < l) mindq.pop_front();
        }
        ans += r-l+1;

    }
    cout<<ans<<"\n";

  
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