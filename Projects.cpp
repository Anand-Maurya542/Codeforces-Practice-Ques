// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<tuple<int,int,int>> nums;
int n;


void solve()
{
    cin >> n ;

    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        nums.push_back({a,b,c});
    }

    sort(nums.begin(), nums.end(), [](auto& x, auto& y){
        return get<1> (x) < get<1> (y); 
    });

    vector<int> end;
    for(int i=0; i<n; i++){
        end.push_back(get<1>(nums[i]));
    }

    vector<int> dp(n);

    for(int i=0; i<n; i++){
        auto& [s,e,p] = nums[i];

        int take = p;

        int prev = upper_bound(end.begin(), end.end(), s-1) - end.begin()- 1;

        if(prev>=0) take += dp[prev];

        int skip = i>0 ? dp[i-1] : 0;

        dp[i] = max(take, skip);

    }
    cout<<dp[n-1]<<"\n";



    
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