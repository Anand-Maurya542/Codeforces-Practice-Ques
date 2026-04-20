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
vector<vector<int>>dp;
//dp.assign(n, -1);
// int f(vector<vector<int>>& nums,int i,int j){
    
// }
// vector<int> dp;
int f(vector<vector<int>> &nums,int i,int j){
    // if(i==0) return abs(prev-nums[i][k]);
    if(i==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int mini=INT_MAX;
    
    for(int k=0;k<nums[0].size();k++){
        int diff=abs(nums[i][j]-nums[i-1][k])+f(nums,i-1,k);
        mini=min(mini,diff)%MOD;
    }
    return dp[i][j]=mini;
}
void solve()
{
    int n, m;
    
    cin >> n >> m;
    vector<vector<int>> nums(n,vector<int>(m));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            
            nums[i][j]=s[j]-'a'+1;
            // cout<<nums[i][j]<<' ';
        }
        // cout<<'\n';
    }
    // dp.assign(n,-1);
    dp.assign(n, vector<int>(m, -1));
    
    int ans=f(nums,n-1,0);
    cout<<ans<<"\n";
    
    // int cnt=0;
    // int prev=nums[n-1][0];
    
    // for(int i=n-2;i>=0;i--){
    //     int mini=INT_MAX;
    //     int curr;
    //     for(int j=0;j<m;j++){
    //         // int m=*min_element(nums[i].begin(),nums[i].end());
    //         int ele=nums[i][j];
    //         int diff=abs(ele-prev);
    //         if(diff<=mini){
    //             mini=diff;curr=ele;
    //         }
    //     }
    //     cnt+=mini;
    //     prev=curr;
    // }
    // cout<<cnt<<'\n';
    
    
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