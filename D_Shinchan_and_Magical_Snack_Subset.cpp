// Author: Anand Maurya , MNNIT ALLAHABAD

#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
/* ---------- Output Helpers ---------- */
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n"; }
template <typename T>
void read(vector<T>& v) { for (auto& x : v) cin >> x; }

template <typename T>
void print(const vector<T>& v) { for (const auto& x : v) cout << x << ' '; cout << '\n'; }

#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
// vector<vector<int>>dp;
//dp.assign(n, vector<int>(m, -1));
//dp.assign(n, -1);
void solve()
{
    int n;
    cin >> n ;
    
    vector<int> nums(n);read(nums);
    if(n==1){
        cout<<1<<'\n';
        cout<<nums[0]<<'\n';
        return;
    }
    sort(all(nums));
    vector<int>dp(n,1),hash(n,-1);
    vector<int> ans;
    int maxi=INT_MIN,last=-1;


    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
                hash[i]=j;

            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            last=i;
        }
    }
    while(last!=-1){
        ans.push_back(nums[last]);
        last=hash[last];
    }
    reverse(all(ans));
    cout<<maxi<<'\n';
    print(ans);

    
    
    
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