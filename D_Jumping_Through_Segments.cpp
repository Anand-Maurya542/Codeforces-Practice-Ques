// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int n;
vector<pair<int,int>> segments;

bool valid(int k){
    int left = 0, right = 0;

    for(int i=0; i<n; i++){
        auto [start,end] = segments[i];
        left -= k;
        right += k;

        left = max(left, start);
        right = min(right, end);
        
        if(left > right) return false;
        
    }
    return true;
}
void solve()
{
    segments.clear();
    cin >> n ;
    int maxi = 0;
    for(int i=0; i<n; i++){
        int l,r; cin>>l>>r;
        maxi = max(maxi, r);
        segments.push_back({l,r});
    }

    int lo = 0, hi = maxi;


    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(valid(mid)){
            hi = mid-1;
        }else lo = mid+1;
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