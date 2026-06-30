// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

bool check(vector<int> a, vector<int> b, int ops){
    for(int i=0; i<ops; i++){
        a.pop_back();
        b.pop_back();
    }
    reverse(b.begin(), b.end());

    for(int i=0; i<a.size(); i++){
        if(a[i]>=b[i]) return false;
    }
    return true;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    a[0]=1;
    for(int i=1; i<n; i++) cin>>a[i];
    for(int &x:b) cin>>x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int lo=0, hi=n;

    while(lo<=hi){
        int mid = (hi+lo)/2;

        if(check(a,b,mid)){
            hi = mid-1;
        }else lo=mid+1;
    }
    cout<<lo<<'\n';


    
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