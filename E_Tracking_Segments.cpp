// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<pair<int, int>> seg;

bool valid(int n,vector<int>& qry, int mid){
    vector<int> arr(n,0);
    int i=0;
    while(mid--){
        arr[qry[i]-1]=1;
        i++;
    }
    vector<int> pre(n+1);
    for(int i=0; i<n; i++){
        pre[i+1]=pre[i]+arr[i];
    }
    for(auto [l,r] : seg){
        if((pre[r+1] - pre[l]) > (r-l+1)/2) return true;
    }
    return false;
}

void solve()
{
    seg.clear();
    int n, k;
    cin >> n >> k;
    while(k--){
        int l,r;
        cin>>l>>r;
        seg.push_back({l-1, r-1});

    }
    int q; cin>>q;
    vector<int> qry(q);
    for(int& x : qry) cin>>x;

    int lo = 0, hi = q;
    int ans = -1;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(valid(n,qry,mid)){
            ans = mid;
            hi=mid-1;
        }else lo=mid+1;
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