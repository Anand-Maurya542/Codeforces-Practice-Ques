// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
bool valid(vector<int>& arr, int time, int k)
{
    int item = 0;
    for(int&x:arr){
        item += time/x;
        if(item >= k) return true;
    }
    return false;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int&x : arr) cin>>x;

    int lo= 1;
    int hi = *max_element(arr.begin(), arr.end())*k;
    int ans;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(valid(arr, mid, k)){
            ans = mid;
            hi = mid -1;

        }else lo = mid+1;
    }
    cout<<ans<<'\n';

    
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