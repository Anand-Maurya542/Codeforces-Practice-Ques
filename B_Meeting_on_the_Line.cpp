// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long double

using ll = long long;
const int MOD = 1e9 + 7;

bool valid(vector<int>& pos, vector<int>& cost, int T){
    int left = -1e18, right = 1e18;
    for(int i=0; i<pos.size(); i++){
        if(cost[i] > T) return false;
        left = max(left, pos[i] - (T - cost[i]));
        right = min(right, pos[i] + (T - cost[i]));
    }
    return left <= right;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n), cost(n);
    for (int &x : nums)
        cin >> x;
    for (int &x : cost)
        cin >> x;

    int lo=0, hi=2e14;

    while(hi - lo > 1e-6){
        int mid = lo + (hi-lo)/2;
        if(valid(nums, cost, mid)){
            hi=mid;
        }else lo=mid;
    }

    int T = hi;

    int left = -1e18, right = 1e18;
    for(int i=0; i<n; i++){

        left = max(left, nums[i] - (T - cost[i]));
        right = min(right, nums[i] + (T - cost[i]));
    }

    cout<<setprecision(10)<<(left + right)/2<<'\n';




    


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