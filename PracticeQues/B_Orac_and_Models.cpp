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

// #define int long long

using ll = long long;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

void solve()
{
    int n;
    cin >> n ;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    vector<int>dp(n+1,1);


    for(int i=1;i<=n;i++){
        for(int d=1;d*d<=i;d++){
            if(i%d==0){
                
            int j1=d;
            int j2=i/d;

            if(j1<i && nums[j1]<nums[i]){
                dp[i]=max(dp[i],1+dp[j1]);

            }
            if(j1!=j2 && j2<i && nums[j2]<nums[i]){
                dp[i]=max(dp[i],1+dp[j2]);
            }}
        }
    }
    cout<<*max_element(all(dp))<<'\n';
    
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