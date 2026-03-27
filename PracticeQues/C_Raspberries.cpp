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
    int n, k;
    cin >> n >> k;
    int even=0;
    int ans=INT_MAX;
    vector<int> nums(n),need(n);read(nums);
    for(int i=0;i<n;i++){
        if(nums[i]%2==0) even++;
        if(nums[i]%k==0) ans=0;
        ans=min(ans,k-(nums[i]%k));
    }
    if(k==4){
        if(even>=2) ans=min(ans,0);
        else if(even==1) ans=min(ans,1);
        else ans=min(ans,2);
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