// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
int n, k;

bool valid(int target, int k, vector<int>& a){
    
    for(int i=0; i<n-1; i++){
        int need = target;
        int cost = 0;
        for(int j=i; j<n; j++){
            if(j==n-1) {
                if(need > a[j]) cost += 1e9;
            }
            if(a[j] >= need) break;
            
            cost += need - a[j];
            need--;
            if(cost > k) break;
        }
        if(cost <= k) return true;
    }
    return false;

}

void solve()
{
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    
    int lo = *max_element(a.begin(), a.end());
    int hi = lo + n;
    int ans = lo;

    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(valid(mid, k, a)){
            ans = max(ans, mid);
            lo=mid+1;
        }else hi=mid-1;
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